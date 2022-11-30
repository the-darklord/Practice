#include <stdio.h>

int SecondLargest(int a[100],int n)
{
    int i,largest, second;

   if(a[0] > a[1])
   {
      largest = a[0];
      second  = a[1];
   }
   else
   {
      largest = a[1];
      second  = a[0];
   }

   for(i=2;i<n;i++)
   {
      if( largest < a[i] )
      {
         second = largest;
         largest = a[i];
      }
      else if( second < a[i] )
      {
         second =  a[i];
      }
   }

   printf("Second Largest Element is %d \n",second);   
   return 0;
}

int main()
{
   int i,n,a[100];

   printf("Enter size of array : \t");
   scanf("%d",&n);

   for(i=0;i<n;i++)
   {
    printf("Enter Number %d : \t",i+1);
    scanf("%d",&a[i]);
    printf("\n");
   }
   SecondLargest(a,n);

   return 0;   
}