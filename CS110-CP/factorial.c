#include <stdio.h>
 
int main()
{
	int num,f=1;
	printf("Enter a number: ");
	scanf("%d",&num);
	printf("Factorial of %d = ",num);
	while (num>0)
	{
		f*=num;
		num--;
	}
	printf("%d",f);
	return 0;
}
 
