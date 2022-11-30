#include <stdio.h>
int main() {
	int n,rev=0,rem,N;
    printf("Enter an integer: ");
    scanf("%d", &n);
    N=n;

    while (n != 0) {
        rem=n%10;
        rev=rev*10+rem;
        n/=10;
    }

    if (N==rev)
        printf("%d is a palindrome.",N);
    else
        printf("%d is not a palindrome.",N);

    return 0;
}