#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

static int row=1,col=1;
char buf[256];
const char *keywords={"exit","void","int","char","float","double","if","else","for","while","switch","case","break","const","auto"};
const char arithmeticSymbols[]={'+','-','*','/','^'};
const char specialSymbols[]={';',':',',','.','(',')','[',']','{','}','~','@','$'};
const char *predefFuncs[]={"printf","scanf"};
const char *retTypes[]={"int","char","void","float","double"};

int isKeyword(const char *str)
{
    for(int i=0;i<sizeof(keywords)/sizeof(char*);i++)
    {
        if(strcmp(str,keywords[i])==0)
        {
            return 1;
        }
    }
    return 0;
}

int isPredefFunc(const char *str)
{
    for(int i=0;i<sizeof(predefFuncs)/sizeof(char*);i++)
    {
        if(strcmp(str,predefFuncs[i])==0)
        {
            return 1;
        }
    }
    return 0;
}

int isRetType(const char *str)
{
    for(int i=0;i<sizeof(retTypes)/sizeof(char*);i++)
    {
        if(strcmp(str,retTypes[i])==0)
        {
            return 1;
        }
    }
    return 0;
}

int charBelongsto(int c,const char *arr)
{
    int len=sizeof(arr)/sizeof(char);
    for(int i=0;i<len;i++)
    {
        if(c==arr[i])
        {
            return 1;
        }
    }
    return 0;
}

struct token
{
    char lexeme[100],rettype[20],dtype[20],ttype[20];
    int row,col,index,argc;
};

struct List
{
    struct token tkn;
    struct List *next;
};

struct List *Table[30];

void Initialize()
{
    for(int i=0;i<30;i++)
    {
        Table[i]=NULL;
    }
}

int hash(const char *str)
{
    int sum=0;
    for(int i=0;i<strlen(str);i++)
    {
        sum += str[i];
    }
    return sum%30;
}

int search(const char *str)
{
    int key=hash(str);

    if(Table[key]==NULL)
    {
        return 0;
    }
    struct List *cur=Table[key];
    while(cur)
    {
        if(strcmp(str,cur->tkn.lexeme)==0)
        {
            return 1;
        }
        cur = cur->next;
    }
    return 0;
}

void insert(struct token tkn)
{
    if(search(tkn.lexeme)==1)
    {
        return;
    }
    int key=hash(tkn.lexeme);
    struct List *cur=(struct List*)malloc(sizeof(struct List));
    cur->tkn=tkn;
    cur->next=NULL;
    if(Table[key]==NULL)
    {
        Table[key]=cur;
    }
    else
    {
        struct List *ele=Table[key];
        while(ele->next)
        {
            ele = ele->next;
        }
        ele->next=cur;
    }
}

void display()
{
    printf("SL.NO\t\tNAME\t\tRET_TYPE\t\tDATA_TYPE\t\tTOK_TYPE\t\tARGC\n");
    for(int i=0;i<30;i++)
    {
        if(Table[i]==NULL)
        {
            continue;
        }
        else
        {
            struct List *ele=Table[i];
            while(ele)
            {
                printf("%d\t\t%s\t\t%s\t\t%s\t\t%s\t\t%d\n",ele->tkn.index,ele->tkn.lexeme,ele->tkn.rettype,ele->tkn.dtype,ele->tkn.ttype,ele->tkn.argc);
                ele=ele->next;
            }
        }
    }
}

void newLine()
{
    col=0;
    row++;
    printf("\n");
}

void fillToken(struct token *tkn,char c,int row,int col,char *type)
{
    tkn->row=row;
    tkn->col=col;
    strcpy(tkn->ttype,type);
    tkn->lexeme[0]=c;
    tkn->lexeme[1]='\0';
}

struct token getNextToken(FILE *f)
{
    char c;
    int gotToken=0;
    struct token tkn={.row=-1};
    while(!gotToken && (c=fgetc(f))!=EOF)
    {
        if(c=='/')
        {
            char d=fgetc(f);
            ++col;
            if(d=='/')
            {
                while((c=fgetc(f))!=EOF && c!='\n')
                {
                    ++col;
                }
                if(c=='\n')
                {
                    newLine();
                }
            }
            else if(d=='*')
            {
                do
                {
                    if(d=='\n')
                    {
                        newLine();
                    }
                    while((c=fgetc(f))!=EOF && c!='*')
                    {
                        ++col;
                        if(c=='\n')
                        {
                            newLine();
                        }
                    }
                    ++col;
                }while((d=fgetc(f))!=EOF && d!='/' && (++col));
                ++col;
            }
            else
            {
                fillToken(&tkn,c,row,--col,"/");
                gotToken=1;
                fseek(f,-1,SEEK_SET);
            }
        }
        else if(charBelongsto(c,specialSymbols)||charBelongsto(c,arithmeticSymbols))
        {
            fillToken(&tkn,c,row,--col,(char*){c,'\0'});
            gotToken=1;
            ++col;
        }
        else if(c=='+'||c=='-')
        {
            char d=fgetc(f);
            if(c!=d)
            {
                fillToken(&tkn,c,row,col,(char*){c,'\0'});
                gotToken=1;
                ++col;
                fseek(f,-1,SEEK_SET);
            }
            else
            {
                fillToken(&tkn,c,row,col,(char*){c,c,'\0'});
                gotToken=1;
                col += 2;
            }
        }
        else if(c=='='||c=='<'||c=='>')
        {
            fillToken(&tkn,c,row,col,(char*){c,'\0'});
            gotToken=1;
            ++col;
            char d=fgetc(f);
            if(d=='=')
            {
                ++col;
                strcat(tkn.lexeme,"=");
            }
            else
            {
                fseek(f,-1,SEEK_SET);
            }
        }
        else if(isdigit(c))
        {
            tkn.row=row;
            tkn.col=col;
            ++col;
            tkn.lexeme[0]=c;
            int k=1;
            while((c=fgetc(f))!=EOF && isdigit(c))
            {
                ++col;
                tkn.lexeme[k++]=c;
            }
            tkn.lexeme[k]='\0';
            strcpy(tkn.ttype,"Number");
            gotToken=1;
            fseek(f,-1,SEEK_SET);
        }
        else if(c=='#')
        {
            while((c=fgetc(f))!=EOF && c!='\n');
            if(c=='\n')
            {
                newLine();
            }
        }
        else if(c=='\n')
        {
            newLine();
        }
        else if(isspace(c))
        {
            ++col;
        }
        else if(isalpha(c)||c=='_')
        {
            tkn.row=row;
            tkn.col=col;
            ++col;
            tkn.lexeme[0]=c;
            int k=1;
            while((c=fgetc(f))!=EOF && isalnum(c))
            {
                ++col;
                tkn.lexeme[k++]=c;
            }
            tkn.lexeme[k]='\0';
            if(isKeyword(tkn.lexeme))
            {
                strcpy(tkn.ttype,"Keyword");
            }
            else
            {
                strcpy(tkn.ttype,"Identifier");
            }
            gotToken=1;
            fseek(f,-1,SEEK_SET);
        }
        else if(c=='"')
        {
            tkn.row=row;
            tkn.col=col;
            strcpy(tkn.ttype,"String");
            tkn.lexeme[0]=c;
            int k=1;
            while((c=fgetc(f))!=EOF && c!='"')
            {
                ++col;
                tkn.lexeme[k++]=c;
            }
            if(c=='"')
            {
                tkn.lexeme[k]=c;
            }
            else
            {
                fseek(f,-1,SEEK_SET);
            }
            gotToken=1;
        }
        else if(c=='&'||c=='|')
        {
            char d=fgetc(f);
            if(c!=d)
            {
                fillToken(&tkn,c,row,col,(char*){c,'\0'});
                gotToken=1;
                ++col;
                fseek(f,-1,SEEK_SET);
            }
            else
            {
                fillToken(&tkn,c,row,col,(char*){c,c,'\0'});
                gotToken=1;
                col += 2;
            }
        }
        else
        {
            ++col;
        }
    }
    return tkn;
}

void printToken(struct token tkn)
{
    printf("<%s,%d,%d>",tkn.lexeme,tkn.row,tkn.col);
}

void main(int argc,char** argv)
{
    if(argc<2)
    {
        perror("Insufficient Arguments\n");
        exit(EXIT_FAILURE);
    }
    if(argc>2)
    {
        perror("Extra Arguments\n");
        exit(EXIT_FAILURE);
    }
    FILE *f=fopen(argv[1],"r");
    struct token tkn;
    while((tkn=getNextToken(f)).row != -1)
    {
        printToken(tkn);
    }
    printf("\n");
    fclose(f);
}