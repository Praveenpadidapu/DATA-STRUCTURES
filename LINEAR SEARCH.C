#include<stdio.h>
int main()
 {
     int a[100];
      int i,key,pos=-1,n;
      printf("ENTER THE VALUE OF n=\n");
      scanf("%d",&n);
      printf("ENTER THE ELEMENTS=\n");
      for(i=0;i<n;i++)
      {
      scanf("%d",&a[i]);
      }
      printf("ENTER THE KEY TO FIND=\n");
      scanf("%d",&key);
        for(i=0;i<n;i++)
             {
               if(key==a[i])
                   
                   {
                     pos=i;
                     break;
                    
                   }
             }
        if(pos>=0)
            printf("key is found at %d",pos);        
         else
            printf("key is not found ");
  }
