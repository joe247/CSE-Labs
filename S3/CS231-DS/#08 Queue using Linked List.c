/**
 * Author: Jovial
 * S3 CSE
 * IES17CS016
 * Queue using Linked Lists
 */
#include<stdio.h>
#include<stdlib.h>

struct Node{
	int DATA;
	struct Node *LINK;
}*front, *rear, *np, *ptr;


void CreateNode(int val){
	np = (struct Node*) malloc(sizeof(struct Node));
    if(np ==  NULL){
        printf("MEMORY FULL!");
        exit(1);
    }
    np->DATA = val;
	np->LINK  = NULL;
}

void In_R(){//insertion at rear
	if(front == NULL)
		front = rear = np;
	else{
		rear -> LINK = np;
		rear = np;
		rear -> LINK = NULL;
	}
}

int De_F(){//deletion from front
	if(front == NULL){
		printf("Empty LL!!\n");
        front = NULL;
	}
	else if(front == rear){
		ptr = front;
		front = rear = NULL;
    	free(ptr);
        printf("\nDeleted!");
	}
	else{
		ptr = front;
		front = front->LINK;
		free(ptr);
        return -1;
	}
}

void Display(){
    ptr = front;
    printf("\n\n");
	while(ptr != NULL){
		printf("| %d | --> ", ptr -> DATA);
		ptr = ptr -> LINK;
	}
	printf(" X");
	
}

int main(){
	front = rear = NULL;
	int ch, val, retn;
	while(1){
		printf("1. Insert\n2. Delete\n3. Exit: ");
		scanf("%d", &ch);
		switch (ch){
            case 1:
				printf("A Number: ");
				scanf("%d", &val);
				CreateNode(val);
				printf("\nNode Created!");
				In_R();
				printf("\nInserted!");
				Display();
				break;
			case 2:
				retn = De_F();
				if (retn == -1){
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
