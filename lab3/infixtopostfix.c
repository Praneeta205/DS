#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define max 100
char s[max];
int top=-1;
void push(char value)
{
    
    s[++top]=value;
    
}
char pop()
{
    char value=' ';
    if (top==-1)
        return value;
    else
        return s[top--];
}
int pre(char value)
{
    if(value=='^')
    {
        return 3;
    }
    else if(value =='*' || value =='/')
    {
        return 2;
    }
    else if(value =='+' || value =='-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}
void convert(char infix[],char postfix[])
{
    int i=0,j=0;
    char x;
    while(infix[i]!='\0')
    {
        if(infix[i]=='(')
        {
            push(infix[i]);
            i++;
        }
        else if(infix[i]==')')
        {
            while((s[top]!='(') && (top!=-1))
            {
                postfix[j++]=pop();
                
            }
            x=pop();
            i++;
        }
        else if(isalnum(infix[i]))
        {
            postfix[j++]=infix[i];
            i++;

        }
        else 
        {
            while((s[top]!='(') &&( top!=-1) && (pre(s[top])>=pre(infix[i])))
            {
                postfix[j++]=pop();

            }
            push(infix[i]);
            i++;
        }
    }
       
    while((s[top]!='(') && (top!=-1))
    {
        postfix[j++]=pop();
    }
    postfix[j]='\0';
}

void main()
{
    char infix[100],postfix[100];
    printf("enter the exp:");
    scanf("%s",infix);
    convert(infix,postfix);
    printf("postfix:");
    printf("%s",postfix);
}
