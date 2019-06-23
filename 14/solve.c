#include <stdio.h>
#include <stdlib.h>
double solve(double*x,double* y,int n,double x0)
{
    int i,j,k=1;

    for(j=0;j<n;j++)
     {
        for (i=n-1;i>j;i--)
        {
            y[i]=(y[i]*(x0-x[i-k])-y[i-1]*(x0-x[i]))/(x[i]-x[i-k]);

        }
        k++;
     }

    return y[n-1];
}
