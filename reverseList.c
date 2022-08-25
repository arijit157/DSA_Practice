#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};
struct node *createList(struct node *start);
struct node *insertAtBeg(struct node *start, int data);
struct node *insertAtEnd(struct node *start, int data);
struct node *reverse(struct node *start);
void display(struct node *start);
int main()
{
    struct node *start=NULL;
    start=createList(start);
    display(start);
    start=reverse(start);
    printf("\nReverse is:\n");
    display(start);
    return 0;
}
struct node *createList(struct node *start)
{
    int n, data;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the data of the first node: ");
    scanf("%d", &data);
    start=insertAtBeg(start, data);
    for(int i=2; i<=n; i++)
    {
        printf("insert data for node %d: ",i);
        scanf("%d", &data);
        start=insertAtEnd(start, data);
    }
    return start;
}
struct node *reverse(struct node *start){
    struct node *prev,*ptr, *next;
    prev=NULL;
    ptr=start;
    while(ptr!=NULL)
    {
        next=ptr->link;
        ptr->link=prev;
        prev=ptr;
        ptr=next;
    }
    start=prev;
    return start;
}
struct node *insertAtBeg(struct node *start, int data)
{
    struct node *tmp;
    tmp=(struct node *)malloc(sizeof(struct node));
    if(tmp==NULL)
    {
        printf("Unable to allocate memory");
        exit(1);
    }
    tmp->data=data;
    tmp->link=start;
    start=tmp;
    return start;
}

struct node *insertAtEnd(struct node *start, int data)
{
    struct node *tmp, *ptr;
    tmp=(struct node *)malloc(sizeof(struct node));
    if(tmp==NULL)
    {
        printf("Unable to allocate memory");
        return start;
    }
    tmp->data=data;
    tmp->link=NULL;
    ptr=start;
    while(ptr->link!=NULL)
    {
        ptr=ptr->link;
    }
    ptr->link=tmp;
    return start;
}

void display(struct node *start)
{
    struct node *ptr;
    ptr=start;
    while(start==NULL)
    {
        printf("List is empty\n");
        exit(1);
    }
    while(ptr!=NULL)
    {
        printf("%d\t", ptr->data);
        ptr=ptr->link;
    }
}