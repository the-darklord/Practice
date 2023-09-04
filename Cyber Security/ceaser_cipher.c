#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* encryption(const char* str,int key)
{
    char* enc=(char*)malloc(strlen(str)*sizeof(char));
    for(int i=0;i<strlen(str);i++)
    {
        if(str[i]>='A'&&str[i]<='Z')
        {
            enc[i]=(str[i]-'A'+key)%26 + 'A';
        }
        else if(str[i]>='a'&&str[i]<='z')
        {
            enc[i]=(str[i]-'a'+key)%26 + 'a';
        }
        else if(str[i]>='0'&&str[i]<='9')
        {
            enc[i]=(str[i]-'0'+key)%10 + '0';
        }
        else
        {
            enc[i]=str[i];
        }
    }
    enc[strlen(str)]='\0';
    return enc;
}

char* decryption(const char* str,int key)
{
    char* dec=(char*)malloc(strlen(str)*sizeof(char));
    for(int i=0;i<strlen(str);i++)
    {
        if(str[i]>='A'&&str[i]<='Z')
        {
            dec[i]=(str[i]-'A'-key+26)%26 + 'A';
        }
        else if(str[i]>='a'&&str[i]<='z')
        {
            dec[i]=(str[i]-'a'-key+26)%26 + 'a';
        }
        else if(str[i]>='0'&&str[i]<='9')
        {
            dec[i]=(str[i]-'0'-key+10)%10 + '0';
        }
        else
        {
            dec[i]=str[i];
        }
    }
    dec[strlen(str)]='\0';
    return dec;
}

void main()
{
    printf("Enter Message to encrypt : \n");
    char str[100];
    scanf("%[^\n]",str);
    printf("\nEnter Encryption key [0-25] : \t");
    int key;
    scanf("%d",&key);
    if(key<0 || key>25)
    {
        printf("\nInvalid Key\n");
        exit(0);
    }
    printf("Input Text : \n%s\n",str);
    printf("Given Key : \t%d\n\n",key);

    char* enc=encryption(str,key);
    printf("Encrypted Text : \n%s\n",enc);
    
    char* dec=decryption(enc,key);
    printf("Decrypted Text : \n%s\n",dec);
}