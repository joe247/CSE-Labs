#include <stdio.h>
 
int main()
{
	int i,j,l,tmp,a[20];
	printf("Enter a limit: ");
	scanf("%d",&l);
	for(i=0;i<l;i++)
		scanf("%d",&a[i]);
	for(i=0;i<l;i++)
	{
		for(j=0;j<l;j++)
		{
			if(a[i]>=a[j])
			{
				tmp=a[i];
				a[i]=a[j];
				a[j]=tmp;
			}
		}
	}
	for(i=0;i<l;i++)
		printf("%d ",a[i]);
	return 0;
}
 
