#include <ctype.h>
#include <stdio.h>
#include <string.h>

void gen_tokens(FILE *f_inp, FILE *f_itr, char *inp_f);
void recognize_char(FILE *f_itr, FILE *f_opr, FILE *f_key);

int main() {
    // Create file buffers
    FILE *f_inp, *f_itr, *f_opr, *f_key;
    char inp_f[20];
    printf("Enter file name: ");
    scanf("%s", inp_f);
    gen_tokens(f_inp, f_itr, inp_f);
    recognize_char(f_itr, f_opr, f_key);
    return 0;
}

void gen_tokens(FILE *f_inp, FILE *f_itr, char *inp_f){
    
    char chtr;

    f_inp = fopen(inp_f, "r");
    f_itr = fopen("inter.txt", "w");

    while(!feof(f_inp)){
        chtr = fgetc(f_inp); // getc is kind of macro but fgetc is purely function (latter takes longer to call but safer)
        if (feof(f_inp)) break;
        //printf("%c", temp);
        if (isalnum(chtr) || (chtr == '[' || chtr == ']' || chtr == '.') == 1){
            fputc(chtr, f_itr);
        }
        else{
            (chtr == '\n') ? fprintf(f_itr, "\t$\t") : fprintf(f_itr, "\t%c\t", chtr);
        }
    }

    fclose(f_inp);
    fclose(f_itr);
    return;
}

void recognize_char(FILE *f_itr, FILE *f_opr, FILE *f_key) {
    
    char chtr[20], temp[20];
    int l_count = 0, flag;
    
    f_itr = fopen("inter.txt", "r");
    f_opr = fopen("opr.txt", "r");
    f_key = fopen("key.txt", "r");
    
    printf("\nLine: %d \n", ++l_count);
    while (!feof(f_itr)) {
        fscanf(f_itr, "%s", chtr);
        if (feof(f_itr)) break;
        flag = 0;
        if (strcmp(chtr, "$") == 0){ // strcmp return 0 if true
            printf("\nLine: %d \n", ++l_count);
            continue;
        }

        // crosscheck operators
        while (!feof(f_opr)) {
            if (feof(f_opr)) break;
            fscanf(f_opr, "%s", temp);
            if (strcmp(temp, chtr) == 0){
                fscanf(f_opr, "%s", temp);
                printf("\t\t%s\t:\t%s\n", chtr, temp);
                flag = 1;
            }
        }
        rewind(f_opr);
        if (flag == 1) continue;

        // crosscheck keywords
        while (!feof(f_key)) {
            if (feof(f_key))
                break;
            fscanf(f_key, "%s", temp);
            if (strcmp(temp, chtr) == 0){
                fscanf(f_key, "%s", temp);
                printf("\t\t%s\t:\tKeyword\n", chtr);
                flag = 1;
            }
        }
        rewind(f_key);
        if (flag == 1) continue;

        // if neither keyword nor operator
        isdigit(chtr[0]) ? printf("\t\t%s\t:\tConstant\n", chtr) : printf("\t\t%s\t:\tIdentifier\n", chtr);
    }

    fclose(f_itr);
    fclose(f_opr);
    fclose(f_key);
    return;
}