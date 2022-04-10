#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

class Stack {
private:
	int top, MaxSize;
	char* stack;
public:
	Stack(int size);
	bool isFull(), isEmpty();
	char pop();
	void push(char element);
};

Stack::Stack(int size) {
	MaxSize = size;
	stack = new char[MaxSize];
	top = -1;
}

bool Stack::isFull() {
	if (top == MaxSize - 1) return 1;
	else return 0;
}

bool Stack::isEmpty() {
	if (top == -1) return 1;
	else return 0;
}

char Stack::pop() {
	if (isEmpty() == 1) {
		cout << "Stack is Empty" << endl;
	}
	else return stack[top--];
}

void Stack::push(char element) {
	if (isFull() == 1) {
		cout << "Stack is Full" << endl;
	}
	else stack[++top] = element;
}

class IntStack {
private:
	int top, MaxSize;
	int* stack;
public:
	IntStack(int size);
	bool isFull(), isEmpty();
	char pop();
	void push(int element);
};

IntStack::IntStack(int size) {
	MaxSize = size;
	stack = new int[MaxSize];
	top = -1;
}

bool IntStack::isFull() {
	if (top == MaxSize - 1) return 1;
	else
		return 0;
}

bool IntStack::isEmpty() {
	if (top == -1) return 1;
	else 
		return 0;
}

char IntStack::pop() {
	if (isEmpty() == 1) {
		cout << "Stack is Empty" << endl;
	}
	else
		return stack[top--];
}

void IntStack::push(int element) {
	if (isFull() == 1) {
		cout << "Stack is Full" << endl;
	}
	else 
		stack[++top] = element;
}

int main() {
	char postfix[100] = {};
	char infix[100] = {};
	int top = 0;
	Stack save(50);

	//���� ǥ������� �� �Է�
	cout << "������ �� ������ �Է�: ";
	cin.getline(infix, 100); 

	// �Էµ� getline(infix)�� ���� �׸��� ���� �� ������ �˻�
	for (int i = 0; i<=100; i++) {
		if (infix[i] == ')') // ')'�� ���� �������� �����ڸ� pop
			postfix[top++] = save.pop();
		if (infix[i] == '+') // ��Ģ���� �����ڵ��� infix�� ���� push
			save.push(infix[i]);
		if (infix[i] == '*')
			save.push(infix[i]);
		if (infix[i] == '/')
			save.push(infix[i]);
		if (infix[i] == '-')
			save.push(infix[i]);
		while (infix[i] >= '0' && infix[i] <= '9') {
			postfix[top++] = infix[i]; // infix�� ���� ���ڵ��� ��� �������̹Ƿ� ..
			break;
		}
		postfix[top] = NULL;
		if (infix[i] == NULL) break; // �ǹ̾��� 0-100�� ���� �ݺ��� ���� ���� �ڵ� 
	}

	cout << "����ǥ��� �ۼ��� �� : " << postfix << endl;

	IntStack acc(100); 
	int x;
	for (int i = 0; postfix[i] != NULL; i++) {
		x = 0;
		if (postfix[i] == '+') x = acc.pop() + acc.pop();
		if (postfix[i] == '-') x = acc.pop() - acc.pop();
		if (postfix[i] == '*') x = acc.pop() * acc.pop();
		if (postfix[i] == '/') x = acc.pop() / acc.pop();
		while (postfix[i] >= '0' && postfix[i] <= '9') {
			x = 10 * x + (postfix[i] - '0');
			break;
		}
		acc.push(x);
	}

	cout << "�������: " << acc.pop() << endl;
}

