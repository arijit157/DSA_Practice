#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};
struct node *createList(struct node *start); //done
struct node *insertAtBeg(struct node *start, int data); //done
struct node *insertAtEnd(struct node *start, int data); //done
struct node *insertAfter(struct node *start, int data, int item); //done
struct node *insertBefore(struct node *start, int data, int item); //done
struct node *insertAtPos(struct node *start, int data, int pos); //done
struct node *deleteAtFirst(struct node *start); //done
// struct node *deleteOnly(struct node *start);
struct node *reverse(struct node *start); //done
void display(struct node *start); //done
void count(struct node *start); //done
void search(struct node *start, int data); //done
int main()
{
    struct node *start=NULL;
    int choice, data, item, pos;
    while(1)
    {
        printf("1. \ncreate list\n");
        printf("2. insert at the beginning\n");
        printf("3. insert at the end\n");
        printf("4. insert after a node\n");
        printf("5. insert before a node\n");
        printf("6. insert at any position\n");
        printf("7. delete a node\n");
        printf("8. reverse a node\n");
        printf("9. display the list\n");
        printf("10. count the no. of list\n");
        printf("11. search a node\n");
        printf("12. exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
            start=createList(start);
            break;
            case 2:
            int data;
            printf("Enter data: ");
            scanf("%d", &data);
            start=insertAtBeg(start, data);
            break;
            case 3:
            printf("Enter data: ");
            scanf("%d", &data);
            start=insertAtEnd(start, data);
            break;
            case 4:
            printf("Enter data: ");
            scanf("%d", &data);
            printf("Enter the target node: ");
            scanf("%d", &item);
            start=insertAfter(start, data, item);
            break;
            case 5:
            printf("Enter data: ");
            scanf("%d", &data);
            printf("Enter the target node: ");
            scanf("%d", &item);
            start=insertBefore(start, data, item);
            break;
            case 6:
            printf("Enter data: ");
            scanf("%d", &data);
            printf("Enter the position: ");
            scanf("%d", &pos);
            start=insertAtPos(start, data, pos);
            break;
            case 7:
            printf("Enter node data: ");
            scanf("%d", &data);
            start=deleteAtFirst(start);
            break;
            case 8:
            start=reverse(start);
            break;
            case 9:
            display(start);
            break;
            case 10:
            count(start);
            break;
            case 11:
            printf("Enter a node data: ");
            scanf("%d", &data);
            search(start, data);
            break;
            case 12:
            exit(0);
            break;
            default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}

struct node *insertAtBeg(struct node *start, int data){
    struct node *tmp=(struct node *)malloc(sizeof(struct node));
    if(tmp==NULL){
        printf("Sorry! unable to allocate memory");
        return start;
    }
    tmp->data=data;
    tmp->link=start;
    start=tmp;
    return start;
}

struct node *insertAtEnd(struct node *start, int data){
    struct node *tmp=(struct node *)malloc(sizeof(struct node));
    struct node *ptr=start;
    if(tmp==NULL){
        printf("Sorry! unable to allocate memory");
        return start;
    }
    tmp->data=data;
    tmp->link=NULL;
    while(ptr->link!=NULL){
        ptr=ptr->link;
    }
    ptr->link=tmp;
    return start;
}

struct node *createList(struct node *start){
    //struct node *tmp;
    int n, data;
    printf("Enter the no. of nodes: ");
    scanf("%d", &n);
    printf("Enter the data of the first node: ");
    scanf("%d", &data);
    start=insertAtBeg(start, data);
    for(int i=2;i<=n; i++){
        printf("Enter data: ");
        scanf("%d", &data);
        start=insertAtEnd(start, data);
    }
    return start;
}

void display(struct node *start){
    struct node *ptr=start;
    if(start==NULL){
        printf("List is already empty\n");
        return;
    }
    while(ptr!=NULL){
        printf("%d -> ", ptr->data);
        ptr=ptr->link;
    }
}

void count(struct node *start){
    int count=0;
    struct node *tmp;
    if(start==NULL){
        printf("List is empty\n");
        return;
    }
    tmp=start;
    while(tmp!=NULL){
        count++;
        tmp=tmp->link;
    }
    printf("Total nodes: %d\n", count);
}

void search(struct node *start, int data){
    struct node *tmp;
    int pos;
    if(start==NULL){
        printf("List is empty\n");
        return;
    }
    tmp=start;
    while(tmp!=NULL){
        if(tmp->data == data){
            pos++;
            printf("Element found at position= %d\n", pos);
            return;
        }
        tmp=tmp->link;
    }
    printf("Element not found\n");
}

struct node *insertAfter(struct node *start, int data, int item){
    struct node *tmp, *ptr;
    if(start==NULL){
        printf("List is empty");
        return start;
    }
    tmp=start;
    ptr=(struct node*)malloc(sizeof(struct node));
    if(ptr==NULL){
        printf("Unable to create node\n");
        exit(1);
    }
    ptr->data=data;
    ptr->link=NULL;
    while(tmp!=NULL){
        if(tmp->data == item){
            ptr->link=tmp->link;
            tmp->link=ptr;
        }
        tmp=tmp->link;
    }
    printf("%d not present in the list\n", item);
    return start;
}

struct node *insertBefore(struct node *start, int data, int item){
    struct node *p, *ptr;
    if(start==NULL){
        printf("List is empty\n");
        return start;
    }
    ptr=(struct node *)malloc(sizeof(struct node));
    if(ptr==NULL){
        printf("Unable to create node\n");
        return start;
    }
    ptr->data=data;
    if(item==start->data){
        //insertAtBeg(start, data);
    }
    p=start;
    while(p->link!=NULL){
        if(p->link->data == item){
            ptr->link=p->link;
            p->link=ptr;
            return start;
        }
        p=p->link;
    }
    printf("%d not present in the list\n", item);
    return start;
}

struct node *reverse(struct node *start)  //again go through the book
{
    struct node *prev, *ptr, *next;
    if(start==NULL){
        printf("List is empty\n");
        return start;
    }
    prev=NULL;
    ptr=start;
    while(ptr!=NULL){
        next=ptr->link;  //we have to traverse the 'next' so we have to write it inside the  loop
        ptr->link=prev;   //connection loss and connection re-build
        prev=ptr;
        ptr=next;
    }
    start=prev;
    return start;
}

struct node *insertAtPos(struct node *start, int data, int pos){
    struct node *p, *tmp;
    if(start==NULL){
        printf("List is empty\n");
        return start;
    }
    tmp=(struct node *)malloc(sizeof(struct node));
    if(tmp==NULL){
        printf("Unable to create node\n");
        exit(1);
    }
    tmp->data=data;
    tmp->link=NULL;
    if(pos==1){
        tmp->link=start;
        start=tmp;
        return start;
    }
    p=start;
    for(int i=1; i<(pos-1) && p!=NULL; i++){
        p=p->link;
    }
    if(p==NULL){
        printf("There are less than %d element\n", pos);
    }
    else{
        tmp->link=p->link;
        p->link=tmp;
    }
    return start;
}

struct node *deleteAtFirst(struct node *start){
    if(start==NULL){
       printf("List is already empty\n");
       return start;
    }
    struct node *tmp=start;
    start=start->link;
    free(tmp);
    return start;
}