#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

int cque[SIZE], F=-1, R=-1;

void c_insert(int x){
    if(F == (R+1)%SIZE)
		printf("Queue Overflow\n");
	else if(R==-1){
        F = R = 0;
        cque[R]=x;
        printf("%d inserted!\n\n", x);
    }
    else{
        R = (R+1)%SIZE;
        cque[R]=x;
        printf("%d inserted!\n\n", x);
    }
}

int c_delete(){
    int x;
    if(F==-1)
        printf("Queue Underflow\n\n");
    else if(F==R){
        x = cque[F];
        printf("%d deleted!\n", x);
        cque[F] = 0;
        F = R = -1;
    }
    else{
        x = cque[F];
        printf("%d deleted!\n\n", x);
        cque[F] = 0;
        F = (F+1)%SIZE;
    }
    return x;
}


void disp(){
    int i;
    printf("FRONT: %d",F);
    printf("\nREAR: %d\n",R);

	for(i=0;i<SIZE;i++){
        if(cque[i]==0)
            printf("| __ |");
        else
            printf("| %d |", cque[i]);
    }
}

int main(){
	int ch, x;
	while(1){
		printf("1. Insert\n2. Delete\n3. Exit: ");
		scanf("%d", &ch);
		switch(ch){
			case 1:
				printf("Enter an element to insert: ");
				scanf("%d", &x);
				c_insert(x);
                disp();
				break;
			case 2:
				c_delete();
                disp();
				break;
			default:
				if(ch == 3){
					printf("Thanks!\n");
                    exit(0);
                }
				else
					printf("Nothing!\n");
		}
		printf("\n");
	}
	return 0;
}
