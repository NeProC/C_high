#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct list
{
    void *address;
    size_t size;
    char comment[64];
    struct list *next;
} list;

size_t totalMemoryUsage(list *head)
{
    if (head == NULL)
    {
        return 0;
    }
    size_t allMem = 0;
    do
    {
        allMem += head->size;
        head = head->next;
    } while (head != NULL);
    return allMem;
}