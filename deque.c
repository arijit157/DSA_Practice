#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int deque[MAX];
int front=-1, rear=-1;
void insert_front(int);
void insert_rear(int);
int delete_front();
int delete_rear();
int peek();
void display();
int isFull();
int isEmpty();

int main()
{
    int choice, item;
    while(1)
    {
        printf("\n1. Insert at rear\n");
        printf("2. Insert at front\n");
        printf("3. Delete from rear\n");
        printf("4. Delete from front\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
            printf("Enter element at rear: ");
            scanf("%d", &item);
            insert_rear(item);
            break;
            case 2:
            printf("Enter element at front: ");
            scanf("%d", &item);
            insert_front(item);
            break;
            case 3:
            item=delete_rear();
            printf("%d\n", item);
            break;
            case 4:
            item=delete_front();
            printf("%d\n", item);
            break;
            case 5:
            display();
            break;
            case 6:
            exit(1);
            default:
            printf("Wrong choice!!!\n");
        }
        printf("Front = %d\tRear = %d\n", front, rear);
        display();
    }
    return 0;
}

void insert_front(int item)
{
    if(isFull())
    {
        printf("Overflow\n");
        return;
    }
    if(front==-1)
    {
        front=0;
        rear=0;
    }
    else if(front==0)
    {
        front=MAX-1;
    }
    else{
        front--;
    }
    deque[front]=item;
}

void insert_rear(int item)
{
    if(isFull())
    {
        printf("Overflow\n");
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
    else
    {
        rear++;
    }
    deque[rear]=item;
}

int delete_front()
{
    if(isEmpty())
    {
        printf("Underflow\n");
        exit(1);
    }
    int item=deque[front];
    if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else if(front==MAX-1)
    {
        front=0;
    }
    else
    {
        front++;
    }
    return item;
}

int delete_rear()
{
    if(isEmpty())
    {
        printf("Underflow\n");
        exit(1);
    }
    int item=deque[rear];
    if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else if(rear==MAX-1)
    {
        rear=0;
    }
    else{
        rear--;
    }
    return item;
}

int isEmpty()
{
    if(front==-1)
    {
        return 1;
    }
    return 0;
}

int isFull()
{
    if((front==0 && rear==MAX-1) || front==(rear+1))
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
            printf("%d\t", deque[i]);
            i++;
        }
    }
    else{
        while(i<=MAX-1)
        {
            printf("%d\t", deque[i]);
            i++;
        }
        i=0;
        while(i<=rear)
        {
            printf("%d\t", deque[i]);
            i++;
        }
    }
}