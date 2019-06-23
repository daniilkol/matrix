#include <stdio.h>
#include <stdlib.h>
double solve(double*x,double* y,int n,double x0)
{
    int i,j,k=1;
    double s=0,p=1;
    for(j=0;j<n;j++)
     {
        for (i=n-1;i>j;i--)
        {
            y[i]=(y[i]-y[i-1])/(x[i]-x[i-k]);

        }
        k++;
     }
    for(i=0;i<n;i++)
    {
           for(j=0;j<i;j++)
           p*=x0-x[j];

      s+=y[i]*p;
      p=1;
    }
    return s;
}
