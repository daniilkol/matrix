#include <stdio.h>
#include <stdlib.h>
void solve(double* a,int n,int m,int i,int j)
{
    int k;
    double p;
    (void)n;
    for (k=0;k<m;k++)
    {
      p=a[k*n+i];
      a[k*n+i]=a[k*n+j];
      a[k*n+j]=p;
    }
}
