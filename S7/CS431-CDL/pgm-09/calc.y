%{
    /* C Definitions */
    #include <stdio.h>
    #include "lex.yy.c"

    void yyerror();
    int flag = 0;
%}

%token NUMBER
%left '+' '-'
%left '*' '/' '%'
%left '(' ')'

/* Rule Section */
%%
S: E {
    if(flag == 0)
        printf("\nValid expression\n");
    printf("\nResult = %d\n", $$);
    return 0;
};
E: E '+' E {$$ = $1 + $3;} | E '-' E {$$ = $1 - $3;}
 | E '*' E {$$ = $1 * $3;} | E '/' E {$$ = $1 / $3;}
 | E '%' E {$$ = $1 % $3;} | '(' E ')' {$$ = $2;}
 | '-' E {$$ = -$2;} | '+' E {$$ = $2;}
 | NUMBER {$$ = $1;};
%%

/* Driver code */
void main() {
    printf("\nEnter any Arithmetic Expression: ");
    yyparse();
}

void yyerror() {
    printf("\nInvalid expression!\n");
    flag = 1;
}