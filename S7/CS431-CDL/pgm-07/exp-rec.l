%{
    #include "y.tab.h"
%}

%%
[a-zA-Z]+   {return VARIABLE;}
[0-9]       {return NUMBER;}
[ \t]       {} //Do nothing if whitespace
[\n]        {return 0;}
.           {return yytext[0];}
%%

int yywrap(){
    return 1;
}