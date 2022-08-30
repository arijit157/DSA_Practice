#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int cqueue[MAX];
int front=-1, rear=-1;
void enqueue(int);
int dequeue();
int peek();
void display();
int isFull();
int isEmpty();
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
            enqueue(item);
            break;
            case 2:
            item=dequeue();
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

void enqueue(int item)
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
    if(rear==MAX-1)
    {
        rear=0;
    }
    else{
        rear++;
    }
    cqueue[rear]=item;
}

int dequeue()
{
    if(isEmpty())
    {
        printf("Queue underflow");
        exit(1);
    }
    int item=cqueue[front];
    if(front==MAX-1)
    {
        front=0;
    }
    if(front==rear)
    {
        front=rear=-1;
    }
    else
    {
        front++;
    }
    return item;
}

int isFull()
{
    if((front==0 && rear==MAX-1) || front==(rear+1))
    {
        return 1;
    }
    return 0;
}

int isEmpty()
{
    if(front==-1)
    {
        return 1;
    }
    return 0;
}

void display()
{
    int i=front;
    if(front<=rear)
    {
        while(i<=rear)
        {
            printf("%d\t", cqueue[i]);
            i++;
        }
    }
    else
    {
        while(i<=MAX-1)
        {
            printf("%d\t", cqueue[i]);
            i++;
        }
        i=0;
        while(i<=rear)
        {
            printf("%d\t", cqueue[i]);
            i++;
        }
    }
}

int peek()
{
    if(isEmpty())
    {
        printf("Queue Underflow\n");
        exit(1);
    }
    return cqueue[front];
}