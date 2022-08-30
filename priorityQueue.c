#include<stdio.h>
#include<stdlib.h>
struct node{
    int priority;
    int info;
    struct node *link;
}*start=NULL;
void insert(int, int);
int del();
int isEmpty();
void display();
int main()
{
    //struct node *start=NULL;
    int item, choice, item_priority;
    while(1)
    {
        printf("\n1. Insert element\n");
        printf("2. Delete element\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
            printf("Enter the element: ");
            scanf("%d", &item);
            printf("Enter the priority: ");
            scanf("%d", &item_priority);
            insert(item, item_priority);
            break;
            case 2:
            item=del();
            printf("Deleted: %d\n", item);
            break;
            case 3:
            display();
            break;
            case 4:
            exit(1);
            default:
            printf("Wrong choice!!!\n");
        }
    }
    return 0;
}

void insert(int item, int item_priority)
{
    struct node *tmp=(struct node *)malloc(sizeof(struct node));
    struct node *p;
    if(tmp==NULL)
    {
        printf("Memory not available\n");
        return;
    }
    tmp->info=item;
    tmp->priority=item_priority;
    if(isEmpty() || start->priority>item_priority)
    {
        tmp->link=start;
        start=tmp;
    }
    else{
        p=start;
        while(p->link!=NULL && p->link->priority<item_priority)
        {
            p=p->link;
        }
        tmp->link=p->link;
        p->link=tmp;
    }
}

int del()
{
    struct node *tmp;
    tmp=start;
    if(tmp==NULL)
    {
        printf("Queue Underflow\n");
        exit(1);
    }
    int item=tmp->info;
    start=start->link;
    free(tmp);
    return item;
}

int isEmpty()
{
    if(start==NULL)
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
    struct node *tmp;
    tmp=start;
    if(tmp==NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    while(tmp!=NULL)
    {
        printf("%d\t%d\n", tmp->priority, tmp->info);
        tmp=tmp->link;
    }
}