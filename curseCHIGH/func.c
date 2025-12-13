#include "func.h"

float p[5][2] = {{0.5f,1.0f},{-6.0f,-5.0f},{3.5f, 4.0f},{3.0f,3.5f},{-0.4f,-0.2f}};


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
    printf("Для поиска произведено %d итераций\n",stepCount); //статистика
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
    printf("Для поиска произведено %d итераций\n",stepCount); //статистика
    return xl;
}

float rootFindCombine(float xl, float xr, float eps, function f, function df, function ddf, int flag)
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
    if(flag)
        printf("Для поиска произведено %d итераций\n",stepCount); //статистика
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

float f1(float x)
{
    return 0.6 * x + 3;
}

float df1(float x)
{
    x = 1.0;
    return 0.6*x;
}

float ddf1(float x)
{
    x = 0.0;
    return 0.6*x;
}

float f2(float x)
{
    return (x-2)*(x-2)*(x-2)-1;
}

float df2(float x)
{
    return 3*(x-2)*(x-2);
}

float ddf2(float x)
{
    return 6*x-12;
}

float f3(float x)
{
    return 3/x;
}

float df3(float x)
{
    return -3*pow(x,-2);
}

float ddf3(float x)
{
    return 6*pow(x,-3);
}

float F1(float x)
{
    return f3(x)-f1(x);
}

float dF1(float x)
{
    return df3(x) - df1(x);
}

float ddF1(float x)
{
    return ddf3(x) - ddf1(x);
}

float F2(float x)
{
    return f3(x)-f2(x);
}

float dF2(float x)
{
    return df3(x) - df2(x);
}

float ddF2(float x)
{
    return ddf3(x) - ddf2(x);
}

float F3(float x)
{
    return f2(x)- f1(x);
}

float dF3(float x)
{
    return df2(x) - df1(x);
}

float ddF3(float x)
{
    return ddf2(x) - ddf1(x);
}


float testF(float x)
{
    return 2*x;
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

float calcIntegralSimpson(float xl, float xr, size_t n, function f)
{
    float sum = 0;
    float h = (xr-xl)/n;
    for (float x = xl+h; x < xr - h; x+=h)
    {
        sum += h/6.0*(f(x) + 4.0*f(0.5*(x+x+h)) + f(x+h));
    }
    return sum;
}