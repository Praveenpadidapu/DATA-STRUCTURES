#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 100
char infix[max];
char postfix[max], stack[max];
int top = -1;
void push (char x);
void
push (char x)
{
  if (top == max - 1)
	{
	  printf ("STACK OVERFLOW");
	  exit (1);
	}
  top++;
  stack[top] = x;
}

char pop ();
char pop ()
{
  int temp;
  temp = stack[top];
  top--;
  return temp;
}

int order (char x);
int
order (char x)
{
  if (x == '+' || x == '-')
	{
	  return 1;
	}
  else if (x == '*' || x == '/')
	{
	  return 2;
	}
  else if (x == '^')
	{
	  return 3;
	}
  else
	return 0;
}


void display ();
void display ()
{
  int i;
  for (i = 0; postfix[i] != '\0'; i++)
	{
	  printf ("%c", postfix[i]);
	}
}

void infix_to_postfix ();
void infix_to_postfix ()
{
  int i, j = 0;
  char sym, f;
  for (i = 0; infix[i] != '\0'; i++)
	{
	  sym = infix[i];
	  if (sym == '(')
		{
		  push (sym);
		}
	  else if (sym == ')')
		{
		  while ((f = pop ()) != '(')
			{
			  postfix[j++] = f;
			}
		
		}
	  else if (sym == '+' || sym == '-' || sym == '*' || sym == '/'
			   || sym == '^')
		{
		  while (top != -1 && order (stack[top]) >= order (sym))
			  postfix[j++] = pop ();
			  
	        push (sym);

		}

	  else
		{
		  postfix[j++] = sym;
		}
	  


	}
	while (top != -1){

		  postfix[j++] = pop ();

		  postfix[j] = '\0';
}
}


int main ()
{
  printf ("ENTER THE INFIX ELEMENTS");
  scanf ("%s", infix);
  infix_to_postfix ();
  display();
}
