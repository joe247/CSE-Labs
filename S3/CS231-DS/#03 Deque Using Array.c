#include<stdio.h>
#include<process.h>
#define SIZE 10

int deq[SIZE], F=-1, R=-1;


void insertFront(int x){
	
	int tmp, i;
	
	if(F == (R+1)%SIZE)
		printf("\nQueue Overflow\n\n");
	else if(F == -1){
        F = R = 0;
        deq[F]=x;
    }
    else if(R == SIZE-1){
    	printf("\nCannot insert from front!\n");
    	printf("Try deleting from REAR!\n\n");
	}
    else{
    	for(i=R;i>=F;i--){
		    tmp = deq[i];
        	deq[i+1]=tmp;
    	}
		deq[F]=x;
		R += 1;
		printf("%d inserted!\n\n", x);
	}
}

void deleteFront(){
	int x;
    if(F==-1)
        printf("\nQueue Underflow\n\n");
    else if(F==R){
        x = deq[F];
        deq[F]=0;
        F = R = -1;
        printf("%d deleted!\n", x);
    }
    else{
        x = deq[F];
        deq[F]=0;
        F += 1;
        printf("%d deleted!\n", x);
    }
}

void insertRear(int x){
	if(F == (R+1)%SIZE)
		printf("\nQueue Overflow\n\n");
	else if(R==-1){
        F = R = 0;
        deq[R]=x;
        printf("%d inserted!\n\n", x);
    }
    else if(R == SIZE-1){
    	printf("\nCannot insert from rear!\n");
    	printf("Try deleting from REAR!\n\n");
	}
    else{
        R += 1;
        deq[R]=x;
        printf("%d inserted!\n\n", x);
    }
}

void deleteRear(){
	int x;
    if(F==-1)
        printf("\nQueue Underflow\n\n");
    else if(F==R){
        x = deq[R];
        deq[R]=0;
        F = R = -1;
        printf("%d deleted!\n", x);
    }
    else{
        x = deq[R];
        deq[R]=0;
        R -= 1;
        printf("%d deleted!\n", x);
    }	
}

void disp(){
    int i;
    printf("FRONT: %d",F);
    printf("\nREAR: %d\n",R);
    for(i=0;i<SIZE;i++){
        if(deq[i]==0)
            printf("| __ |");
        else
            printf("| %d |", deq[i]);
    }
}

int main(){
	int ch, x;
	while(1){
		printf("1. InsertFront\n2. DeleteFront\n3. InsertRear\n4. DeleteRear\n5. Exit: ");
		scanf("%d", &ch);
		
		switch(ch){
			case 1:
				printf("Enter an element to insert: ");
				scanf("%d", &x);
				insertFront(x);
				disp();
				break;
			case 2:
				deleteFront();
				disp();
				break;
			case 3:
				printf("Enter an element to insert: ");
				scanf("%d", &x);
				insertRear(x);
				disp();
				break;
			case 4:
				deleteRear();
				disp();
				break;
			default:
				if(ch == 5){
					printf("Thanks!");
					exit(0);
			}
				else
					printf("Nothing!");
		}
		printf("\n\n");
	}
}
