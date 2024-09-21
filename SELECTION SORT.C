#include<stdio.h>
void readarray(int a[],int n);
void readarray(int a[],int n)
{
int i;
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
}
void printarray(int a[],int n);
void printarray(int a[],int n)
{
int i;
for(i=0;i<n;i++)
{
printf("%d\n",a[i]);
}
}
void swap(int *x,int *y);
void swap(int *x,int *y)
{
int t;
 t=*x;
*x=*y;
*y=t;
}
void sort(int a[],int n);
void sort(int a[],int n)
{
int i,j,min;
for(i=0;i<n-1;i++)
{
min=i;
for(j=i+1;j<n;j++)
{
if(a[j]<a[min])
min=j;
}
if(min!=i)
swap(&a[min],&a[i]);
}
}

int main()
{
int a[100],n;
scanf("%d",&n);
readarray(a,n);
printf("before sorting=\n");
printarray(a,n);
printf("after sorting=\n");
sort(a,n);
printarray(a,n);
}
