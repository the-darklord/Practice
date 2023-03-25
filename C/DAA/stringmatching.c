/*
ALGORITHM StringMatching(T[0..n-1],P[0..m-1])
    for i ← 0 to n-m 
        j ← 0
        while j<m and P[j]=T[i+j]
            j ← j+1
        if j=m
            return i
    return -1
*/

#include <stdio.h>
#include <string.h>

int StringMatching(char *str,char *ptr)
{
    int n=strlen(str);
    int m=strlen(ptr);
    int j;
    for(int i=0;i<n-m+1;i++)
    {
        j=0;
        while(j<m&&ptr[j]==str[i+j])
        {
            j++;
        }
        if(j==m)
        {
            return i;
        }
    }
    return -1;
}

void main()
{
    char string[100],pattern[100];
    printf("Enter String : \n");
    scanf("%s",string);
    printf("Enter Pattern to Match : \n");
    scanf("%s",pattern);
    int flag=StringMatching(string,pattern);
    if(flag==-1)
    {
        printf("\nPattern Not Found\n\n");
    }
    else
    {
        printf("\nPattern Found at Position %d\n\n",flag+1);
    }
}