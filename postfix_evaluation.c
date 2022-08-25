#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define TAB '\t'
#define BLANK ' '
#define MAX 50
char infix_array[MAX], postfix_array[MAX];
long int stack[MAX];
void push(long int);
long int pop();
void infix_to_postfix();
long int eval_postfix();
int whitespace(char);
int priority(char);
int isEmpty();
int isFull();
int top;
int main()
{
	int top=-1;
	printf("Enter infix expression: ");
	gets(infix_array);
	infix_to_postfix();
	int val=eval_postfix();
	printf("Value of the postfix expression is: %d\n", val);
	return 0;
}
void infix_to_postfix()
{
	char symbol, next;
	int i, p=0;
	for(i=0;i<strlen(infix_array); i++)
	{
		symbol=infix_array[i];
		if(!whitespace(symbol))
		{
			switch(symbol)
			{
				case '(':
					push(symbol);
					break;
				case ')':
					while((next=pop())!='(')
					{
						postfix_array[p++]=next;
					}
					break;
				case '+':
				case '-':
				case '*':
				case '/':
				case '^':
					while(!isEmpty() && priority(stack[top])>=priority(symbol))
					{
						//top++;
						postfix_array[p++]=pop();
					}
				    push(symbol);
					break;
				default:
				//top++;
				postfix_array[p++]=symbol;	
			}
		}
	}
	while(!isEmpty())
	{
		postfix_array[p++]=pop();
	}
	postfix_array[p]='\0';
}

int priority(char symbol)
{
	switch(symbol)
	{
		case '^':
			return 3;
			break;
		case '*':
		case '/':
			return 2;
			break;
		case '+':
		case '-':
			return 1;
			break;
		default:
			return 0;
	}
}

void push(long int symbol)
{
	if(isFull())
	{
		printf("Stack overflow\n");
		exit(1);
	}
	top++;
	stack[top]=symbol;
}

long int pop()
{
	if(isEmpty())
	{
		printf("Stack underflow\n");
		exit(1);
	}
	long int item=stack[top];
	top--;
	return item;
}

int isEmpty()
{
	if(top==-1)
	{
		return 1;
	}
	else{
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

int whitespace(char symbol)
{
	if(symbol==TAB || symbol==BLANK)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

long int eval_postfix()
{
	long int a,b,temp;
	int i;
	for(i=0; i<=strlen(postfix_array); i++)
	{
		if(postfix_array[i]>='0' && postfix_array[i]<='9')
		{
			push(postfix_array[i]-'0');
		}
		else
		{
			a=pop();
			b=pop();
			switch(postfix_array[i])
			{
				case '+':
					temp=b+a;
					push(temp);
					break;
				case '-':
					temp=b-a;
					push(temp);
					break;
				case '*':
					temp=b*a;
					push(temp);
					break;
				case '/':
					temp=b/a;
					push(temp);
					break;
				case '^':
					temp=pow(b,a);
					push(temp);
					break;
				default:
					printf("Invalid operator\n");
			}
		}
	}
	int result=pop();
	return result;
}
