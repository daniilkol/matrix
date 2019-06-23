#include <stdio.h>
#include <stdlib.h>
void solve(double* a,int n,int m,int i,int j,double b)
{
    int k;
    double* p=a+j*n;
    double* t=a+i*n,h;
    (void)m;
    for (k=0;k<n;k++)
    {
       h=t[k];
       p[k]=b*h+p[k];
    }
}
