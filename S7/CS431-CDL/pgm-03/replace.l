%%
[ \t]   printf(" ");
[\n]    printf(" ");
%%

int main() {
    extern FILE *yyin;
    yyin = fopen("new.txt", "r");
    yylex();
    printf("\n");
}
int yywrap() {
    return 1;
}