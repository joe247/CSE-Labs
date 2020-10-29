%{
    #include <stdio.h>
    #include "lex.yy.c"
    void yyerror();
%}

%token VARIABLE
%token NUMBER
%left '+' '-'
%left '*' '/' '%'
%left '(' ')'

%%
S: VARIABLE '=' E {
    printf("\nValid expression.\n");
    return 0;
};
E: E '+' E | E '-' E
 | E '*' E | E '/' E
 | E '%' E | '(' E ')'
 | NUMBER | VARIABLE;
%%

int main() {
    printf("\nEnter any arithmetic expression: ");
    yyparse();
}

void yyerror() {
    printf("\nInvalid expression!\n");
}