#include "func.h"

int main(int argc, char const *argv[])
{
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


    return 0;
}
