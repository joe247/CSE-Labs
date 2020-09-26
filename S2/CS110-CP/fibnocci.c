#include <stdio.h>
 
int main()
{
	int n,i,a,b,c;
	printf("Enter a limit: ");
	scanf("%d", &n);
	if(n>2)
	{
		printf("%d", 0);
		printf(" %d", 1);
		a=0;
		b=1;
		for(i=2;i<n;i++)
		{
			c=a+b;
			printf(" %d", c);
			a=b;
			b=c;
		}
	}
	else
		printf("limit must be>2");
	return 0;
}
 
