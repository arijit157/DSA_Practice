#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *createList(struct node *start);
struct node *addToEmpty(struct node *start, int data);
struct node *addAtBeg(struct node *start, int data);
struct node *addAtEnd(struct node *start, int data);
struct node *addBefore(struct node *start, int item, int data);
struct node *addAfter(struct node *start, int item, int data);
struct node *delete (struct node *start, int data);
struct node *reverse(struct node *start);
void display(struct node *start);

int main()
{
    struct node *start = NULL;
    int choice, data, item;
    while (1)
    {
        printf("1. Create list\n");
        printf("2. Display\n");
        printf("3. Add to an empty list\n");
        printf("4. Add at the beginning\n");
        printf("5. Add at the end\n");
        printf("6. Add at before\n");
        printf("7. Add at after\n");
        printf("8. Delete node\n");
        printf("9. Reverse list\n");
        printf("Enter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
            start=createList(start);
            break;
            case 2:
            display(start);
            break;
            case 3:
            printf("Enter data: ");
            scanf("%d", &data);
            start=addToEmpty(start, data);
            break;
            case 4:
            printf("Enter data: ");
            scanf("%d", &data);
            start=addAtBeg(start, data);
            break;
            case 5:
            printf("Enter data: ");
            scanf("%d", &data);
            start=addAtEnd(start, data);
            break;
            case 6:
            printf("Enter data: ");
            scanf("%d", &data);
            printf("Enter the node data after which to insert: ");
            scanf("%d", &item);
            start=addAfter(start, data, item);
            break;
            case 7:
            printf("Enter data: ");
            scanf("%d", &data);
            printf("Enter the node data before which to insert: ");
            scanf("%d", &item);
            start=addBefore(start, data, item);
            break;
            case 8:
            printf("Enter node data: ");
            scanf("%d", &data);
            start=delete(start, data);
            break;
            case 9:
            start=reverse(start);
            break;
            default:
            printf("Invalid choice!!!\n");
        }
    }
    return 0;
}

void display(struct node *start)
{
    struct node *p=start;
    if(start==NULL)
    {
        printf("Empty list\n");
        return;
    }
    while(p!=NULL)
    {
        printf("%d\t", p->data);
        p=p->next;
    }
}

struct node *addToEmpty(struct node *start, int data)
{
    if(start==NULL)
    {
        struct node *tmp;
        tmp=(struct node *)malloc(sizeof(struct node));
        if(tmp==NULL)
        {
            printf("Unable to allocate memory\n");
            return start;
        }
        tmp->data=data;
        tmp->next=NULL;
        tmp->prev=NULL;
        start=tmp;
        return start;
    }
    else{
        printf("List is not empty\n");
        return start;
    }
}

struct node *addAtBeg(struct node *start, int data)
{
    struct node *tmp;
    tmp=(struct node *)malloc(sizeof(struct node));
    if(tmp==NULL)
    {
        printf("Unable to allocate memory\n");
        return start;
    }
    tmp->data=data;
    tmp->prev=NULL;
    tmp->next=start;
    start->prev=tmp;
    start=tmp;
    return start;
}

struct node *addAtEnd(struct node *start, int data)
{
    struct node *tmp, *p;
    tmp=(struct node *)malloc(sizeof(struct node));
    if(tmp==NULL)
    {
        printf("Unable to allocate memory\n");
        return start;
    }
    p=start;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    tmp->data=data;
    tmp->next=NULL;
    tmp->prev=p;
    p->next=tmp;
    return start; 
}

struct node *addBefore(struct node *start, int data, int item)
{
    struct node *tmp, *p;
    tmp=(struct node *)malloc(sizeof(struct node));
    if(tmp==NULL)
    {
        printf("Unable to allocate memory\n");
        return start;
    }
    tmp->data=data;
    if(start->data==item)
    {
        tmp->next=start;
        tmp->prev=NULL;
        start->prev=tmp;
        start=tmp;
        return start;
    }
    p=start;
    while(p!=NULL)
    {
        if(p->data==item)
        {
            tmp->next=p;
            p->prev=tmp;
            tmp->prev=p->prev;
            p->prev->next=tmp;
            return start;
        }
        p=p->next;
    }
    printf("Element not found\n");
    return start;
}

struct node *addAfter(struct node *start, int data, int item)
{
    struct node *tmp;
    tmp=(struct node *)malloc(sizeof(struct node));
    if(tmp==NULL)
    {
        printf("Unable to allocate memory\n");
        return start;
    }
    tmp->data=data;
    struct node *p=start;
    while(p!=NULL)
    {
        if(p->data==item)
        {
            tmp->prev=p;
            tmp->next=p->next;
            p->next=tmp;
            if(p->next!=NULL)   //when the pointer 'p' is pointing to the last node
                p->next->prev=tmp;
            return start;
        }
        p=p->next;
    }
    printf("Element not present\n");
    return start;
}

struct node *createList(struct node *start)
{
    int data, n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    if(n==0)
    {
        return start;
    }
    printf("Enter data: ");
    scanf("%d", &data);
    start=addToEmpty(start, data);
    for(int i=2; i<=n; i++)
    {
        printf("Enter data: ");
        scanf("%d", &data);
        start=addAtEnd(start, data);
    }
    return start;
}

struct node *delete(struct node *start, int data)
{
    struct node *tmp;
    if(start==NULL)
    {
        printf("List is empty\n");
        return start;
    }
    if(start->next==NULL)   //deletion of only node
    {
        if(start->data==data)
        {
            tmp=start;
            start=NULL;
            free(tmp);
            return start;
        }
        else{
            printf("%d not found\n", data);
            return start;
        }
    }
    if(start->data==data)  //deletion of first node
    {
        tmp=start;
        start=start->next;
        start->prev=NULL;
        free(start);
        return start;
    }
    tmp=start->next;
    while(tmp->next!=NULL)   //deletion in between nodes
    {
        if(tmp->data==data)
        {
            tmp->prev->next=tmp->next;
            tmp->next->prev=tmp->prev;
            free(tmp);
            return start;
        }
        tmp=tmp->next;
    }
    if(tmp->data==data)   //deletion of the last node
    {
        tmp->prev->next=NULL;
        free(tmp);
        return start;
    }
    printf("%d not found\n", data);
    return start;
}

struct node *reverse(struct node *start)
{
    struct node *p1, *p2;
    if(start==NULL)
    {
        printf("List is already empty\n");
        return start;
    }
    p1=start;
    p2=p1->next;
    p1->next=NULL;
    p1->prev=p2;
    while(p2!=NULL)
    {
        p2->prev=p2->next;
        p2->next=p1;
        p1=p2;
        p2=p2->prev;
    }
    start=p1;
    return start;
}