#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 20
int stack[MAX];
int top=-1;
void push(char);
char pop();
void display();
int main()
{
    char str[MAX];
    printf("Enter a string: ");
    gets(str);
    for(int i=0; i<strlen(str); i++)
    {
        push(str[i]);
    }
    for(int i=0; i<strlen(str); i++)
    {
        str[i]=pop();
    }
    puts(str);
    return 0;
}

void push(char item)
{
    if(top==MAX-1)
    {
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stack[top]=item;
}

char pop()
{
    if(top==-1)
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    char ch=stack[top];
    top--;
    return ch;
}