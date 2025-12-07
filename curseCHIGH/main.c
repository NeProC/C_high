#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>
#include <math.h>
#include <stdbool.h>
//#include <func.h>

typedef float(*function)(float);

int signF(float x, function f)
{
    return f(x) == 0 ? 0 : (f(x) < 0 ? -1 : +1);
}

float rootFindLineSearch(float xl, float xr, float eps,function f)
{
    float x, minx = xl, nextStep;
    nextStep = fabs(xr-xl)/(1/eps);
    unsigned int stepCount = 0;
    for (x=xl; x<xr; x += nextStep, stepCount++){
        if(fabs(f(x)) < fabs(f(minx))) minx = x;
    }
    printf("Find by %d steps\n", stepCount);
    return minx;
    
}

float rootFindDiv(float xl, float xr, float eps,function f)
{
    unsigned int stepCount = 0;
    float xMid;
    while (fabs(xr-xl) > eps)
    {
        stepCount++;
        xMid = (xl+xr)/2;
        if(signF(xl,f) != signF(xMid,f))
            xr = xMid;
        else
            xl = xMid;
    }
    printf("Find root for %d steps\n",stepCount); 
    return (xl+xr) /2;
}

float rootFindDiv2(float xl, float xr, float eps, function f) 
{
    unsigned int stepCount=0; //число шагов
    float xm;
    while(fabs(xr-xl)>eps) {
            //вещественный модуль разницы
        stepCount++;
        xm=(xl+xr)/2; // середина отрезка
        if(f(xr)==0) { // нашли решение на правой границе
            printf("Find root for %d steps\n",stepCount);
            return xr;
        }
        else if(f(xl)==0) { // нашли решение на левой границе
            printf("Find root for %d steps\n",stepCount);
            return xl;
        }
        if(signF(xl,f) != signF(xm,f))//если знак отличается
            xr=xm;
        else
            xl=xm;
    }
    printf("Find root for %d steps\n",stepCount); //статистика
    return (xl+xr)/2;
}

float rootFindChord(float xl, float xr, float eps, function f)
{
    unsigned int stepCount = 0;
    while (fabs(xr - xl) > eps)
    {
        stepCount++;
        xl = xr - (xr - xl) * f(xr) / (f(xr) - f(xl));
        xr = xl - (xl - xr) * f(xl) / (f(xl) - f(xr));
    }
    printf("Find root for %d steps\n",stepCount); //статистика
    return xr;
}

float rootFindTangent(float xn, float eps, function f, function df)
{
    float xl = xn - f(xn)/df(xn);
    float x0 = xn;
    unsigned int stepCount = 0;
    while (fabs(x0-xl) > eps)
    {
        stepCount++;
        x0 = xl;
        xl = xl - f(xl)/df(xl);
    }
    printf("Find root for %d steps\n",stepCount); //статистика
    return xl;
}

float rootFindCombine(float xl, float xr, float eps, function f, function df, function ddf)
{
    unsigned int stepCount = 0;
    while (fabs(xl-xr) > 2*eps) {
        stepCount++;
        if(f(xl)*ddf(xl) < 0){
            xl = xl - (f(xl) * (xl - xr) / (f(xl) - f(xr)));
        }
        else{
            xl = xl - f(xl)/df(xl);
        }
        if(f(xr)*ddf(xr) < 0){
            xr = xr - (f(xr)*(xr - xl) / (f(xr) - f(xl)));
        }
        else{
            xr = xr - f(xr)/df(xr);
        }
    }
    printf("Find root for %d steps\n",stepCount); //статистика
    return (xl+xr)/2;
}

float f(float x)
{
    return 8*x*x*x*x+32*x*x*x+40*x*x+16*x+1;
}

float df(float x)
{
    return 32*x*x*x+96*x*x+80*x+16;
}

float ddf(float x)
{
    return 96*x*x+192*x+80;
}

float testF(float x)
{
    return 2;
}

float calcIntegralSqu(float xl, float xr, size_t n, function f)
{
    float sum = 0;
    float h = (xr-xl)/n;
    for (size_t i = 0; i < n; i++)
    {
        sum += f(xl);
        xl += h;
    }
    return sum*h;
    
}

float calcIntegralTrap(float xl, float xr, size_t n, function f)
{
    float sum = 0.0;
    float h = (xr-xl)/n;
    for (float x = xl+h; x < xr-h; x+=h)
    {
        sum += 0.5*h*(f(x)+f(x+h));
    }
    return sum;
}

float calcIntSimpson(float xl, float xr, size_t n, function f)
{
    float sum = 0;
    float h = (xr-xl)/n;
    for (float x = xl+h; x < xr - h; x+=h)
    {
        sum += h/6.0*(f(x) + 4.0*f(0.5*(x+x+h)) + f(x+h));
    }
    return sum;
}

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
    printf("calc Int Squ %.5lf\n", calcIntSimpson(-1.3,-0.6,1000,f));


    return 0;
}
