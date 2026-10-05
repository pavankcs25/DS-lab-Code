#include<stdio.h>
#include<string.h>
int F(char ch)
{
    switch(ch)
    {
    case '+':
    case '-':
        return 2;
        break;
    case '*':
    case '/':
        return 4;
        break;
    case '$':
    case '^':
        return 5;
        break;
    case '(':
        return 0;
        break;
    case '#':
        return -1;
    default :
        return 8;
    }
}
int G(char ch)
{
    switch(ch)
    {
    case '+':
    case '-':
        return 1;
        break;
    case '*':
    case '/':
        return 3;
        break;
    case '$':
    case '^':
        return 6;
        break;
    case '(':
        return 9;
        break;
    case ')':
        return 0;
        break;
    default :
        return 7;
    }
}
void exp(char infix[], char postfix[])
{
    char symbol;
    int i=0,k=0;
    int top=-1;
    char s[30];
    s[++top]='#';
    for(i=0;i<strlen(infix);i++)
    {
        symbol=infix[i];
        while(F(s[top])>G(symbol))
        {
            postfix[k++]=s[top--];
        }
        if(F(s[top])!=G(symbol))
        {
            s[++top]=symbol;
        }
        else
        {
            top--;
        }
    }
    while(s[top]!='#')
    {
        postfix[k++]=s[top--];
    }
    postfix[k]='\0';
    printf("%s",postfix);
}
int main()
{
    char infix[50],postfix[50];
    printf("Enter the infix expression:");
    scanf("%s",infix);
    printf("Postfix expression:");
    exp(infix,postfix);
    return 0;
}
