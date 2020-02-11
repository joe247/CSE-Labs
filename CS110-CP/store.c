#include<stdio.h>
#include<string.h>
//#include "admin.c"
//#include "custom.c"

struct Store
{
	char name[20];
	int id,qty;
	float price,value;
}str[10],tmp[10];

void STKINZ(struct Store str[7]);
void STKSHW(struct Store str[7]);
void custom(struct Store str[7]);

int main()
{
	int ch;
	//printf("%s",ch);
	printf("Your Portal: ");
	printf("\n1. Customer\n2. Adminstrator: ");
	scanf("%d",&ch);
	STKINZ(str);
	//STKSHW(str);
	switch(ch)
	{
		case 1:
			custom(str);
			break;
		case 2:
			//admin(str);
			break;
		default:
			printf("ERROR!");
	}
	printf("\n");
	return 0;
}

void STKINZ(struct Store str[7])
{
	str[0].id=1;
	strcpy(str[0].name,"CloutX42 Exotic");
	str[0].qty=7;
	str[0].price=5999.00;
	
	str[1].id=2;
	strcpy(str[1].name,"Google Buds");
	str[1].qty=3;
	str[1].price=7980.45;
	
	str[2].id=3;
	strcpy(str[2].name,"Amazon Alexa");
	str[2].qty=5;
	str[2].price=20999.68;

	str[3].id=4;
	strcpy(str[3].name,"Samsung Gear");
	str[3].qty=9;
	str[3].price=30836.99;

	str[4].id=5;
	strcpy(str[4].name,"iPhone X");
	str[4].qty=6;
	str[4].price=89000.00;
}

void STKSHW(struct Store str[7])
{
	int i=0;
	printf("Sl No.\tID\tName\t\t\tQuantity\tPrice\n");
	while(i<5)
	{
		printf("%d\t%d\t%s\t\t\t%d\t%f", i+1, str[i].id, str[i].name, str[i].qty, str[i].price);
		printf("\n");
		i++;
	}
}

void custom(struct Store str[7])
{
	STKSHW(str);
	char itm[5];
	int no,i,gd=0,flg=0,j,qt;
	printf("\nBuy an Item(Y/N)? ");	
	scanf("%s",itm);
	while(strcmp(itm,"Y")==0||strcmp(itm,"y")==0)
	{
		printf("Enter id number: ");
		scanf("%d",&no);
		printf("Enter quantity: ");
		scanf("%d",&qt);
		for(i=0;i<5;i++)
		{
			if(str[i].id==no)
			{
				flg=1;
				if(str[i].qty>=qt)
				{				
					for(j=0;j<5;j++)
					{					
						if(tmp[j].id==no)
						{
							tmp[j].qty+=1;
							gd++;
							break;
						}
					}
					tmp[gd]=str[no-1];
					tmp[gd].qty=qt;
					str[no-1].qty-=1;
					gd++;
				}
				else
					printf("Qty left = %d!!",str[i].qty);
			}
		}
		if(flg==0)
			printf("\nGoods Not Found!\n");
		printf("\nBuy Something Again? ");
		scanf("%s", itm);
	}
	printf("\n\nBILL:\n");
	printf("Sl No.\tID\tName\t\t\tQuantity\tPrice\t\tValue\n");
	for(i=0;i<gd;i++)
	{
		tmp[i].value=tmp[i].price*tmp[i].qty;
		printf("%d\t%d\t%s\t\t\t%d\t%f\t%f\n", i+1, tmp[i].id, tmp[i].name, tmp[i].qty, tmp[i].price, tmp[i].value);
	}
}


