#include "func.h"

int main(int argc, char *argv[])
{/*
    // float points[4][2] = {{-2.0,-1.6},{-1.5,-1.0},{-0.7,-0.5},{-0.1,0}};

    // for (int i = 0; i < 4; i++) {
    //     printf("------------------Root%d----------------------\n",i);
    //     printf("Line Search root%d = %.4f\n",i,rootFindLineSearch(points[i][0],points[i][1],0.001,f));
    //     printf("Find Div Search root%d = %.4f\n",i,rootFindDiv(points[i][0],points[i][1],0.001,f));
    //     printf("Find Div Search root%d = %.4f\n",i,rootFindDiv2(points[i][0],points[i][1],0.001,f));
    //     printf("Find Div Search root%d = %.4f\n",i,rootFindChord(points[i][0],points[i][1],0.001,f));
    //     printf("Find Div Search root%d = %.4f\n",i,rootFindTangent(points[i][0],0.001,f,df));
    //     printf("Find Div Search root%d = %.4f\n",i,rootFindCombine(points[i][0],points[i][1],0.001,f,df,ddf));
    // }
    
    printf("calc Int Squ %.5lf\n", calcIntegralSqu(-1.3,-0.6,1000,f));
    printf("calc Int Squ %.5lf\n", calcIntegralTrap(-1.3,-0.6,1000,f));
    printf("calc Int Squ %.5lf\n", calcIntegralSimpson(-1.3,-0.6,1000,f));
*/

    const char* optString = "abcdh";
    int opt;
    float functionsS = 0.0f, pf1f3, pf1f2, pf2f3;

    printf("Вычисление площади образующих заданными функциями\n");
    pf1f3 =rootFindCombine(p[0][0], p[0][1], EPS, F1, dF1, ddF1);
    pf2f3 =rootFindCombine(p[3][0], p[3][1], EPS, F2, dF2, ddF2);
    pf1f2 =rootFindCombine(p[2][0], p[2][1], EPS, F3, dF3, ddF3);
    printf("pf1f3 = %.3f\tpf2f3=%.3f\tpf1f2=%.3f\n", pf1f3,pf2f3,pf1f2);

    

    while ((opt = getopt(argc, argv, optString)) != -1)
    {
        switch (opt)
        {
            case 'a':
                printf("Вычисление точек пересечения функций методом хорд\n");
                printf("1 f(x)=0.6 * x + 3\n");
                printf("2 f(x)=(x-2)^3-1\n");
                printf("3 f(x)=3/x\n");
                printf("Пересечение 1й и 3й функций в точке %.4f\n",rootFindChord(p[0][0], p[0][1], EPS, F1));
                printf("Пересечение 1й и 3й функций в точке %.4f\n",rootFindChord(p[1][0], p[1][1], EPS, F1));
                printf("Пересечение 1й и 2й функций в точке %.4f\n",rootFindChord(p[2][0], p[2][1], EPS, F3));
                printf("Пересечение 3й и 2й функций в точке %.4f\n",rootFindChord(p[3][0], p[3][1], EPS, F2));
                printf("Пересечение 3й и 2й функций в точке %.4f\n",rootFindChord(p[4][0], p[4][1], EPS, F2));
                break;
            case 'b':
                printf("Вычисление точек пересечения функций методом касательных\n");
                printf("1 f(x)=0.6 * x + 3\n");
                printf("2 f(x)=(x-2)^3-1\n");
                printf("3 f(x)=3/x\n");
                printf("Пересечение 1й и 3й функций в точке %.4f\n",rootFindTangent(p[0][0], EPS, F1,dF1));
                printf("Пересечение 1й и 3й функций в точке %.4f\n",rootFindTangent(p[1][0], EPS, F1,dF1));
                printf("Пересечение 1й и 2й функций в точке %.4f\n",rootFindTangent(p[2][0], EPS, F3,dF3));
                printf("Пересечение 3й и 2й функций в точке %.4f\n",rootFindTangent(p[3][0], EPS, F2,dF2));
                printf("Пересечение 3й и 2й функций в точке %.4f\n",rootFindTangent(p[4][0], EPS, F2,dF2));
                break;
            case 'c':
                printf("Вычисление точек пересечения функций комбинированным методом\n");
                printf("1 f(x)=0.6 * x + 3\n");
                printf("2 f(x)=(x-2)^3-1\n");
                printf("3 f(x)=3/x\n");
                printf("Пересечение 1й и 3й функций в точке %.4f\n",rootFindCombine(p[0][0], p[0][1], EPS, F1, dF1, ddF1));
                printf("Пересечение 1й и 3й функций в точке %.4f\n",rootFindCombine(p[1][0], p[1][1], EPS, F1, dF1, ddF1));
                printf("Пересечение 1й и 2й функций в точке %.4f\n",rootFindCombine(p[2][0], p[2][1], EPS, F3, dF3, ddF3));
                printf("Пересечение 3й и 2й функций в точке %.4f\n",rootFindCombine(p[3][0], p[3][1], EPS, F2, dF2, ddF2));
                printf("Пересечение 3й и 2й функций в точке %.4f\n",rootFindCombine(p[4][0], p[4][1], EPS, F2, dF2, ddF2));
                break;
            case 'd':
                printf("Вы выбрали опцию b\n");
                break;
            case 'h':
                printf("Помощь по командам:\n");
                printf("-a: Опция a\n");
                printf("-b: Опция b\n");
                printf("-h: Помощь\n");
                break;
            default:
                printf("Неверная опция: %c\n", opt);
                printf("Вся информация с ПК будет стерта через;\n");
                break;
        }

    }


    

    return 0;
}
