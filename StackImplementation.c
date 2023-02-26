//This is the program to implement Stack

#include<stdio.h>


struct stack
{
	int arr[5];   //Initialize Stack
	int top;
};

void init(struct stack *t) //Initialize top pointer
{
	t->top = -1;
}

void push(struct stack *t)   //Function for Push operation in Stack
{
	int b;
	if (t->top==4)
	{
		printf("\nStack Overflow.");
		
	}
	else
	{
		printf("\nEnter data You Want to enter : ");
		scanf("%d",&b);
		t->top++;
		t->arr[t->top] = b;
	}
}

int pop(struct stack *t) //Function for Pop Operation in Stack
{
	int x;
	if (t->top == -1)
	{
		printf("\nStack Undreflow.");
		return 0;
	}
	else
	{
		x = t->arr[t->top];
		t->top--;
		
	}
	return x;
}


void peep(struct stack *t)  //Function for Peep Operation in Stack
{
	int x;
	printf("\nEnter Position You Want to enter : ");
	scanf("%d",&x);
    int a = t->top - x;	
	int pos_sta = t->top + 1 - x;
	if (a < -1)
	{
		printf("\nElement doesn't Find.");
	}
	else
	{
		printf("\nAt Postion %d element is %d",x,t->arr[pos_sta]);
	}
}


void display(struct stack *t)  //Function for display all data of stack
{
	int r = t->top;
	int i;
	printf("\nDisplaying Stack Element : ");
	for (i=r;i>=0;i--)
	{
		printf("\n\n%d",t->arr[i]);
	}
}



int main()
{
	int op;
	struct stack s;
	init(&s);
	char ans;
	do
	{
	printf("\nThis are the Operation for stack.");
	printf("\n1.Push");
	printf("\n2.Pop");
	printf("\n3.Peep");
	printf("\n4.Display");
	printf("\n5.Exit");
	printf("\nChoose any Operation for Stack : ");
	scanf("%d",&op);
	
	switch(op)
	{
		case 1:
			push(&s);
			break;
		case 2:
			pop(&s);
			break;
		case 3:
			peep(&s);
			break;
		case 4:
			display(&s);
			break;
		case 5:
		    return 0;
		default :
			break;
	}
    } while(1>0);
	
	return 0;
}
