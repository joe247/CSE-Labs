#include<stdio.h>

int fact(int f)
{
	int rt=1;
	while(f>0)
	{
		rt*=f;
		f--;
	}
	return rt;
}

int main()
{
	double sum=1.0,j;
	int i,k,n;
	printf("enter a limit: ");
	scanf("%d", &n);
	for(i=0,j=2,k=3; i<n; i++,j++,k+=2)
	{
		//printf("%f\n",sum);
		//printf("%d\n\n",fact(k));
		sum+=(j/fact(k));
	}
	printf("sum = %f",sum);
	return 0;
}


