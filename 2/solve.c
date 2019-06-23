#include <stdio.h>
#include <stdlib.h>
double solve(double* a,int n)
{
    int i;
    double res=0;
    for (i=0;i<n;i++)
    {
       res+=a[i*n+i];
    }
    return res;
}
