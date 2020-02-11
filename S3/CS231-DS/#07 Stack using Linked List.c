/**
 * Author: Jovial
 * S3 CSE
 * IES17CS016
 * Stack using Linked Lists
 */
#include<stdio.h>
#include<stdlib.h>

struct Node{
	int DATA;
	struct Node *LINK;
}*top, *np, *ptr;


void CreateNode(int val){
	np = (struct Node*) malloc(sizeof(struct Node));
    if(np ==  NULL){
        printf("MEMORY FULL!");
        exit(1);
    }
    np->DATA = val;
	np->LINK  = NULL;
}

void Psh_T(){//insertion at top
	if(top == NULL)
		top = np;
	else{
        np -> LINK = top;
        top = np;
	}
}

int Pop_T(){//deletion from top
	if(top == NULL){
		printf("Empty LL!!\n");
        top = NULL;
	}
	else if(top -> LINK == NULL){
		ptr = top;
		top = NULL;
    	free(ptr);
        printf("\nDeleted!");
	}
	else{
		ptr = top;
		top = top->LINK;
		free(ptr);
        return -1;
	}
}

void Display(){
    ptr = top;
	printf("\n| %d | <-- Top\n", ptr -> DATA);
	ptr = ptr -> LINK;
	while(ptr != NULL){
		printf("| %d |\n", ptr -> DATA);
		ptr = ptr -> LINK;
	}
	printf("   X");
}

int main(){
	top = NULL;
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
				Psh_T();
				printf("\nPushed!");
				Display();
				break;
			case 2:
				retn = Pop_T();
				if (retn == -1){
					printf("\nPopped!");
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
