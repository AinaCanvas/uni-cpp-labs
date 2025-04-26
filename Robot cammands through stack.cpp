#include <iostream>
#include <string>
using namespace std;

class CommandStack {
private:
	string* commands;
	int capacity;
	int top;

	void resize() {
		int newCapacity = capacity * 2;
		string* newCommands = new string[newCapacity];
		for (int i = 0; i <= top; i++) {
			newCommands[i] = commands[i];
		}
		delete[] commands;
		commands = newCommands;
		capacity = newCapacity;
	}

	void discardOldestIfNeeded() {
		if (top + 1 > 10) {
			for (int i = 1; i <= top; i++) {
				commands[i - 1] = commands[i];
			}
			top--;
		}
	}

public:
	CommandStack(int s = 4) {
		top = -1;
		capacity = s;
		commands = new string[capacity];
	}

	~CommandStack() {
		delete[] commands;
	}

	void push(const string& c) {
		if (top == capacity - 1) {
			resize();
		}
		discardOldestIfNeeded();
		commands[++top] = c;
	}

	string pop() {
		if (top == -1) {
			cout << "Stack is empty." << endl;
			return "";
		}
		return commands[top--];
	}

	void display() {
		cout << "Current Commands (" << top + 1 << "):\n";
		for (int i = 0; i <= top; i++) {
			cout << commands[i] << endl;
		}
		cout << "------\n";
	}
};
int main() {
	CommandStack robot;

	robot.push("MOVE 10");
	robot.push("TURN LEFT");
	robot.push("MOVE 20");
	robot.push("TURN RIGHT");
	robot.push("STOP");
	robot.push("MOVE 5");
	robot.push("TURN BACK");
	robot.push("MOVE 15");
	robot.push("JUMP");
	robot.push("SIT");
	robot.push("ROLL");
	robot.push("RUN");
	robot.push("MOVE 15");

	robot.display(); 

	system("pause");
	return 0;
}
