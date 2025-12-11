#ifndef FUNC_H
#define FUNC_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>
#include <math.h>
#include <stdbool.h>

typedef float(*function)(float);        //Тип данных указателя на функцию

int signF(float x, function f);         //Определение знака функции
// Поиск нулей функция
float rootFindLineSearch(float xl, float xr, float eps, function f);
float rootFindDiv(float xl, float xr, float eps, function f);
float rootFindDiv2(float xl, float xr, float eps, function f);
float rootFindChord(float xl, float xr, float eps, function f);
float rootFindTangent(float xn, float eps, function f, function df);
float rootFindCombine(float xl, float xr, float eps, function f, function df, function ddf);

//Заданная функция
float f(float x);
float df(float x);
float ddf(float x);

//Интегрирование, площадь под кривой
float calcIntegralSqu(float xl, float xr, size_t n, function f);
float calcIntegralTrap(float xl, float xr, size_t n, function f);
float calcIntegralSimpson(float xl, float xr, size_t n, function f);




#endif


