//Create a file, (write & read) contents (to & from) it respectively.
#include<stdio.h>
#include<string.h>
int main()
{
	FILE *RW;
	char fnam[20],ch[2]="y",wrt,rad;
	printf("Enter filename with extention: ");
	scanf("%s",fnam);
	
	//Writing
	RW=fopen(fnam,"w");
	while(strcmp(ch,"Y")==0 || strcmp(ch,"y")==0)
	{
		wrt=getchar();
		putc(wrt,RW);
		printf("Another character? ");
		scanf("%s",ch);

	}
	fclose(RW);
	
	//Reading
	RW=fopen(fnam,"r");
	while((rad=getc(RW))!=EOF)
	{
		printf("%c",rad);
	}
	fclose(RW);
	return 0;
}
