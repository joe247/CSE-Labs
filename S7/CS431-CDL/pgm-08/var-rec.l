%{
    #include "y.tab.h"
%}

%%
[a-zA-Z]    {return LETTER;}
[0-9]       {return DIGIT;}
![ \t]      {} //Flag whitespace
\n          {return 0;}
.           {return yytext[0];}
%%

int yywrap(){
    return 1;
}