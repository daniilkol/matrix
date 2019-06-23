#include <stdio.h>
#include <stdlib.h>
double solve(double*x,double* y,int n,double x0)
{
    int i,j;
    double s=0,p=1;
    for(i=0;i<n;i++)
    {
            for(j=0;j<n;j++)
            {
                if(j!=i)
                {
                    p*=(x0-x[j])/(x[i]-x[j]);
                }
            }
            s+=y[i]*p;
            p=1;

    }
    return s;
}
