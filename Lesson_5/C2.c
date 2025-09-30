#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>

#define MAX_STACK_SIZE 255

double st[MAX_STACK_SIZE];
uint32_t pst = 0;

double pop()
{
    if (pst <= 0)
    {
        fprintf(stderr, "Error: stack underflow\n");
        exit(1);
    }
    return st[--pst];
}

void push(double v)
{
    if (pst >= MAX_STACK_SIZE)
    {
        fprintf(stderr, "Error: stack overflow\n");
        exit(1);
    }
    st[pst++] = v;
}

void operate(char c)
{
    double arg2 = pop(), arg1 = pop();
    switch (c)
    {
    case '+':
        push(arg1 + arg2);
        break;
    case '-':
        push(arg1 - arg2);
        break;
    case '*':
        push(arg1 * arg2);
        break;
    case '/':
        if (arg2 == 0)
        {
            fprintf(stderr, "Error: division by zero\n");
            exit(1);
        }
        push(arg1 / arg2);
        break;
    default:
        fprintf(stderr, "Unknown operator: %c\n", c);
        exit(1);
    }
}

int isNumber(const char *s)
{
    if (*s == '-' || *s == '+')
        s++; // знак
    int hasDigit = 0;
    int hasDot = 0;

    while (*s)
    {
        if (isdigit((unsigned char)*s))
        {
            hasDigit = 1;
        }
        else if (*s == '.' && !hasDot)
        {
            hasDot = 1;
        }
        else
        {
            return 0;
        }
        s++;
    }
    return hasDigit;
}

int main()
{
    char token[64];

    while (scanf("%63s", token) != EOF)
    {
        size_t len = strlen(token);

        // если последний символ — точка, обрезаем её
        int hasDotEnd = 0;
        if (len > 1 && token[len - 1] == '.')
        {
            token[len - 1] = '\0';
            hasDotEnd = 1;
        }

        if (strcmp(token, ".") == 0)
        {
            break; // конец выражения
        }
        else if (isNumber(token))
        {
            push(atof(token));
        }
        else if (strlen(token) == 1 && strchr("+-*/", token[0]))
        {
            operate(token[0]);
        }
        else if (strlen(token) > 0) // отсекаем пустую строку после "."
        {
            fprintf(stderr, "Error: invalid token '%s'\n", token);
            exit(1);
        }

        if (hasDotEnd)
            break; // если была точка в конце токена → конец выражения
    }

    if (pst != 1)
    {
        fprintf(stderr, "Error: invalid expression (stack size = %u)\n", pst);
        return 1;
    }

    printf("%.10g\n", pop());
    return 0;
}
