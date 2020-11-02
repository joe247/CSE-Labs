%{
    /* C Definitions */
    #include <stdio.h>
    #include <math.h>

    #define YYSTYPE double // https://stackoverflow.com/questions/53818618/error-conflicting-types-for-yylval-extern-yystype-yylval

    #include "lex.yy.c"

    void yyerror();
%}

%token NUMBER

%left '+' '-'
%left '*' '/' '%'
%left '(' ')'

/* Rule Section */
%%
S: E {
    printf("\nValid expression\n");
    printf("\nResult = %g\n", $$);
    return 0;
};
E: E '+' E {$$ = $1 + $3;} | E '-' E {$$ = $1 - $3;}
 | E '*' E {$$ = $1 * $3;} | E '/' E {$$ = $1 / $3;}
 | E '%' E {$$ = fmod($1, $3);} | '(' E ')' {$$ = $2;}
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
    exit(-1);
}