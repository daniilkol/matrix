#include <stdio.h>
#include <stdlib.h>
void solve(double* a,double* b,double* c,int n,int m,int k)
{
    int i,j,t,p;
    double sum=0;
    for (i=0;i<m;i++)
    {
       p=i*n;
       for(j=0;j<k;j++)
          {
              for(t=0;t<n;t++)
                sum=sum+a[p+t]*b[t*k+j];
              c[i*k+j]=sum;
              sum=0;
          }
    }
}
