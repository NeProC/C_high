#include "func.h"

int main(int argc, char *argv[])
{/**/
    const char* optString = "abch";
    int opt;
    float functionsS = 0.0f, functionsS1 = 0.0f, functionsS2 = 0.0f, functionsS3 = 0.0f, pf1f3, pf1f2, pf2f3;

    while ((opt = getopt(argc, argv, optString)) != -1)
    {
        switch (opt)
        {
            case 'a':
                printf("\n");
                printf("Вычисление всех точек пересечения функций методом хорд\n");
                printf("Пересечение 1й и 3й функций в точке %.4f\n",rootFindChord(p[0][0], p[0][1], EPS, F1));
                printf("Пересечение 1й и 3й функций в точке %.4f\n",rootFindChord(p[1][0], p[1][1], EPS, F1));
                printf("Пересечение 1й и 2й функций в точке %.4f\n",rootFindChord(p[2][0], p[2][1], EPS, F3));
                printf("Пересечение 3й и 2й функций в точке %.4f\n",rootFindChord(p[3][0], p[3][1], EPS, F2));
                printf("Пересечение 3й и 2й функций в точке %.4f\n",rootFindChord(p[4][0], p[4][1], EPS, F2));
                break;
            case 'b':
                printf("\n");
                printf("Вычисление всех точек пересечения функций методом касательных\n");
                printf("1 f1(x)=0.6 * x + 3\n");
                printf("2 f2(x)=(x-2)^3-1\n");
                printf("3 f3(x)=3/x\n");
                printf("Пересечение 1й и 3й функций в точке %.4f\n",rootFindTangent(p[0][0], EPS, F1,dF1));
                printf("Пересечение 1й и 3й функций в точке %.4f\n",rootFindTangent(p[1][0], EPS, F1,dF1));
                printf("Пересечение 1й и 2й функций в точке %.4f\n",rootFindTangent(p[2][0], EPS, F3,dF3));
                printf("Пересечение 3й и 2й функций в точке %.4f\n",rootFindTangent(p[3][0], EPS, F2,dF2));
                printf("Пересечение 3й и 2й функций в точке %.4f\n",rootFindTangent(p[4][0], EPS, F2,dF2));
                break;
            case 'c':
                printf("\n");
                printf("Вычисление всех точек пересечения функций комбинированным методом\n");
                printf("1 f1(x)=0.6 * x + 3\n");
                printf("2 f2(x)=(x-2)^3-1\n");
                printf("3 f3(x)=3/x\n");
                printf("Пересечение 1й и 3й функций в точке %.4f\n",rootFindCombine(p[0][0], p[0][1], EPS, F1, dF1, ddF1,1));
                printf("Пересечение 1й и 3й функций в точке %.4f\n",rootFindCombine(p[1][0], p[1][1], EPS, F1, dF1, ddF1,1));
                printf("Пересечение 1й и 2й функций в точке %.4f\n",rootFindCombine(p[2][0], p[2][1], EPS, F3, dF3, ddF3,1));
                printf("Пересечение 3й и 2й функций в точке %.4f\n",rootFindCombine(p[3][0], p[3][1], EPS, F2, dF2, ddF2,1));
                printf("Пересечение 3й и 2й функций в точке %.4f\n",rootFindCombine(p[4][0], p[4][1], EPS, F2, dF2, ddF2,1));
                break;
            case 'h':
                printf("Ключи программы:\n");
                printf("-a: Вычисление всех точек пересечения функций методом хорд\n");
                printf("-b: Вычисление всех точек пересечения функций методом касательных\n");
                printf("-с: Вычисление всех точек пересечения функций комбинированным методом\n");
                printf("-h: Помощь\n");
                printf("Без ключей программа расчитывает площадь образующую заданными функция\n");
                break;
            default:
                printf("Неверная опция: %c\n", optopt);
                printf("Вся информация с ПК будет стерта через;\n");
                for(int i = 5; i >= 0; i--){
                    printf("%d \n", i);
                    sleep(1);
                }
                printf("\n");
                return 0;
        }

    }
    printf("\n");
    printf("Вычисление площади образующих заданными функциями:\n");
    printf("1 f1(x)=0.6 * x + 3\n");
    printf("2 f2(x)=(x-2)^3-1\n");
    printf("3 f3(x)=3/x\n");
    pf1f3 =rootFindCombine(p[0][0], p[0][1], EPS, F1, dF1, ddF1,0);
    pf2f3 =rootFindCombine(p[3][0], p[3][1], EPS, F2, dF2, ddF2,0);
    pf1f2 =rootFindCombine(p[2][0], p[2][1], EPS, F3, dF3, ddF3,0);
    printf("Точки пересечения функций по оси Х \n");
    printf("point f1(x)f3(x)=%.3f\tpoint f2(x)f3(x)=%.3f\tpoint f1(x)f2(x)=%.3f\n", pf1f3,pf2f3,pf1f2);
    functionsS1 = calcIntegralTrap(pf1f3, pf1f2, INTEGRAL_STEPS, f1);
    printf("Площадь под функцией f1(x)=0.6 * x + 3 - %.4f\n", functionsS1);
    functionsS2 = calcIntegralTrap(pf2f3, pf1f2, INTEGRAL_STEPS, f2);
    printf("Площадь под функцией f2(x)=(x-2)^3-1 - %.4f\n", functionsS2);
    functionsS3 = calcIntegralTrap(pf1f3, pf2f3, INTEGRAL_STEPS, f3);
    printf("Площадь под функцией f3(x)=3/x - %.4f\n", functionsS3);
    functionsS = functionsS1 - (functionsS2 + functionsS3);
    printf("Площадь образуемвя функциями S(f1) - S(f2) - Sf(3) = %.4f\n", functionsS);

    

    return 0;
}
