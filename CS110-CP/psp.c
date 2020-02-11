#include<stdio.h>
#include<string.h>
struct Person
{
	int pid;
	char name[20];
	float age;
}*prs[10],tmp[10];

int main()
{	
	char ch[2];
	strcpy(ch,"Y");
	int i=0,j;
	while (strcmp(ch,"Y")==0 || strcmp(ch,"y")==0)
	{
		prs[i]=&tmp[i];
		printf("Person %d id = ", i+1);
		scanf("%d",&(*prs[i]).pid);

		printf("Person %d Name = ", i+1);
		scanf("%s",&(*prs[i]).name);

		printf("Person %d age = ", i+1);
		scanf("%f",&(*prs[i]).age);

		printf("\nAnother Person? ");
		scanf("%s",ch);
		i++;
	}
	printf("\n\nDetails:\n ");
	printf("Id\tName\tAge");
	for(j=0;j<i;j++)
		printf("\n%d\t%s\t%f",prs[j]->pid,prs[j]->name,prs[j]->age);
	printf("\n");
	return 0;
}
