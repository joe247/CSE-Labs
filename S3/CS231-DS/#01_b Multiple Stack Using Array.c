/**
 * Author: Jovial
 * S3 CSE
 * IES17CS016
 * Multiple Stack Using Array
 */
#include<stdio.h>

#define maxSize 10
#define maxA 5

int stack[maxSize], topA=-1, maxB=maxA, topB=maxSize;

void Push(int);
void Pop(int);
void disp();
void diTp();
void mkNULL(int);

void main(){
	int sh;
	printf("1. Push\n2. Pop\n3. Display\n4. Display Top\n5. Make NULL\n6. Exit: ");
	scanf("%d",&sh);
    printf("\n");
	switch(sh){
		int cs;
		case 1:
			printf("Push to Stack:\n1. \'A\'\n2. \'B\': ");
			scanf("%d",&cs);
			if(cs == 1 || cs == 2)
				Push(cs);
			else
				printf("\nInvalid!");
			printf("\n\n******************************\n\n");
			main();
			break;
		case 2:
			printf("Pop from Stack:\n1. \'A\'\n2. \'B\': ");
			scanf("%d",&cs);
			if(cs == 1 || cs == 2 )
				Pop(cs);
			else
				printf("\nInvalid!");
			printf("\n\n******************************\n\n");
			main();
			break;
		case 3:
			disp();
			printf("\n\n******************************\n\n");
			main();
			break;
		case 4:
			diTp();
			printf("\n\n******************************\n\n");
			main();
			break;
		case 5:
			printf("Nullify Stack:\n1. \'A\n2. \'B\'\n3. Both: ");
			scanf("%d",&cs);
			if(cs == 1 || cs == 2 || cs == 3)
				mkNULL(cs);
			else
				printf("\nInvalid!");
			printf("\n\n******************************\n\n");
			main();
			break;
		case 6:
			printf("Thanks!");
			break;
		default:
			printf("\nInvalid!");
			printf("\n\n******************************\n\n");
			main();
	}
	printf("\n");
}

void Push(int cs){
	int psh;
	if(cs == 1){
		if(topA == maxA-1)
			printf("Stack \'A\' Overflow!");
		else{
			printf("Enter a Number: ");
			scanf("%d", &psh);
			topA++;
			stack[topA]=psh;
			printf("Pushed %d! to Stack \'A\'",psh);
		}
	}
	else{
		if(topB == maxB)
			printf("Stack \'B\' Overflow!");
		else{
			printf("Enter a Number: ");
			scanf("%d", &psh);
			topB--;
			stack[topB]=psh;
			printf("Pushed %d! to Stack \'B\'",psh);
		}
	}
}

void Pop(int cs){
	int ppd;
	if(cs == 1){
		if(topA == -1)
			printf("Stack \'A\' Underflow!");
		else{
			ppd = stack[topA];
			topA--;
			printf("Popped %d! from Stack \'A\'",ppd);
		}
	}
	else{
		if(topB == maxSize)
			printf("Stack \'B\' Underflow!");
		else{
			ppd = stack[topB];
			topB++;
			printf("Popped %d! from Stack \'B\'",ppd);
		}
	}
}

void disp(){
	int i;
    if(topA == -1 && topB == maxSize)
		printf("\nBoth Stacks are empty!");
	
    else if(topA == -1){
		printf("\nStack \'A\' is empty!");
        
        printf("\nStack \'B\': ");
		for(i=maxSize-1;i>=topB;i--)
			printf("%d ", stack[i]);
    }
	else if(topB == maxSize){
		printf("\nStack \'B\' is empty!");
        
        printf("\nStack \'A\': ");
		for(i=0;i<=topA;i++)
			printf("%d ", stack[i]);
    }
	else{
		printf("\nStack \'A\': ");
		for(i=0;i<=topA;i++)
			printf("%d ", stack[i]);

		printf("\nStack \'B\': ");
		for(i=maxSize-1;i>=topB;i--)
			printf("%d ", stack[i]);
	}
}

void diTp(){
	int i;
    if(topA == -1 && topB == maxSize)
		printf("\nBoth Stacks are Empty!");
	else if(topA == -1){
		printf("\nStack \'A\' is Empty!");
        printf("\nTop Value Of Stack \'B\': %d", stack[topB]);
    }
	else if(topB == maxSize){
		printf("\nStack \'B\' is Empty!");
        printf("\nTop Value Of Stack \'A\': %d", stack[topA]);
    }
	else{
		printf("\nTop Value Of Stack \'A\': %d", stack[topA]);
		printf("\nTop Value Of Stack \'B\': %d", stack[topB]);
	}
}

void mkNULL(int cs){
	int i;
	if(cs == 1){
		if(topA == -1)
			printf("Stack \'A\' is Empty!");
		else{
			for(i=0;i<maxA;i++)			
				stack[i]=0;
			topA=-1;
			printf("Stack \'A\' Emptied!");
		}
	}
	else if(cs == 2){
		if(topB == maxSize)
			printf("Stack \'B\' is Empty!");
		else{
			for(i=maxSize-1;i>maxB;i--)			
				stack[i]=0;
			topB=maxSize;
			printf("Stack \'B\' Emptied!");
		}
	}
	else{
		if(topA == -1 && topB == maxSize-1)
			printf("Both Stacks are Empty!");
		else{
			for(i=0;i<maxSize;i++)
				stack[i]=0;
			topA=-1;
			topB=maxSize;
			printf("Both Stacks Emptied!");
		}
	}
}
