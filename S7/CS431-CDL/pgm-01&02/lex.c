#include <ctype.h>
#include <stdio.h>
#include <string.h>
int main() {
    FILE *fi, *fo, *fop, *fk;
    int flag = 0, i = 1;
    char c, t, a[15], ch[15], file[20];
    printf("\n Enter the File Name: ");
    scanf("%s", file);            // need not give & as string == char*
    fi = fopen(file, "r");        // fi == input file
    fo = fopen("inter.txt", "w"); // fo == output file
    fop = fopen("opr.txt", "r");  // fop == operator files
    fk = fopen("key.txt", "r");   // fk == keyword file
    c = getc(fi);                 // characters are being read from the input file
    while (!feof(fi)) {           // until file characters end
        if (isalnum(c) || ((c == '[' || c == ']' || c == '.') == 1))
            fputc(c, fo); // write it to output file
        else {
            if (c == '\n')
                fprintf(fo, "\t$\t");
            else
                fprintf(fo, "\t%c\t", c);
        }
        c = getc(fi);
    }
    fclose(fi);
    fclose(fo);
    fi = fopen("inter.txt", "r");
    printf("\n Lexical Analysis");
    fscanf(fi, "%s", a);
    printf("\n Line: %d\n", i++);
    while (!feof(fi)) {
        if (strcmp(a, "$") == 0) {
            printf("\n Line: %d \n", i++);
            fscanf(fi, "%s", a);
        }
        fscanf(fop, "%s", ch);
        while (!feof(fop)) {
            if (strcmp(ch, a) == 0) {
                fscanf(fop, "%s", ch);
                printf("\t\t%s\t:\t%s\n", a, ch);
                flag = 1;
            }
            fscanf(fop, "%s", ch);
        }
        rewind(fop);
        fscanf(fk, "%s", ch);
        while (!feof(fk)) {
            if (strcmp(ch, a) == 0) {
                fscanf(fk, "%s", ch);
                printf("\t\t%s\t:\tKeyword\n", a);
                flag = 1;
            }
            fscanf(fk, "%s", ch);
        }
        rewind(fk);
        if (flag == 0) {
            if (isdigit(a[0]))
                printf("\t\t%s\t:\tConstant\n", a);
            else
            printf("\t\t%s\t:\tIdentifier\n", a);
        }
        flag = 0;
        fscanf(fi, "%s", a);
    }
    return 0;
}