#include <stdio.h>
#include <math.h>
 
int main()
{
	int num,i=0,sum=0,sav;
	printf("Enter a number: ");
	scanf("%d", &num);
	sav=num;
	while (num>0)
	{
		num/=10;
		i++;
	}
	//i-=1;
	num=sav;
	while(num>0)
	{
		sum+=pow((num%10),i);
		num/=10;
	}
	if (sum==sav)
		printf("armstrong");
	else
		printf("nop");
	return 0;
}
