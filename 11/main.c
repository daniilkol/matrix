#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include <math.h>
#include "read.h"
#include "solve.h"
double nevyazka (double* a,double* b,double* x,int n);
void matrcicanavector (double* a,double* b,double* c,int n);
double norma (double* a,int n);
double oshibka (double* a,double* b,double* x,int n);
void matricanavector (double* a,double* b,double* c,int n)
{
    int i,j,p;
    double sum=0;
    for (i=0;i<n;i++)
    {
       p=i*n;
       for(j=0;j<n;j++)
          sum=sum+a[p+j]*b[j];
       c[i]=sum;
       sum=0;
    }
}
double norma (double* a,int n)
{
    int i;
    double p,max=fabs(a[0]);
    for (i=1;i<n;i++)
    {
        p=fabs(a[i]);
        if (max>p)
            max=p;
    }
    return p;
}
double nevyazka (double* a,double* b,double* x,int n)
{
    int i;
    double p;
    double* t;
    t=(double*)malloc(n*sizeof(double));
    matricanavector(a,x,t,n);
    for(i=0;i<n;i++)
        t[i]=t[i]-b[i];
    p=norma(t,n);
    free(t);
    return p;

}
double oshibka (double* a,double* b,double* x,int n)
{
    int i,j,res;
    double* t,sum=0,p;
    t=(double*)malloc(n*sizeof(double));
    for(i=0;i<n;i++)
    {
        if (i%2==0)
         t[i]=1.0;
        else t[i]=0;
        for(j=0;j<n;j=j+2)
            sum+=a[i*n+j];
        b[i]=sum;
        sum=0;
    }
    res=jordanpostroke(a,b,x,n);
    for(i=0;i<n;i++)
        t[i]=t[i]-x[i];
    p=norma(t,n);
    free(t);
    return p;

}
int main()
{
    const char *name1="a.txt";
    const char *name2="b.txt";
    int n,key1,key2,res;
    double* a;
    double* b;
    double* x;
    double t,nev,osh;
    printf("Input n and key1 and key2:\n");
    if(scanf("%d%d%d",&n,&key1,&key2)!=3)
    {
        printf("Cannot read!\n");
        return 1;
    }
    if(!(a=(double*)malloc(n*n*sizeof(double))))
    {
        printf("Not enough memory");
        return 2;
    }
    if(!(b=(double*)malloc(n*sizeof(double))))
    {
        printf("Not enough memory");
        return 2;
    }
    if(!(x=(double*)malloc(n*sizeof(double))))
    {
        printf("Not enough memory");
        return 2;
    }
  if (key1==0)
       {
           int ret;
         ret=read_matrix(name1,a,n,n);
            if(ret<0)
            {
                switch (ret)
                {
                    case -1:
                        printf("Cannot open%s\n",name1);
                        break;
                    case -2:
                        printf("Cannot read%s\n",name1);
                        break;
                    default:
                        printf("Unknown error%s\n",name1);
                        break;
                }
                free(a);
                return 3;
            }

       }
       else init_matrix(a,n,n);
         if (key2==0)
       {
           int ret1;
           ret1=read_matrix(name2,b,n,1);
            if(ret1<0)
            {
                switch (ret1)
                {
                    case -1:
                        printf("Cannot open%s\n",name2);
                        break;
                    case -2:
                        printf("Cannot read%s\n",name2);
                        break;
                    default:
                        printf("Unknown error%s\n",name2);
                        break;
                }
                free(b);
                return 3;
            }

       }
       else init_matrix(b,n,1);
       printf("MATRIX A:\n");
    print_matrix(a,n,n);
    printf("VECTOR B:\n");
    print_vector(b,n);

    t=clock();
    res=jordanpostroke(a,b,x,n);
    t=(clock()-t)/CLOCKS_PER_SEC;
    printf("VECTOR X:\n");
        print_vector(x,n);
     printf("MATRIX A:\n");
    print_matrix(a,n,n);
    if (key1==0)
       {
           int ret;
         ret=read_matrix(name1,a,n,n);
            if(ret<0)
            {
                switch (ret)
                {
                    case -1:
                        printf("Cannot open%s\n",name1);
                        break;
                    case -2:
                        printf("Cannot read%s\n",name1);
                        break;
                    default:
                        printf("Unknown error%s\n",name1);
                        break;
                }
                free(a);
                return 3;
            }

       }
       else init_matrix(a,n,n);
      if (key2==0)
       {
           int ret1;
           ret1=read_matrix(name2,b,n,1);
            if(ret1<0)
            {
                switch (ret1)
                {
                    case -1:
                        printf("Cannot open%s\n",name2);
                        break;
                    case -2:
                        printf("Cannot read%s\n",name2);
                        break;
                    default:
                        printf("Unknown error%s\n",name2);
                        break;
                }
                free(b);
                return 3;
            }

       }
       else init_matrix(b,n,1);
    printf("Elapse time=%.2f\n",t);
    nev=nevyazka(a,b,x,n);
    printf("Nevyazka=%e\n",nev);
    osh=oshibka (a,b,x,n);
    printf("Oshibka=%e\n",osh);
    free(a);
    free(b);
    free(x);
    return 0;
}
