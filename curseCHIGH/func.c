

typedef float(*function)(float);

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



float f(float x)
{
    return 8*x*x*x*x+32*x*x*x+40*x*x+16*x+1;
}