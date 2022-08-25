#include<stdio.h>
#include<stdlib.h>
#define MAX 10

struct employee{
    int id;
    char name[30];
    int age;
};

struct record{
    struct employee info;
    struct record *link;
};

void insert(struct employee emprec, struct record *table[]);
int search(int key, struct record *table[]);
void delete_record(int key, struct record *table[]);
void display(struct record *table[]);
int hash(int key);

int main()
{
    struct employee emprec;
    struct record *table[MAX];
    int choice, item, idx, key;
    for(int i=0; i<MAX; i++)
    {
        table[i]=NULL;
    }
    while(1)
    {
        printf("\n1.insert record\n");
        printf("2.search record\n");
        printf("3.delete record\n");
        printf("4.display record\n");
        printf("5.exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
            printf("insert employee informations:\n");
            scanf("%d %s %d", &emprec.id, emprec.name, &emprec.age);
            insert(emprec, table);
            break;

            case 2:
            printf("Enter a key to be searched: ");
            scanf("%d", &key);
            idx=search(key, table);
            if(idx==-1)
            {
                printf("Key not found\n");
            }
            else
            {
                printf("%d found at index %d", key, idx);
            }
            break;

            case 3:
            printf("Enter a key to be deleted: ");
            scanf("%d", &key);
            delete_record(key, table);
            break;

            case 4:
            display(table);
            break;

            case 5:
            exit(0);
        }
    }
    return 0;
}

void insert(struct employee emprec, struct record *table[])
{
    struct record *tmp;
    int h;
    int key=emprec.id;
    h=hash(key);
    if(search(key, table)!=-1)
    {
        printf("Duplicate key\n");
        return;
    }
    tmp=(struct record *)malloc(sizeof(struct record));
    tmp->link=table[h];
    table[h]=tmp;
}

int search(int key, struct record *table[])
{
    int h;
    h=hash(key);
    struct record *ptr;
    ptr=table[h];
    while(ptr!=NULL)
    {
        if(ptr->info.id==key)
        {
            return h;
        }
        ptr=ptr->link;
    }
    return -1; //if the entered key is not present in the hash table
}

int hash(int key)
{
    return (key%MAX); //modulo-division method
}

void delete_record(int key, struct record *table[])
{
    int h;
    struct record *tmp;
    struct record *ptr;
    h=hash(key);
    if(table[h]==NULL)
    {
        printf("Record not found\n");
        return;
    }
    if(table[h]->info.id==key)
    {
        tmp=table[h];
        table[h]=table[h]->link;
        free(tmp);
        return;
    }
    ptr=table[h];
    while(ptr->link!=NULL)
    {
        if(ptr->link->info.id==key)
        {
            tmp=ptr->link;
            ptr->link=tmp->link;
            free(tmp);
        }
        ptr=ptr->link;
    }
}

void display(struct record *table[])
{
    struct record *ptr;
    for(int i=0; i<MAX; i++)
    {
        if(table[i]!=NULL)
        {
            ptr=table[i];
            while(ptr!=NULL)
            {
                printf("%d %s %d\n", ptr->info.id, ptr->info.name, ptr->info.age);
                ptr=ptr->link;
            }
        }
    }
}