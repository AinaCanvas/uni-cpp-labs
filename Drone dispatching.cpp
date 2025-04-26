#include <iostream>
using namespace std;

class Drone {
private:
	int id;
	int priority;
public:
	Drone(int i = 0, int p = 0) {
		id = i;
		priority = p;
	}
	int getID() {
		return id;
	}
	int getPriority() {
		return priority;
	}
	void display() {
		cout << "ID: " << id << "  Priority: " << priority << endl;
	}
};

class Stack {
private:
	Drone* arr;
	int capacity;
	int top;
public:
	Stack(int size) {
		capacity = size;
		arr = new Drone[capacity];
		top = -1;
	}
	~Stack() {
		delete[] arr;
	}
	void push(Drone val) {
		if (top == capacity - 1) {
			cout << "Stack overflow." << endl;
		}
		else {
			arr[++top] = val;
		}
	}
	Drone pop() {
		if (top == -1) {
			cout << "Stack underflow." << endl;
			return Drone();  // Return default drone
		}
		else {
			return arr[top--];
		}
	}
	Drone peek() {
		if (top != -1) {
			return arr[top];
		}
		else {
			cout << "Stack is empty." << endl;
			return Drone();
		}
	}
	bool isEmpty() {
		return top == -1;
	}
	int size() {
		return top + 1;
	}

	void clear() {
		top = -1;
	}
};

void dispatchHighestPriorityDrone(Stack& s) {
	int n = s.size();
	Drone* temp = new Drone[n];
	int maxPriority = -1;
	int maxIndex = -1;

	for (int i = n - 1; i >= 0; i--) {
		temp[i] = s.pop();
		if (temp[i].getPriority() > maxPriority) {
			maxPriority = temp[i].getPriority();
			maxIndex = i;
		}
	}

	cout << "\nDispatched Drone with Highest Priority:\n";
	temp[maxIndex].display();

	for (int i = 0; i < n; i++) {
		if (i != maxIndex)
			s.push(temp[i]);
	}

	delete[] temp;
}

int main() {
	Drone D1(1, 5);
	Drone D2(2, 8);
	Drone D3(3, 2);
	Drone D4(4, 10);
	Drone D5(5, 3);
	Drone D6(6, 9);

	Stack drones(6);
	drones.push(D1);
	drones.push(D2);
	drones.push(D3);
	drones.push(D4);
	drones.push(D5);
	drones.push(D6);

	cout << "Dispatching Drones in Order of Priority:\n";

	while (!drones.isEmpty()) {
		dispatchHighestPriorityDrone(drones);
	}

	system("pause");
	return 0;
}
