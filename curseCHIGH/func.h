#ifndef FUNC_H
#define FUNC_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>
#include <math.h>
#include <stdbool.h>
#include <unistd.h>

#define EPS 0.001f

extern float p[5][2];

typedef float(*function)(float);        //Тип данных указателя на функцию

int signF(float x, function f);         //Определение знака функции
// Поиск нулей функция
float rootFindLineSearch(float xl, float xr, float eps, function f);
float rootFindDiv(float xl, float xr, float eps, function f);
float rootFindDiv2(float xl, float xr, float eps, function f);
float rootFindChord(float xl, float xr, float eps, function f);
float rootFindTangent(float xn, float eps, function f, function df);
float rootFindCombine(float xl, float xr, float eps, function f, function df, function ddf);

//Заданные функциии и их производные
float f(float x);
float df(float x);
float ddf(float x);

float f1(float x);
float df1(float x);
float ddf1(float x);

float f2(float x);
float df2(float x);
float ddf2(float x);

float f3(float x);
float df3(float x);
float ddf3(float x);

//Разность функций для поиска точек пересечений и их производные
float F1(float x);
float F2(float x);
float F3(float x);

float dF1(float x);
float dF2(float x);
float dF3(float x);

float ddF1(float x);
float ddF2(float x);
float ddF3(float x);

//Интегрирование, площадь под кривой
float calcIntegralSqu(float xl, float xr, size_t n, function f);
float calcIntegralTrap(float xl, float xr, size_t n, function f);
float calcIntegralSimpson(float xl, float xr, size_t n, function f);




#endif


