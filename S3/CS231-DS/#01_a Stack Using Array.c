/**
 * Author: Jovial
 * S3 CSE
 * IES17CS016
 * Stack Using Array
 */
#include<stdio.h>

int stack[5], top=-1, maxSize=5;

void Push();
void Pop();
void disp();
void disTop();
void mkNull();

void main(){
    int sh;
    char ch;
    printf("1. Push\n2. Pop\n3. Display\n4. Display TOP Value\n5. Make NULL\n6. Exit: ");
    scanf("%d",&sh);
    printf("\n");
    switch(sh){
        case 1:
            Push();
            printf("\n\n*******************************************************\n\n");
            main();
            break;
        case 2:
            Pop();
            printf("\n\n*******************************************************\n\n");
            main();
            break;
        case 3:
            disp();
            printf("\n\n*******************************************************\n\n");
            main();
            break;
        case 4:
            disTop();
            printf("\n\n*******************************************************\n\n");
            main();
            break;
        case 5:
            mkNull();
            printf("\n\n*******************************************************\n\n");
            main();
            break;
        case 6:
            printf("Thanks!");
            break;
        default:
            printf("Invalid Option!");
            printf("\n\n*******************************************************\n\n");
            main();
    }
    printf("\n");
}

void Push(){
    if(top == maxSize-1)
        printf("StackOverFlow!");
    else{
        int psh;
        printf("Enter a number: ");
        scanf("%d",&psh);
        top++;
        stack[top]=psh;
        printf("Pushed %d!", psh);
    }
}

void Pop(){
    if(top == -1)
        printf("StackUnderFlow!");
    else{
        int ppd;
        ppd=stack[top];
        top--;
        printf("Popped %d!", ppd);
    }
}

void disp(){
    if(top == -1)
        printf("Empty Stack!");
    else{
        int i;
        printf("Stack:\t");
        for(i=0;i<=top;i++)
            printf("%d ",stack[i]);
    }
}

void disTop(){
    if(top == -1)
        printf("Empty Stack!");
    else
        printf("Top Value:\t%d ", stack[top]);
}

void mkNull(){
    if(top == -1)
        printf("Empty Stack!");
    else{
        int i;
        top=-1;
        for(i=0;i<maxSize;i++)
            stack[i]=0;
        printf("Stack Emptied!");
    }
}
