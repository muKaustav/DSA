#include <iostream>
using namespace std;

int n = 100, top = -1;
int stack[100];

void push(int val)
{
	if (top >= n - 1)
		cout << "stack overflow" << endl;

	else
	{
		top++;
		stack[top] = val;
	}
}

void pop()
{
	if (top <= -1)
		cout << "stack underflow" << endl;

	else
	{
		cout << "the popped element is " << stack[top] << endl;
		top--;
	}
}

void display()
{
	if (top >= 0)
	{
		cout << "stack elements are\n";

		for (int i = top; i >= 0; i--)
			cout << stack[i] << " ";

		cout << endl;
	}

	else
		cout << "stack is empty\n";
}

void findMinimum()
{
	if (top >= 0)
	{
		int minEle = stack[top];

		for (int i = top; i >= 0; i--)
		{
			if (stack[i] < minEle)
				minEle = stack[i];
		}

		cout << "the minimum element is " << minEle << endl;
	}

	else
		cout << "stack is empty\n";
}

void findMaximum()
{
	if (top >= 0)
	{
		int maxEle = stack[top];

		for (int i = top; i >= 0; i--)
		{
			if (stack[i] > maxEle)
				maxEle = stack[i];
		}

		cout << "the maximum element is " << maxEle << endl;
	}

	else
		cout << "stack is empty\n";
}

void findMinRange()
{

	if (top == 0)
		cout << "the minimum element in range (top / 2) + 1 is " << stack[0] << endl;

	else if (top > 0)
	{
		int query = top / 2 + 1;
		int minEle = stack[query];

		for (int i = query; i >= 0; i--)
		{
			if (stack[i] < minEle)
				minEle = stack[i];
		}

		cout << "the minimum element in range (top / 2) + 1 is " << minEle << endl;
	}

	else
		cout << "stack is empty\n";
}

int main()
{
	int ch, val = 0;

	do
	{
		cout << "\nEnter choice: " << endl;
		cout << "1) Push in stack" << endl;
		cout << "2) Pop from stack" << endl;
		cout << "3) Display stack" << endl;
		cout << "4) Peek minimum value" << endl;
		cout << "5) Peek maximum value" << endl;
		cout << "6) Peek minimum value in size / 2 + 1" << endl;
		cout << "7) Exit" << endl;

		cin >> ch;

		switch (ch)
		{
		case 1:
		{
			cout << "Enter value to be pushed:" << endl;
			cin >> val;
			push(val);
			break;
		}

		case 2:
		{
			pop();
			break;
		}

		case 3:
		{
			display();
			break;
		}

		case 4:
		{
			findMinimum();
			break;
		}

		case 5:
		{
			findMaximum();
			break;
		}

		case 6:
		{
			findMinRange();
			break;
		}

		case 7:
		{
			cout << "Exit" << endl;
			break;
		}

		default:
			cout << "Invalid Choice" << endl;
		}

	} while (ch != 7);

	return 0;
}