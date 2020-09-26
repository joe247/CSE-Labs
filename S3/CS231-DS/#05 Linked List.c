/**
 * Author: Jovial
 * S3 CSE
 * IES17CS016
 * Linked Lists
 */
#include<stdio.h>
#include<stdlib.h>

struct Node{
	int DATA;
	struct Node *LINK;
}*start, *np, *rear, *ptr, *tmp;

int i=0;

void CreateNode(int val){
    //np = new Node;
	np = (struct Node*) malloc(sizeof(struct Node)); //malloc() returns a pointer of type void which can be casted into pointer of any form;
	np->DATA = val;
	np->LINK  = NULL;
    if(np ==  NULL){
        printf("MEMORY FULL!");
        exit(1);
    }
    i++;
}

void In_F(){//insertion at front
	if(start == NULL)
		start = rear = np;
	else{
        np -> LINK = start;
        start = np;
	}
}

void In_R(){//insertion at rear
	if(start == NULL)
		start = rear = np;
	else{
		rear -> LINK = np;
		rear = np;
		rear -> LINK = NULL;
	}
}

void In_A(int pos){//insert anywhere 
	if(start == NULL)
		start = rear = np;
	else{
        int siz=1;
        ptr = start;
        while(siz < pos){
            siz++;
            ptr = ptr -> LINK;
        }
        np -> LINK = ptr;
        ptr = start;
        siz=1;
        while(siz < pos-1){
            siz++;
            ptr = ptr -> LINK;
        }
        ptr -> LINK = np;
	}
}

int De_F(){//deletion at front
	if(start == NULL){
		printf("Empty LL!!\n");
        start = rear = NULL;
        i=0;
		return -1;
	}
	else if(start == rear){
		ptr = start;
		start = rear = NULL;
    free(ptr);//delete ptr
        printf("\nDeleted!");
        i--;
		return -1;
	}
	else{
		ptr = start;
		start = start->LINK;
		free(ptr);//delete ptr;
        i--;
	}
}

int De_R(){//deletion at rear
	if(start == NULL){
		printf("Empty LL!!\n");
        start = rear = NULL;
        i=0;
		return -1;
	}
	else if(start == rear){
		ptr = start;
		start = rear = NULL;
		free(ptr);//delete ptr
        printf("\nDeleted!");
        i--;
		return -1;
	}
	else{
        int siz = 1;
        ptr = start;
        while(siz < i-1){
            siz++;
            ptr = ptr -> LINK;
        }
        free(rear);//delete ptr
		rear = ptr;
        rear -> LINK = NULL;
        i--;
	}
}

int De_A(int pos){//delete from anywhere
	if(start == rear){
		ptr = start;
		start = rear = NULL;
		free(ptr);//delete ptr
        printf("\nDeleted!");
        i--;
		return -1;
	}
	else{
        int siz = 1;
        ptr = start;
        while(siz < pos){
            ptr = ptr -> LINK;
            siz++;
        }
        tmp = ptr -> LINK;
        free(ptr);//delete ptr
        siz = 1;
        ptr = start;
        while(siz < pos-1){
            siz++;
            ptr = ptr -> LINK;
            
        }
        ptr -> LINK = tmp;
        i--;
        printf("\nDeleted!");
	}
}

void Display(){
    ptr = start;
	printf("\n\n");
	while(ptr != NULL){
		printf("| %d | --> ", ptr -> DATA);
		ptr = ptr -> LINK;
	}
	printf(" X");
}

int main(){
	start = rear = NULL;
	int ch, val, dr, pos, ctr, flg;
	while(1){
		printf("1. Insert at front:\n2. Insert at rear:\
		\n3. Delete from front:\n4. Delete from rear:\
		\n5. Insert at a position:\n6. Delete from anywhere:\
		\n7. Exit: ");
		scanf("%d", &ch);
		switch (ch){
            case 1:
				printf("A Number: ");
				scanf("%d", &val);
				CreateNode(val);
				In_F();
				printf("\nInserted!");
				Display();
				break;
			case 2:
				printf("A Number: ");
				scanf("%d", &val);
				CreateNode(val);
				In_R();
				printf("\nInserted!");
				Display();
				break;
			case 3:
				dr = De_F();
				if (dr != -1){
					printf("\nDeleted!");
					Display();
				}
				break;
            case 4:
				dr = De_R();
				if (dr != -1){
					printf("\nDeleted!");
					Display();
				}
				break;
            case 5:
                if(start == NULL){
                    printf("\n!! Can insert only as first Node!!\n");
                    printf("A Number: ");
                    scanf("%d", &val);
                    CreateNode(val);
                    In_F();
                    printf("\nInserted!");
                    Display();
                }
                else{
                    printf("A Number: ");
                    scanf("%d", &val);
                    printf("Insert @: ");
                    scanf("%d", &pos);
                    if(pos>0 & pos<=i){
                        CreateNode(val);
                        if(pos == 1)
                            In_F();
                        else if(pos == i)
                            In_R();
                        else{
                            In_A(pos);
                        }
                        printf("\nInserted!");
                        Display();
                    }
                    else
                        printf("Invalid Location!");
                }
				break;
            case 6:
                if(start == NULL){
                    printf("\nEmpty LL!!");
                }
                else{
                    printf("!! Deletes only the first match !! \n");
                    printf("A data to delete: ");
                    scanf("%d", &val);
                    ctr = 1; flg = 0;
                    ptr = start;
                    while((ptr->LINK) != NULL){
                        if((ptr -> DATA) == val){
                            flg = 1;
                            break;
                        }
                        ctr++;
                        ptr = ptr -> LINK;
                        if(((ptr -> DATA) == val) && ((ptr->LINK) == NULL)){
                            flg = 1;
                            break;
                        }
                    }
                    if(flg == 0)
                        printf("\nNo data matched!");
                    else{
                        if(ctr == 1)
                            De_F();
                        else if(ctr == i)
                            De_R();
                        else De_A(ctr);
                        
                        Display();
                    }
                }
				break;
			case 7:
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
