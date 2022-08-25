#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int queue[MAX];
void push(int);
int pop();
int peek();
void display();
int isEmpty();
int isFull();
int front=-1, rear=-1;
int main()
{
    int choice, item;
    while(1)
    {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
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
    return 0;
}

void push(int item)
{
    if(isFull())
    {
        printf("Queue overflow\n");
        return;
    }
    if(front==-1)
    {
        front=0;
    }
    rear++;
    queue[rear]=item;
}

int pop()
{
    if(isEmpty())
    {
        printf("Queue underflow\n");
        exit(1);
    }
    int item=queue[front];
    front++;
    return item;
}

int peek()
{
    if(isEmpty())
    {
        printf("Queue underflow\n");
        exit(1);
    }
    return queue[front];
}

int isFull()
{
    if(rear==MAX-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty()
{
    if(front==-1 || front==(rear+1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void display()
{
    int i;
    if(isEmpty())
    {
        printf("Queue is empty\n");
        return;
    }
    for(i=front;i<=rear; i++)
    {
        printf("%d\t", queue[i]);
    }
    printf("\n");
}