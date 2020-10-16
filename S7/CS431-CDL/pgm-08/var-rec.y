%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "lex.yy.c"
    void yyerror();
%}

%token LETTER
%token DIGIT

%%
S: A;
A: LETTER B;
B: LETTER B | DIGIT B | LETTER | DIGIT;
%%

void main() {
    printf("Enter a variable: ");
    yyparse();
    printf("Valid\n");
    exit(0);
}

void yyerror() {
    printf("Invalid\n");
    exit(0);
}