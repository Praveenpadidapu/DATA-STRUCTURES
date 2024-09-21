#include<stdio.h>
#include<stdlib.h>
#define max 100              
char postfix[max];
char stack[max];
int top = -1;

void push(char x)     
{
	top++;
	stack[top]=x;
}
char pop(){
	int temp;
	if(top==-1) {
	printf("Stack underflow");
	exit(1);
	}
	temp=stack[top];
	top--;
	return temp;
}

 

int main() {
	char sym;
	int i,a,b,result;
	printf("READ THE postfix EXPRESSION\n");
	scanf("%s",postfix);
	                                 
    
	for(i=0;postfix[i]!='\0';i++){
		sym=postfix[i];
		if(sym>='0' && sym<='9')
		   push(sym);
		else{
			a=pop()-'0';
			b=pop()-'0';
			switch(sym) {
            case '+' :
                result=b+a;
                break;
            case '-' :
                result=b-a;
                break;
            case '*' :
                result=b*a;
                break;
            case '/':
                result=b/a;
                break;
            }
  		result=result+'0';	
            push(result) ;
        }
      
}
	printf("\nAnswer=%d",pop()-'0');
	return 0;
}
