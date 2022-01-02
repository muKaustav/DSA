#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define sz 10

struct stk
{
    int top;
    char arr[sz];
};

typedef struct stk Stack;

int isFull(Stack *p)
{
    return (p->top == sz - 1 ? 1 : 0);
}

int isEmpty(Stack *p)
{
    return (p->top == -1 ? 1 : 0);
}

void push(Stack *s, char c)
{
    if (!isFull(s))
    {
        s->top++;
        s->arr[s->top] = c;
    }

    else
        printf("Stack overflow\n");
}

char pop(Stack *s)
{
    char c;

    if (!isEmpty(s))
    {
        c = s->arr[s->top];
        s->top--;

        return c;
    }

    else
    {
        printf("Stack underflow\n");
        return '\0';
    }
}

char peek(Stack *s)
{
    if (!isEmpty(s))
        return (s->arr[s->top]);

    else
        return '\0';
}

int isOperand(char ch)
{
    if ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <= 57))
        return 1;

    else
        return 0;
}

int precedence(char ch)
{
    int p;
    switch (ch)
    {
    case '+':
    case '-':
        p = 1;
        break;

    case '*':
    case '/':
        p = 2;
        break;

    case '^':
        p = 3;
        break;

    default:
        p = 0;
        break;
    }

    return (p);
}

void infixToPostfix(char *exp)
{
    int i = 0, k = -1;
    char post[100];

    Stack s;
    s.top = -1;

    while (exp[i])
    {
        if (isOperand(exp[i]))
            post[++k] = exp[i];

        else if (exp[i] == '(')
            push(&s, exp[i]);

        else if (exp[i] == ')')
        {
            while (peek(&s) != '(')
                post[++k] = pop(&s);

            pop(&s);
        }

        else
        {
            while (!isEmpty(&s) && precedence(exp[i]) <= precedence(peek(&s)))
                post[++k] = pop(&s);

            push(&s, exp[i]);
        }

        i++;
    }

    while (!isEmpty(&s))
        post[++k] = pop(&s);

    post[++k] = '\0';

    printf("%s\n", post);
}

void infixToPrefix(char *exp)
{
    int i = strlen(exp) - 1, k = -1;
    char post[100];

    Stack s;
    s.top = -1;

    while (i >= 0)
    {
        if (isOperand(exp[i]))
            post[++k] = exp[i];

        else if (exp[i] == '(')
            push(&s, exp[i]);

        else if (exp[i] == ')')
        {
            while (peek(&s) != '(')
                post[++k] = pop(&s);

            pop(&s);
        }

        else
        {
            while (!isEmpty(&s) && precedence(exp[i]) <= precedence(peek(&s)))
                post[++k] = pop(&s);

            push(&s, exp[i]);
        }

        i--;
    }

    while (!isEmpty(&s))
        post[++k] = pop(&s);

    post[++k] = '\0';

    for (i = k; i >= 0; i--)
        printf("%c", post[i]);
}

int main()
{
    char exp[] = "a*b+c";

    infixToPostfix(exp);
    infixToPrefix(exp);

    return 0;
}