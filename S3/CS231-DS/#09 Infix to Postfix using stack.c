/**
 * Infix to Postfix using stack
 */
#include<stdio.h>
#include<ctype.h>
char stack[20];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}
 
char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}
 
int priority(char x)
{
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    if(x == '^')
        return 3;
}
 
int main()
{
    char exp[20];
    char *p, x;
    printf("Enter the expression :: ");
    scanf("%s",exp);
    p = exp;
    while(*p != '\0')
    {
        if(isalnum(*p))
            printf("%c",*p);
        else if(*p == '(')
            push(*p);
        else if(*p == ')')
        {
            while((x = pop()) != '(')
                printf("%c", x);
        }
        else
        {
            while(priority(stack[top]) >= priority(*p))
                printf("%c",pop());
            push(*p);
        }
        p++;
    }
    while(top != -1)
    {
        printf("%c",pop());
    }
    return 0;
}
