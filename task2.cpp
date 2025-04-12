//Remove middle element from stack
#include <iostream>
using namespace std;

class Stack {
private:
	int* arr;        
	int top;         
	int capacity;   

public:
	Stack(int size) {
		capacity = size;
		arr = new int[capacity];
		top = -1;  
	}

	~Stack() {
		delete[] arr;
	}

	void push(int value) {
		if (top == capacity - 1) {
			cout << "Stack overflow. Cannot push " << value << endl;
		}
		else {
			arr[++top] = value;  // Increment top and insert value
			cout << value << " pushed to stack." << endl;
		}
	}

	int pop() {
		if (top == -1) {
			cout << "Stack underflow. Cannot pop." << endl;
			return -1;
		}
		else {
			int poppedValue = arr[top--];  
			return poppedValue;
		}
	}

	int peek() {
		if (top != -1) {
			return arr[top];
		}
		else {
			cout << "Stack is empty." << endl;
			return -1;
		}
	}

	bool isEmpty() {
		return top == -1;
	}

	int size() {
		return top + 1;
	}

	void removeMiddleElement() {

		int m = size() / 2;
		int *Array = new int[size()];
		int c = size();
		for (int i = 0; i < c; i++) {
			Array[i] = pop();
		}


		for (int i = c - 1; i >= 0; i--) {
			if (i != m) {
				push(Array[i]);
			}
		}

		delete[] Array;
	}
};

int main() {
	Stack s(5);  

	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);

	if (s.isEmpty()) {
		cout << "Stack is empty!" << endl;
	}
	else {
		cout << "Stack is not empty." << endl;
	}

	s.removeMiddleElement();
	cout << "After removing middle element size of the stack: " << s.size() << endl;

	cout << "Top element: " << s.peek() << endl;

	system("pause");
	return 0;
}
