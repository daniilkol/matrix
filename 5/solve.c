#include <stdio.h>
#include <stdlib.h>
void solve(double* a,int n)
{
    int i,j;
    double p;
    for (i=0;i<n;i++)
    {
      a[i*n+i]=0;
      for(j=i;j<n;j++)
      {
          p=a[i*n+j];
          a[i*n+j]=(p-a[j*n+i])/2;
          a[j*n+i]=(a[j*n+i]-p)/2;

      }
    }
}
