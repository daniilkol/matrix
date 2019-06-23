#include <stdio.h>
#include <stdlib.h>
void solve(double* a,int n,int m,int i,int j)
{
    int k;
    double p;
    (void)m;
    double* t=a+i*n;
    double* h=a+j*n;
    for (k=0;k<n;k++)
    {
      p=t[k];
      t[k]=h[k];
      h[k]=p;
    }
}
