%%
[0-9]+              printf("+ve no.");
-[0-9]+             printf("-ve no.");
[a-zA-Z]+[A-Z0-9]*  printf("Identifier");
%%

int main() {
    yylex();
}
int yywrap() {
    return 1;
}