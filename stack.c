#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int stack[MAX];
int top=-1;
void push(int);
int pop();
int peek();
void display();
int isEmpty();
int isFull();
int main()
{
    int choice, item;
    while(1)
    {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
            printf("Enter element: ");
            scanf("%d", &item);
            push(item);
            break;
            case 2:
            item=pop();
            printf("Popped item: %d\n", item);
            break;
            case 3:
            item=peek();
            printf("Top element: %d\n", item);
            break;
            case 4:
            display();
            break;
            case 5:
            exit(1);
            default:
            printf("Wrong choice!!!\n");
        }
    }
}

void push(int item)
{
    if(isFull())
    {
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stack[top]=item;
}

int pop()
{
    if(isEmpty())
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    int item=stack[top];
    top--;
    return item;
}

int peek()
{
    if(isEmpty())
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    int item=stack[top];
    return item;
}

int isEmpty()
{
    if(top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull()
{
    if(top==MAX-1)
    {
        return 1;
    }
    else{
        return 0;
    }
}

void display()
{
    int i;
    if(isEmpty())
    {
        printf("Stack is already empty\n");
        return;
    }
    for(i=top; i>=0; i--)
    {
        printf("%d\t", stack[i]);
    }
    printf("\n");
}