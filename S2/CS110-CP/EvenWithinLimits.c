#include <stdio.h>
 
int main()
{
	int l,u,i,sum=0;
	printf("Enter lower & upper limits: ");
	scanf("%d%d",&l,&u);
	if (l<u)
	{
		for(i=l;i<u;i++)
		{
			if (i%2==0)
				sum+=i;
		}
		printf("SumEven=%d", sum);
	}
	else
		printf("WishYouKnewWhatIsLarge!");
	return 0;
}
 
