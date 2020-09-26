/**
 * Author: Jovial
 * S3 CSE
 * IES17CS016
 * Queue Using Array
 */

#include<stdio.h>

#define maxSize 5

int queue[maxSize], front=-1, rear=-1;

void Sel();
void Enq();
void Deq();
void disp();
void mkNULL();

void main(){
    Sel();
    printf("\n");
}

void Sel(){
    int sh;
	printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Make NULL\n5. Queue Length\n6. Exit: ");
    scanf("%d",&sh);
    printf("\n");
	switch(sh){
		case 1:
            Enq();
			printf("\n\n******************************\n\n");
			Sel();
			break;
		case 2:
            Deq();
			printf("\n\n******************************\n\n");
			Sel();
			break;
		case 3:
			disp();
			printf("\n\n******************************\n\n");
			Sel();
			break;
		case 4:
            mkNULL();
			printf("\n\n******************************\n\n");
			Sel();
			break;
        case 5:
            if((front > rear) || (front == -1 && rear == -1))
                printf("Empty Queue!");
            else
                printf("Length: %d",rear-front+1);
            printf("\n\n******************************\n\n");
			Sel();
            break;
		case 6:
			printf("Thanks!");
			break;
		default:
			printf("Invalid!");
			printf("\n\n******************************\n\n");
			Sel();
	}
	printf("\n");
}

void Enq(){
    if(front == 0 && rear == maxSize-1)
        printf("Queue Overflow!");
    else{
        int eq;
        printf("Enter a number: ");
        scanf("%d", &eq);
        if(front == -1){
            front=rear=0;
            queue[rear]=eq;
            printf("Inserted %d!",eq);
        }
        else{
            rear+=1;
            queue[rear]=eq;
            printf("Inserted %d!",eq);
        }
    }
}

void Deq(){
    if((front > rear) || (front == -1 && rear == -1))
        printf("Queue Underflow!");
    else{
        int val;
        val = queue[front];
        front++;
        printf("Deleted %d!",val);
    }
}

void disp(){
    printf("Front: %d Rear: %d\n", front+1, rear+1);
    if((front > rear) || (front == -1 && rear == -1))
        printf("Queue is Empty!");
    else{
        int i;
        printf("Queue: ");
        for(i=front;i<=rear;i++)
            printf("| %d ",queue[i]);
    }
}

void mkNULL(){
    if((front > rear) || (front == -1 && rear == -1))
        printf("Queue is Empty!");
    else{
        int i;
        front=rear=-1;
        for(i=0;i<maxSize;i++)
            queue[i]=0;
        printf("Queue made Empty!");
    }
}
