#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "solve.h"
void smenastolbcov(double* a,int n,int i,int j)
{
    int k,r;
    double p;
    for (k=0;k<n;k++)
    {
      r=k*n;
      p=a[r+i];
      a[r+i]=a[r+j];
      a[r+j]=p;
    }
}
void strokanastroky (double* a,int n,int i,int j,double b)
{
    int k;
    double* p=a+j*n;
    double* t=a+i*n,h;
    for (k=0;k<n;k++)
    {
       h=t[k];
       p[k]=b*h+p[k];
    }
}
int maxvstroke(double* a,int n,int k)
{
    int i,r=k,p=k*n;
    double max=fabs(a[p+k]),t;
    for (i=k+1;i<n;i++)
    {
        t=fabs(a[p+i]);
        if (t>max)
        {
            max=t;
            r=i;
        }
    }
    if (max<1e-16)
        return -1;
    return r;
}
void obnylenienijeelementa(double* a,double* b,int n,int k)
{
    int i,t=k*n;
    double p=a[t+k];
    a[t+k]=1;
    for(i=k+1;i<n;i++)
       a[t+i]=a[t+i]/p;
    b[k]=b[k]/p;
    for(i=k+1;i<n;i++)
    {
        b[i]=b[k]*(-a[i*n+k])+b[i];
        strokanastroky(a,n,k,i,-a[i*n+k]);

    }


}
void obnylenievisheelementa(double* a,double* b,int n,int k)
{
    int i;
    for(i=k;i>0;i--)
    {
        b[i-1]=b[k]*(-a[(i-1)*n+k])+b[i-1];
        strokanastroky(a,n,k,i-1,-a[(i-1)*n+k]);

    }
}
#define MAX_N 8
void print_vector1(double* a,int n)
{
    int i;
    for(i=0;i<n;i++)
      {
          printf("  %.2f",a[i]);
          printf("\n");
      }
}
void print_vector2(int* a,int n)
{
    int i;
    for(i=0;i<n;i++)
      {
          printf("  %d",a[i]);
          printf("\n");
      }
}
void print_matrix1(double* a,int n,int m)
{
    int i,j;
    int n_max=(n>MAX_N?MAX_N:n);
    int m_max=(m>MAX_N?MAX_N:m);
    for(i=0;i<m_max;i++)
    {
        for(j=0;j<n_max;j++)
            printf("  %.2f",a[i*n+j]);
        printf("\n");
    }
}

int jordanpostroke (double* a,double* b,double* x,int n)
{
    int i,j,k,num,p;
    double p1;
    int* per;
    per=(int*)malloc(n*sizeof(int));
    for (i=0;i<n;i++)
        per[i]=i+1;

    for (i=0;i<n;i++)
    {
        num=maxvstroke(a,n,i);
        if (num<0)
           {

            return -1;}

         else
         {
                smenastolbcov(a,n,i,num);
                p=per[i];
                per[i]=per[num];
                per[num]=p;
        }

        obnylenienijeelementa(a,b,n,i);




        if (i>0)
          obnylenievisheelementa(a,b,n,i);
    }

    for (i=0;i<n;i++)
    {
        p=per[i];
        x[p-1]=b[i];
    }





    free(per);
    return 0;

}





