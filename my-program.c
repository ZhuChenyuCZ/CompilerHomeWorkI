#include<stdio.h>

char line[2550];
int pos;
char Token[2550];
int TokenLen,lineLen;
int NoMore=0;

void clearToken()
{
    memset(Token,0,sizeof(Token));
    Token[0]='\n';
    TokenLen=0;
}

int isSpace()
{
    char ch=line[pos];
    if (ch==' ') return 1; else return 0;
}

int isNewLine()
{
    char ch=line[pos];
    if (ch=='\n'||ch=='\0') return 1; else return 0;
}

int isTab()
{
    char ch=line[pos];
    if (ch=='\t') return 1; else return 0;
}

int isLetter()
{
    char ch=line[pos];
    if ((ch>='a'&& ch<='z')||(ch>='A'&&ch<='Z')) return 1; 
    else return 0;
}

int isDigit()
{
    char ch=line[pos];
    if (ch>='0'&&ch<='9') return 1;
    else return 0;
}

int isColon()
{
    char ch=line[pos];
    if (ch==':') return 1; else return 0;
}

int isEqu()
{
    char ch=line[pos];
    if (ch=='=') return 1; else return 0;
}

int isPlus()
{
    char ch=line[pos];
    if (ch=='+') return 1; else return 0;
}

int isMinus()
{
    char ch=line[pos];
    if (ch=='-') return 1; else return 0;
}

int isStar()
{
    char ch=line[pos];
    if (ch=='*') return 1; else return 0;
}

int isComma()
{
    char ch=line[pos];
    if (ch==',') return 1; else return 0;
}

int isLpar()
{
    char ch=line[pos];
    if (ch=='(') return 1; else return 0;
}

int isRpar()
{
    char ch=line[pos];
    if (ch==')') return 1; else return 0;
}



void catToken()
{
    Token[TokenLen]=line[pos];
    TokenLen++;
    Token[TokenLen]='\n';
}

int reserver()
{
    if (strcmp(Token,"BEGIN\n")==0)
    {
        printf("Begin\n");
    }
    else if (strcmp(Token,"END\n")==0)
    {
        printf("End\n");
    }
    else if (strcmp(Token,"FOR\n")==0)
    {
        printf("For\n");
    }
    else if (strcmp(Token,"IF\n")==0)
    {
        printf("If\n");
    }
    else if (strcmp(Token,"THEN\n")==0)
    {
        printf("Then\n");
    }
    else if (strcmp(Token,"ELSE\n")==0)
    {
        printf("Else\n");
    }
    else 
    {
        //标识符
        printf("Ident(");
        for (int i=0;i<TokenLen;i++) 
            printf("%c",Token[i]);
        printf(")\n");
    }
}

int transNum()
{
    printf("Int(");
    int isZero=0;
    for (int i=0;i<TokenLen-1;i++)
    {
        if (Token[i]!='0') isZero=1;
        if (isZero==0) continue;
        printf("%c",Token[i]);
    }
    printf("%c",Token[TokenLen-1]);
    printf(")\n");
}

int getsym()
{
    //printf("%s", line);
    //printf("pos: %d %c\n",pos,line[pos]);
    clearToken();
    if (isNewLine()) 
    {
        pos=lineLen+2; 
        return 0;
    }
    while (isSpace()||isTab())
        pos++;
    if (isLetter())
    {
        while (isLetter()||isDigit())
        {
            catToken();
            pos++;
        }
        pos--;
        reserver();
    }
    else if(isDigit())
    {
       while(isDigit())
       {
           catToken();
           pos++;
       }
       pos--;
       transNum();
    }
    else if(isColon())
    {
        pos++;
        if (isEqu()) printf("Assign\n");
        else 
        {
            pos--;
            printf("Colon\n");
        }
    }
    else if (isPlus())
    {
        printf("Plus\n");
    }
    else if (isStar()) printf("Star\n");
    else if (isComma()) printf("Comma\n");
    else if (isLpar()) printf("LParenthesis\n");
    else if (isRpar()) printf("RParenthesis\n");
    else 
    { 
        printf("Unknown\n");
        NoMore=1;
    }
    pos++;
    return 0;
}

int main(int argc, char *argv[])
{
    FILE *fp = NULL;
 
    //fp = fopen("./test.txt", "r");
    fp = fopen(argv[1], "r");
    int i=-1;
    while (fgets(line, 2000, (FILE*)fp)!=NULL)
    {
        i++;
        if (NoMore==1) break;
        //fscanf(fp, "%s", line);
        //fgets(line, 2000, (FILE*)fp);
        //printf("%d: %s\n", i+1, line );
        //printf("%d\n",strlen(line)-2);
        lineLen=strlen(line);
        pos=0;
        while (pos<lineLen-1&&NoMore==0)
            getsym();
    }
    fclose(fp);
}