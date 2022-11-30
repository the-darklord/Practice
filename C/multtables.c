#include <stdio.h>

int main()
{
    int i,j,n,k;

    printf("Enter n,k : \t");
    scanf("%d %d",&n,&k);

    printf("Multiplication table\n\n");

    for(i=1; i<=n; i++){
        for(j=1; j<=k; j++){
                printf("%d\t", i*j);


    }
    printf("\n");
    }
    
    return 0;
}