#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define max 100
char s[max];
int top=-1;
void push(int value)
{
    if(top==max-1)
    {
        printf("overflow,cant push");

    }
    else{
        s[++top]=value;
    }
}
int pop()
{
    int value;
    if(top==-1){
        printf("stack underflow,cant pop\n");
        exit(1);

    }
    else{
        value=s[top--];
        // printf("%d is popped\n",value);
        return value;
        
    }
}
int main()
{
    char exp[100];
    char *e;
    int value=0;
    printf("enter the exp:");
    scanf("%s",exp);
    e=exp;
    while(*e!='\0')
    {
        if(isdigit(*e))
        {
            int num=*e-'0';
            push(num);
        }
        else{
            char op1=pop();
            char op2=pop();
            switch (*e)
            {
            case '+':
                value=op1+op2;
                break;
            case '-':
                value=op2-op1;
                break;
            case '*':
                value=op1*op2;
                break;
            case '/':
                value=op1/op2;
                break;            
            
            }
            push(value);
        }
        e++;
    }

    printf("eval:%d",pop());
}