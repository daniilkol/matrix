#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int solve(double* a,int n)
{
    int i,j;
    for (i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
            if(!fabs(a[i*n+j]-a[j*n+i])<1e-15)
                return 0;
    }
    return 1;
}
