   /**
      STACK Program with all Operations: Menu Base Program
     */
   
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define sz 10

struct stk
{
  char arr[sz];
  int top;
};

typedef struct stk Stack;

void initialize(Stack *p);
int isFull(Stack *p);
int isEmpty(Stack *p);
void push(Stack *p,char v);
char pop(Stack *p);
void infixToPostfix(char *exp ,Stack *stack);
void infixToPrefix(char *exp ,Stack *stack);
int isOperand(char ch);
int Prec(char ch);
void dispstack(Stack *p);
int evalpost(char *exp,Stack *stack);
int evalpre(char *exp,Stack *stack);
char peek(Stack *p);
int checkParan(char st[],Stack *p);
int validateExp(char st[],Stack *p);

int main()
{
	Stack *s;
	char r,v;
	int choice,val;
	char inf[100],post[50],pre[50];
	
	s=(Stack *)malloc(sizeof(Stack));
	do
	{
	  system("cls");
	  printf("\n----Menu----");
	  printf("\n1:Initialize stack");
	  printf("\n2:Disp stack");
	  printf("\n3:Push an elelement");
	  printf("\n4:Pop an element");
	  printf("\n5:Peek element");
	  printf("\n6:Infix to Postfix");
	  printf("\n7:Postfix evaluation");
	  printf("\n8:Paranthesis checking");
	  printf("\n9:Bracket checking");
	  printf("\n10:Infix to prefix");
	  printf("\n11:Prefix evaluation");
	  printf("\n12:Exit");
	  printf("\nEnter you choice:");
	  scanf("%d",&choice);
	  switch(choice)
	  {
	   	case 1:
			system("cls");
			initialize(s);
			break;
		case 2:
			system("cls");
			dispstack(s);
			getch();
			break;
		case 3:
			system("cls");
			fflush(stdin);
			printf("\nEnter value:");
			scanf("%c",&v);
			push(s,v);
			break;
		case 4:
			system("cls");
			r=pop(s);
			printf("\n%c is popped",r);
			getch();
			break;
		case 5:
			system("cls");
			r=peek(s);
			printf("\n%c is at top of the stack",r);
			getch();
			break;
		case 6:
			system("cls");
			fflush(stdin);
			printf("\nEnter infix expression:");
			scanf("%s",inf);
			infixToPostfix(inf,s);
			getch();
			break;
		case 7:
			system("cls");
			fflush(stdin);
			printf("\nEnter postfix expression:");
			scanf("%s",post);
			val=evalpost(post,s);
			printf("Value of postfix exp:%d",val);
			getch();
			break;
		case 8:
			system("cls");
			fflush(stdin);
			printf("\nEnter infix expression:");
			scanf("%s",inf);
			val=checkParan(inf,s);
			if(val==1)
			  printf("Valid Expression.\n");
			else
			  printf("Invalid Expression\n");
			getch();
			break;
		case 9:
			system("cls");
			fflush(stdin);
			printf("\nEnter infix expression:");
			scanf("%s",inf);
			val=validateExp(inf,s);
			if(val==1)
			  printf("Valid Expression.\n");
			else
			  printf("Invalid Expression\n");
			getch();
			break;
		case 10:
			system("cls");
			fflush(stdin);
			printf("\nEnter infix expression:");
			scanf("%s",inf);
			infixToPrefix(inf,s);
			getch();
			break;
		case 11:
			system("cls");
			fflush(stdin);
			printf("\nEnter prefix expression:");
			scanf("%s",pre);
			val=evalpre(pre,s);
			printf("Value of prefix exp:%d",val);
			getch();
			break;
		case 12:
			printf("good bye");
			break;
	  }
	}while(choice!=12);
  return(1);
}
    //Satck initialisation
void initialize(Stack *p)
{
   if(p!=NULL)
	p->top=-1;
   else
	exit(0);
}
   //Display elements of stack
void dispstack(Stack *p)
{
   int i,n;
   system("cls");
   printf("\n");
   if(!isEmpty(p))
	{
	  for(i=p->top;i>=0;i--)
        printf("\n%c",p->arr[i]);
    }
    else
      printf("Stack is empty");
}

  //Check stack is full or not
int isFull(Stack *p)
{
   return(p->top==sz-1 ? 1:0);
}

  //Check stack is empty or not
int isEmpty(Stack *p)
{
   return(p->top==-1 ? 1:0);
}
  //PUSH Operation
void push(Stack *p, char v)
{
   if(!isFull(p))
    {
      p->top++;
      p->arr[p->top]=v;
    }
    else
    {
      printf("Stack overflows.");
    }
}

  //POP Operation
char pop(Stack *p)
{
   char t;
   if(!isEmpty(p))
    {
      t=p->arr[p->top];
      p->top--;
      return(t);
    }
   else
    {
      printf("\nStack underflows");
      return '\0';
    }
}
   //Peek Element
char peek(Stack *p)
{
   if(!isEmpty(p))
     return(p->arr[p->top]); //returns the top value of the stack
   else
     return '\0';
}
    //Infix to Postfix conversion
void infixToPostfix(char *exp ,Stack *st)
{
   int i=0, k=-1;
   char post[100];
   while(exp[i])
    {
      if (isOperand(exp[i]))
         post[++k] = exp[i];
      else if (exp[i] == '(')
         push(st, exp[i]);
      else if (exp[i] == ')')
       {
         while (peek(st) != '(')
            post[++k] = pop(st);
         pop(st);
       }
      else /* an operator is encountered*/
       {
         while (!isEmpty(st) && Prec(exp[i]) <= Prec(peek(st)))
            post[++k] = pop(st);
         push(st, exp[i]);
       }
    i++;
   }
      /*pop all the operators from the stack and put to output */
   while (!isEmpty(st))
      post[++k] = pop(st );
   post[++k] = '\0';
   printf( "\n%s", post);
}

    //Infix to Prefix Conversion
void infixToPrefix(char *exp ,Stack *stack)
{
    /*reverse the infix;
      find postfix of reversed infix.
      reverse the postfix to get prefix of the given infix */
  int i, k=-1;
  char post[100],t;
  i=strlen(exp)-1;
  
  while(i>=0)
  {
    if (isOperand(exp[i]))
       post[++k] = exp[i];
    else if (exp[i] == ')')
       push(stack, exp[i]);
    else if (exp[i] == '(')
     {
       while (peek(stack) != ')')
         post[++k] = pop(stack); 
       pop(stack);
     }
    else /*an operator is encountered */
     {
        while (!isEmpty(stack) && Prec(exp[i]) < Prec(peek(stack))) // only <
          post[++k] = pop(stack);
        push(stack, exp[i]);
     }
    i--;
  }
      /* pop all the operators from the stack and put to output*/
  while (!isEmpty(stack))
    post[++k] = pop(stack );
  post[++k] = '\0';
  for(i=k;i>=0;i--)
    printf( "%c", post[i]);
}
    //Check Operand
int isOperand(char ch)
{
   if((ch>=65 && ch<=90) || (ch>=97 && ch <=122)|| (ch>=48 && ch<=57))
     return(1);
   else
     return(0);
}
    //Check Precedence of operator
int Prec(char ch)
{
  int p;
  switch(ch)
   {
	 case '+':
	 case '-':
			p=1;
			break;
	 case '*':
	 case '/':
			p=2;
			break;
	 case '^':
			p=3;
			break;
	 default:
			p=0;
			break;
   }
return(p);
}

   //Evaluate Postfix Expression
int evalpost(char *exp,Stack *stack)
 {
   int a,b,c,i=0;
   char ch,op;
   while(ch=exp[i])
    {
      if(isOperand(ch))
         push(stack,ch);
      else
       {
          b=pop(stack)-'0';
          a=pop(stack)-'0';
          switch(ch)
           {
              	case '+':
    				c=a+b;
					break;
				case '-':
					c=a-b;
					break;
				case '*':
					c=a*b;
					break;
				case '/':
					c=a/b;
					break;
				case '^':
					c=pow(a,b);
					break;
			}
			push(stack,c+'0');
		}
		i++;
	}
	return(pop(stack)-'0');
}
   //Evaluate Prefix expression
int evalpre(char *exp,Stack *stack)
{
   int a,b,c,i=strlen(exp)-1;
   char ch,op;
   while(i>=0)
    {
      ch=exp[i];
      if(isOperand(ch))
        push(stack,ch);
      else
       {
         a=pop(stack)-'0';
         b=pop(stack)-'0';
         
         /* Use switch case to evaluate a op b */
         switch(ch)
          {
			case '+':
				c=a+b;
				break;
			case '-':
				c=a-b;
				break;
			case '*':
				c=a*b;
				break;
			case '/':
				c=a/b;
				break;
			case '^':
				c=pow(a,b);
				break;
		  }
		 push(stack,c+'0');
		}		
		i--;
	}
   return(pop(stack)-'0');
}
    //Paranthesis checking
int checkParan(char st[],Stack *p) /*checking valid paranthesis in an exp.*/
{
   	char ch,chp;
	int i=0, flag=1;
	initialize(p);
	while(ch=st[i])
	{
		if(ch=='(')
			push(p,ch);
		if(ch==')')
		{
			if(isEmpty(p))
			{
				flag=0;
				break;
			}
			chp=pop(p);
			if(chp!='(')
			{
				flag=0;
				break;
			}
		}
		i++;
	}
	if(!isEmpty(p))
		flag=0;
	return flag;
}
    //Validate Expression
int validateExp(char st[],Stack *p) //validation of different types of brackets
{
	char ch,chp;
	int i=0, flag=1; /*flag=1 ; anticipating expression is valid */
	initialize(p);
	
	while(ch=st[i])
	{
		if(ch=='('||ch=='{'||ch=='[')
			push(p,ch);
		if(ch==')'||ch=='}'||ch==']')
		{
			if(isEmpty(p))
			{
				flag=0;
				break;
			}
			chp=pop(p);
			if((ch==')' && chp!='(') || (ch=='}' && chp!='{') || (ch==']' && chp!='['))
			{
				flag=0;
				break;
			}
		}		
		i++;
	}
	if(!isEmpty(p))
		flag=0;
	return flag;
}
