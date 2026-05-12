// Stack Array code
#include <stdio.h>
#include <stdlib.h>
#define MAX 20
int array[MAX]={0};
static int top;

void Initialize_Stack();
int Is_Stack_Full();
void push(int data);
int Is_Stack_Empty();
int pop(void);
int peek();
void display_stack();
int stack_size();


int main() {
    int data, selection;
    Initialize_Stack();
    
    while(1)
    {
        printf("1.Push an data on the stack\n\r");
		printf("2.Pop an data from the stack\n\r");
		printf("3.Display the top data\n\r");
		printf("4.Display all stack data\n\r");
		printf("5.Display size of the stack\n\r"); 
		printf("6.Exit\n\r");
		printf("Enter an option : ");
		scanf("%d",&selection);
		
		if(selection==6)
		    break;
		    
		switch(selection)
		{
		 case 1 : { printf("Enter the element to be pushed : ");
			        scanf("%d",&data);
		        	push(data);
			        break;
		          }
		 case 2 : { data = pop();
		            printf("Popped data from stack : %d\n\r",data);
			        break;
		          }	
		 case 3 : { data = peek();
		            printf("Data at the top is :%d\n\r",data);
			        break;
		          }	
		 case 4 : { display_stack();
			        break;
		          }	
		 case 5 : { data = stack_size();
		            printf("Stack Size : %d\n\r",data);
			        break;
		          }			          
        }
    }
    return 0;
}

void Initialize_Stack()
{
	top=-1; 
}

int Is_Stack_Full()
{
	if(top==MAX-1)
		return 1;
	else
		return 0;
}

void push(int data)
{
	if(Is_Stack_Full())
	{
		printf("Stack Overflow\n\r");
		return;
	}
	top=top+1;
	array[top]=data;
}

int Is_Stack_Empty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}
int pop(void)
{
    int data;
	if(Is_Stack_Empty())
	{
		printf("Stack Underflow\n\r");
		exit(1);
	}
	data = array[top];
	top=top-1;
	return data;
}
int peek()
{
	if(Is_Stack_Empty())
	{
		printf("Stack Underflow\n\r");
		exit(1);
	}
	return array[top];
}


void display_stack()
{
	int i;
	
	if(Is_Stack_Empty())
	{
		printf("Stack is empty\n\r");
		return;
	}
	else
	{
    printf("Stack is : \n\r");
	for(i=top; i>=0; i--)
	    printf(" %d\n", array[i]);
	printf("\n\r");
	printf("top=%d\n",top);
	}

}

int stack_size()
{
	return top+1;
}
