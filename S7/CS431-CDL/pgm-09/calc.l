%{
    // help source: https://www.geeksforgeeks.org/yacc-program-to-implement-a-calculator-and-recognize-a-valid-arithmetic-expression/
    
    /* C Definitions */
    #include "y.tab.h"

    /*
    If you're going to use #define to redefine YYSTYPE, then you need to do it before you #include <y.tab.h>. Otherwise, y.tab.h will make YYSTYPE a type alias (typedef) for int. Since both y.tab.h and y.tab.c also declare yylval (as extern YYSTYPE), there is actually no need for you to declare it anywhere, but you still need to put the #define before the #include.

    If you use bison, there are much better (and more convenient) ways to declare of YYSTYPE. The best one is to put

    %define api.value.type { char* }

    into your .y file, for example just before the %token declaration. Then you can remove the #define YYSTYPE from both files, as well as the extern YYSTYPE yylval; declarations, since bison will put an appropriate typedef into the header file.

    You really should compile your project with

    gcc -Wall lex.yy.c y.tab.c

    Then gcc will warn you about many mistakes. Both bison and flex will produce warning-free code, provided you put the following into your lex file:

    %option noinput nounput

    I usually recommend using %option noyywrap as well, since that will allow you to avoid having to write a dummy yywrap implementation.

    */
    
%}

%option noyywrap

/* Rule Section */
%%
[0-9]*[.]?[0-9]* {
                    yylval=atof(yytext);
                    return NUMBER;
                }
[ \t]           ;
\n              return 0;
.               return yytext[0];
%%
