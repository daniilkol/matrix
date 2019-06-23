#include <stdio.h>
#include <stdlib.h>
void solve(double* a,int n)
{
    int i,j;
    double p;
    for (i=0;i<n;i++)
    {
      for(j=i;j<n;j++)
      {
          p=a[i*n+j];
          a[i*n+j]=a[j*n+i];
          a[j*n+i]=p;
      }
    }
}
