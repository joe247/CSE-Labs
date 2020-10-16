%{
#include <stdio.h>
int lines=1, words=0, s_letters=0, c_letters=0, num=0, spl_char=0, total=0;
%}

%%
\n    {lines++;}
[ \t] {words++;}
[a-z] {s_letters++;}
[A-Z] {c_letters++;}
[0-9] {num++;}
. {spl_char++;}
%%

void main(void) {
    yyin = fopen("myfile.txt", "r");
    yylex();
    total = s_letters + c_letters + spl_char;
    printf("This file contains...");
    printf("\n\t%d lines", lines);
    printf("\n\t%d words", words+2);
    printf("\n\t%d small letters", s_letters);
    printf("\n\t%d capital letters", c_letters);
    printf("\n\t%d digits", num);
    printf("\n\t%d special characters", spl_char);
    printf("\n\t%d total characters\n", total);
    
    // Todo
    //char ent_name = ["lines", "words", "small letters", "capital letters", "digits", "special characters", "total characters\n"];
    //int ent_val = [lines, words+2, s_letters, c_letters, num, spl_char, total];
    //for int i = 0; i < 
}
int yywrap(){
    return 1;
}