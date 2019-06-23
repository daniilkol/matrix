#include <stdio.h>
#include <stdlib.h>
void solve(double* a,double* b,double* c,int n,int m)
{
    int i,j,p;
    double sum=0;
    for (i=0;i<m;i++)
    {
       p=i*n;
       for(j=0;j<n;j++)
          sum=sum+a[p+j]*b[j];
       c[i]=sum;
       sum=0;
    }
}
