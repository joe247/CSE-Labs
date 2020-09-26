#include<stdio.h>
#include <stdlib.h>
void CHK(int,int);
void INZ(int,int,int matX[20][20],int,int,int matY[20][20]);
void MLP(int,int,int matX[20][20],int,int,int matY[20][20]);
int main()
{
	int k,l,m,n;
	int matX[20][20],matY[20][20];
	printf("Enter order for matrix1: ");
	scanf("%d%d",&k,&l);
	printf("Enter order for matrix2: ");
	scanf("%d%d",&m,&n);
	CHK(l,m);
	INZ(k,l,matX,m,n,matY);
	MLP(k,l,matX,m,n,matY);
	return 0;
}
void CHK(int l,int m)
{
	if(l!=m)
	{
		printf("Cant Multiply!\n");
		printf("No of Columns(of mat1) != No of Rows(of mat2)");
		exit(0);
	}
}
void INZ(int k,int l,int matX[k][l],int m,int n,int matY[m][n])
{
	int i,j;
	printf("Enter Matrix1(%d x %d): ",k,l);
	for(i=0;i<k;i++)
	{
		for(j=0;j<l;j++)
			scanf("%d", &matX[i][j]);
	}
	printf("Enter Matrix2(%d x %d): ",m,n);
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			scanf("%d", &matY[i][j]);
	}
}
void MLP(int k, int l,int matX[k][l],int m,int n,int matY[m][n])
{
	int e,i,j,res[20][20];
	for(i=0;i<k;i++)
	{
		for(j=0;j<n;j++)
		{
			res[i][j]=0;
			for(e=0;e<n;e++)
				res[i][j] += matX[i][e]*matY[e][j];
			printf("%d ",res[i][j]);
		}
		printf("\n");
	}
}
