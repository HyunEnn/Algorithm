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

	//중위 표기법으로 식 입력
	cout << "중위로 된 계산식을 입력: ";
	cin.getline(infix, 100); 

	// 입력된 getline(infix)를 통해 항마다 변수 및 연산자 검사
	for (int i = 0; i<=100; i++) {
		if (infix[i] == ')') // ')'로 식이 끝낫으면 연산자를 pop
			postfix[top++] = save.pop();
		if (infix[i] == '+') // 사칙연산 연산자들은 infix에 전부 push
			save.push(infix[i]);
		if (infix[i] == '*')
			save.push(infix[i]);
		if (infix[i] == '/')
			save.push(infix[i]);
		if (infix[i] == '-')
			save.push(infix[i]);
		while (infix[i] >= '0' && infix[i] <= '9') {
			postfix[top++] = infix[i]; // infix에 넣은 숫자들은 모두 문자형이므로 ..
			break;
		}
		postfix[top] = NULL;
		if (infix[i] == NULL) break; // 의미없는 0-100항 까지 반복을 막기 위한 코드 
	}

	cout << "후위표기로 작성된 식 : " << postfix << endl;

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

	cout << "계산결과값: " << acc.pop() << endl;
}

