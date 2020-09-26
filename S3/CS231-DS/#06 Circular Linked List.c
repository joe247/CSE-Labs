/**
 * Author: Jovial
 * S3 CSE
 * IES17CS016
 *  Circular Linked Lists
 */
 
//Assumption the memory gets full when the 10th node is created

#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

struct Node{
	int DATA;
	struct Node *LINK;
}*start, *np, *rear, *ptr;

int F=0, R=0, i=0;

int CreateNode(int val){
    //np = new Node;
    if(F==(R+1)%SIZE){
    	printf("Node Creation Restricted!");
    	return -1;
	}
	else{
		np = (struct Node*) malloc(sizeof(struct Node)); //malloc() returns a pointer of type void which can be casted into pointer of any form;
		np->DATA = val;
		np->LINK  = NULL;
	    if(np ==  NULL){
	        printf("MEMORY FULL!");
	        exit(0);
	    }
	    i++;
	    return 0;
	}
}

void In_R(){//insertion
	if(start == NULL){
		start = rear = np;
		F++; R++;
	}
	else if(F > 0 && R == SIZE){
		np -> LINK = start;
		start = np;
		F--;
	}
	else{
		rear -> LINK = np;
		rear = np;
		rear -> LINK = NULL;
		R++;
	}
}

int De_F(){//deletion
	if(start == NULL){
		printf("Underflow!\n");
        start = rear = NULL;
        i=0; F=0; R=0;
		return -1;
	}
	else if(start == rear){
		ptr = start;
		start = rear = NULL;
    	free(ptr);//delete ptr
        printf("\nDeleted!");
        F=0; R=0; i--;
		return -1;
	}
	else{
		ptr = start;
		start = start->LINK;
		free(ptr);//delete ptr;
		F++; i--;
	}
}

void Display(){
    ptr = start;
	printf("\n\n");
	printf("<-- ");
	while(ptr != NULL){
		printf("| %d | --> ", ptr -> DATA);
		ptr = ptr -> LINK;
	}
}

int main(){
	start = rear = NULL;
	int ch, val, dr, ret;
	while(1){
		printf("1. Insert:\n2. Delete:\n3. Exit: ");
		scanf("%d", &ch);
		switch (ch){
			case 1:
				printf("A Number: ");
				scanf("%d", &val);
				ret = CreateNode(val);
				if (ret == 0){
					In_R();
					printf("\nInserted!");
					Display();
				}
				break;
			case 2:
				dr = De_F();
				if (dr != -1){
					printf("\nDeleted!");
					Display();
				}
				break;
			case 3:
				printf("Thanks!\n");
				exit(1);
				break;
			default:
				printf("Nothing!");
		}
		printf("\n\n");
	}
	return 0;
}
