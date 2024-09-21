#include<stdio.h>
void read(int a[],int n);
void read(int a[],int n) {
    int i;
    for(i=0;i<n;i++)
     scanf("%d",&a[i]);
}
   void print(int a[],int n);
   void print(int a[],int n) {
     int i; 
      for(i=0;i<n;i++)
        printf("%d\n",a[i]);
 }
    void sort(int a[],int n);
    void sort(int a[],int n) {
        int i,j,t;
        for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
    {
         if(a[j]>a[j+1])
    {
          t=a[j];
          a[j]=a[j+1];
          a[j+1]=t;

    }
    }
    }
    }
      int search(int a[],int n,int key);
      int search(int a[],int n,int key)
    {
        int start,end,mid,pos=-1;
        printf("enter the value of key:\n");
         scanf("%d",&key);
         start=0;
         end=n-1;
         
         while(start<=end)
        {
            mid=(start+end)/2;
             if(a[mid]==key)
          {
             pos=mid+1;
             break;
          }
             else if(key<a[mid])
          {
              end=mid-1;
          }
            else
          {
             start=mid+1;
          }
             
        }
          if(pos>=0)
         printf("key is  found at %d",pos);
         else 
         printf("key is not found ");
         return 0;

    }
       int main()
    {
        int n,a[50],p,key;
        printf("enter the size of an array:\n");
        scanf("%d",&n);
        read(a,n);
        print(a,n);
        sort(a,n);
        print(a,n);
        p=search(a,n,key);
         
    }
      
