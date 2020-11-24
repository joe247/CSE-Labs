#include <stdio.h>
#include <ctype.h>
#include <string.h>

char input[10];
char buffer = sizeof(input);
int lp = 0, error = 0;

void E();
void _E(); // E'
void T();
void _T(); // T'
void F();

void main()
{
    printf("Enter an arithmetic [w/ only + or *] expression (w/o spaces): ");
    fgets(input, buffer, stdin);
    input[strcspn(input, "\n")] = 0; // remove extra '\n' from input
    //printf("%ld\n", strlen(input));

    E();
    
    //printf("%d : %ld\n", lp, strlen(input));

    if (strlen(input) == lp && error == 0)
        printf("Accepted\n");
    else
        printf("Rejected\n");
}

void E() // E --> TE'
{
    T();
    _E();
}

void _E() // E' --> +TE' | e
{
    if (input[lp] == '+')
    {
        lp++;
        T();
        _E();
    }
}

void T() // T --> FT'
{
    F();
    _T();
}

void _T() // T' --> *FT' | e
{
    if (input[lp] == '*') // cheating: goes beyond bonds
    {
        lp++;
        F();
        _T();
    }
}

void F() // F --> (E) | val
{
    if (input[lp] == '(')
    {
        lp++;
        E();
        if (input[lp] == ')')
            lp++;
    }
    else if (isalpha(input[lp]))
    {
        lp++;
        /*while (isalnum(input[lp]) || input[lp] == '_') // This is dangerous as it goes out of bounds!
        {
            lp++;
            printf("%d", lp);
        }*/
    }
    else
        error = 1;
}