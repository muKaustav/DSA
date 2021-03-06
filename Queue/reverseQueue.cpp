#include <bits/stdc++.h>
using namespace std;

void reverseQueue(queue<int> &Queue)
{
    stack<int> Stack;

    while (!Queue.empty())
    {
        Stack.push(Queue.front());
        Queue.pop();
    }

    while (!Stack.empty())
    {
        Queue.push(Stack.top());
        Stack.pop();
    }
}

void display(queue<int> &Queue)
{
    while (!Queue.empty())
    {
        cout << Queue.front() << " ";
        Queue.pop();
    }
}

int main()
{
    queue<int> Queue;
    Queue.push(10);
    Queue.push(20);
    Queue.push(30);
    Queue.push(40);
    Queue.push(50);
    Queue.push(60);
    Queue.push(70);
    Queue.push(80);
    Queue.push(90);
    Queue.push(100);

    reverseQueue(Queue);
    display(Queue);
}
