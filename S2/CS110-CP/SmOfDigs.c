#include <stdio.h>
 
int main()
{
	int num,sm=0;
	printf("Enter a number: ");
	scanf("%d",&num);
	while(num>0)
	{
		sm+=num%10;
		num/=10;
	}
	printf("Sum=%d",sm);
	return 0;
}
