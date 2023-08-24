#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define FILEINPUT "input.txt"

struct token {
    char lexeme[64];
    int row, col;
    char type[20];
};

static int row = 1, col = 1;
char buf[2048];

const char specialsymbols[] = {'?', ';', ':', ','};
const char arithmeticsymbols[] = {'*'};

const char *keywords[] = {"for", "if", "else", "while", "do", "break", "continue", "return",
                         "int", "double", "float", "char", "long", "short", "sizeof",
                         "typedef", "switch", "case", "struct", "const", "void", "exit"};

int isKeyword(const char *str) {
    for (int i = 0; i < sizeof(keywords) / sizeof(char *); i++) {
        if (strcmp(str, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int charBelongsTo(int c, const char *arr) {
    int len;

    if (arr == specialsymbols) {
        len = sizeof(specialsymbols) / sizeof(char);
    } else if (arr == arithmeticsymbols) {
        len = sizeof(arithmeticsymbols) / sizeof(char);
    }

    for (int i = 0; i < len; i++) {
        if (c == arr[i]) {
            return 1;
        }
    }

    return 0;
}

void fillToken(struct token *tkn, char c, int row, int col, char *type) {
    tkn->row = row;
    tkn->col = col;
    strcpy(tkn->type, type);
    tkn->lexeme[0] = c;
    tkn->lexeme[1] = '\0';
}

void newLine() {
    ++row;
    col = 1;
}

struct token getNextToken(FILE *f1) {
    int c;
    struct token tkn = {.row = -1};
    int gotToken = 0;

    while (!gotToken && (c = fgetc(f1)) != EOF) {
        switch (c) {
            case '?':
            case ';':
            case ':':
            case ',':
                fillToken(&tkn, c, row, col, "SS");
                gotToken = 1;
                ++col;
                break;
            case '*':
                fillToken(&tkn, c, row, col, "ARITHMETIC OPERATOR");
                gotToken = 1;
                ++col;
                break;
            case '(':
                fillToken(&tkn, c, row, col, "LB");
                gotToken = 1;
                ++col;
                break;
            case ')':
                fillToken(&tkn, c, row, col, "RB");
                gotToken = 1;
                ++col;
                break;
            case '{':
                fillToken(&tkn, c, row, col, "LC");
                gotToken = 1;
                ++col;
                break;
            case '}':
                fillToken(&tkn, c, row, col, "RC");
                gotToken = 1;
                ++col;
                break;
            case '+':
            case '-':
                if (c == '+') {
                    int d = fgetc(f1);
                    if (d != '+') {
                        fillToken(&tkn, c, row, col, "ARITHMETIC OPERATOR");
                        gotToken = 1;
                        ++col;
                        fseek(f1, -1, SEEK_CUR);
                    } else {
                        fillToken(&tkn, c, row, col, "UNARY OPERATOR");
                        strcpy(tkn.lexeme, "++");
                        gotToken = 1;
                        col += 2;
                    }
                } else if (c == '-') {
                    int d = fgetc(f1);
                    if (d != '-') {
                        fillToken(&tkn, c, row, col, "ARITHMETIC OPERATOR");
                        gotToken = 1;
                        ++col;
                        fseek(f1, -1, SEEK_CUR);
                    } else {
                        fillToken(&tkn, c, row, col, "UNARY OPERATOR");
                        strcpy(tkn.lexeme, "--");
                        gotToken = 1;
                        col += 2;
                    }
                }
                break;
            case '=':
                int d = fgetc(f1);
                if (d != '=') {
                    fillToken(&tkn, c, row, col, "ASSIGNMENT OPERATOR");
                    gotToken = 1;
                    ++col;
                    fseek(f1, -1, SEEK_CUR);
                } else {
                    fillToken(&tkn, c, row, col, "RELATIONAL OPERATOR");
                    strcpy(tkn.lexeme, "==");
                    gotToken = 1;
                    col += 2;
                }
                break;
            case '&':
            case '|':
                d = fgetc(f1);
                if (c == d) {
                    tkn.lexeme[0] = tkn.lexeme[1] = c;
                    tkn.lexeme[2] = '\0';
                    tkn.row = row;
                    tkn.col = col;
                    ++col;
                    gotToken = 1;
                    strcpy(tkn.type, "LOGICAL OPERATOR");
                } else {
                    fseek(f1, -1, SEEK_CUR);
                }
                ++col;
                break;
            case '<':
            case '>':
            case '!':
                fillToken(&tkn, c, row, col, "RELATIONAL OPERATOR");
                ++col;
                d = fgetc(f1);
                if (d == '=') {
                    ++col;
                    strcat(tkn.lexeme, "=");
                } else if (c == '!') {
                    strcpy(tkn.type, "LOGICAL OPERATOR");
                } else {
                    fseek(f1, -1, SEEK_CUR);
                }
                gotToken = 1;
                break;
            case '/':
                d = fgetc(f1);
                ++col;
                if (d == '/') {
                    while ((c = fgetc(f1)) != EOF && c != '\n') {
                        ++col;
                    }
                    if (c == '\n') {
                        newLine();
                    }
                } else if (d == '*') {
                    do {
                        if (d == '\n') {
                            newLine();
                        }
                        while ((c = fgetc(f1)) != EOF && c != '*') {
                            ++col;
                            if (c == '\n') {
                                newLine();
                            }
                        }
                        ++col;
                    } while ((d = fgetc(f1)) != EOF && d != '/');
                    ++col;
                } else {
                    fillToken(&tkn, c, row, --col, "ARITHMETIC OPERATOR");
                    gotToken = 1;
                    fseek(f1, -1, SEEK_CUR);
                }
                break;
            case '"':
                tkn.row = row;
                tkn.col = col;
                strcpy(tkn.type, "STRING LITERAL");
                int k = 1;
                tkn.lexeme[0] = '"';
                while ((c = fgetc(f1)) != EOF && c != '"') {
                    tkn.lexeme[k++] = c;
                    ++col;
                }
                tkn.lexeme[k] = '"';
                gotToken = 1;
                break;
            case '#':
                while ((c = fgetc(f1)) != EOF && c != '\n');
                newLine();
                break;
            case '\n':
                newLine();
                c = fgetc(f1);
                if (c == '#') {
                    while ((c = fgetc(f1)) != EOF && c != '\n');
                    newLine();
                } else if (c != EOF) {
                    fseek(f1, -1, SEEK_CUR);
                }
                break;
            case ' ':
            case '\t':
                ++col;
                break;
            default:
                if (isalpha(c) || c == '_') {
                    tkn.row = row;
                    tkn.col = col++;
                    tkn.lexeme[0] = c;
                    int k = 1;
                    while ((c = fgetc(f1)) != EOF && isalnum(c)) {
                        tkn.lexeme[k++] = c;
                        ++col;
                    }
                    tkn.lexeme[k] = '\0';
                    if (isKeyword(tkn.lexeme)) {
                        strcpy(tkn.type, "KEYWORD");
                    } else {
                        strcpy(tkn.type, "IDENTIFIER");
                    }
                    gotToken = 1;
                    fseek(f1, -1, SEEK_CUR);
                } else {
                    ++col;
                }
        }
    }
    return tkn;
}

int main() {
    FILE *f1 = fopen(FILEINPUT, "r");
    if (f1 == NULL) {
        printf("Error! File cannot be opened!\n");
        return 0;
    }

    struct token tkn;
    while ((tkn = getNextToken(f1)).row != -1) {
        printf("<%s, %d, %d>\n", tkn.type, tkn.row, tkn.col);
    }

    fclose(f1);
    return 0;
}