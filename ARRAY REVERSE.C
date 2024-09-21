#include<stdio.h>
int main()
{
int i,j,a[100],b[100],n;
printf("ENTER THE SIZE OF ARRAY=\n");
scanf("%d",&n);
printf("ENTER THE ELEMENTS OF ARRAY=\n");
for(i=0;i<n;i++){
scanf("%d",&a[i]);}
printf("AFTER REVERSING ARRAY\n");
for(i=n-1,j=0;i<=n,j<n;i--,j++)
{
b[j]=a[i];
printf("%d\n",b[j]);
}
} 
