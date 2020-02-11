#include<stdio.h>
float arrsm(float*,int);
int main()
{
	float *ptr,rslt;
	int lm;
	printf("Enter a limit: ");
	scanf("%d",&lm);
	rslt=arrsm(ptr,lm);
	printf("Sum of the elements: %f\n", rslt);
	return 0;
}

float arrsm(float *p,int l)
{
	float sm,arr[20];
	int i;
	p=arr;
	printf("Enter the array values: ");
	for(i=0;i<l;i++)
	{
		scanf("%f", p);
		sm+=*p;
		p++;
	}
	return sm;
}
