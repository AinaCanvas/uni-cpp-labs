//You're tracking circular references in a network routing system. (Floyd's Algorithm).
#include<iostream>
using namespace std;

class Router {
public:
	int id;
	Router* next;
	Router(int val) : id(val), next(nullptr) {}
};

class Network {
private:
	Router* head;
public:
	Network() : head(nullptr) {}

	void addRouter(int id) {
		Router* newRouter = new Router(id);
		if (!head) {
			head = newRouter;
			return;
		}
		Router* temp = head;
		while (temp->next) {
			temp = temp->next;
		}
		temp->next = newRouter;
	}

	void createCircularReference(int fromId) {
		Router* temp = head;
		Router* target = nullptr;
		while (temp->next) {
			if (temp->id == fromId) {
				target = temp;
			}
			temp = temp->next;
		}
		if (target) {
			temp->next = target; 
		}
	}

	bool detectCircularReference() {
		Router* slow = head;
		Router* fast = head;
		while (fast && fast->next) {
			slow = slow->next;         
			fast = fast->next->next;   
			if (slow == fast) {
				return true; 
			}
		}
		return false; 
	}

	void display() {
		Router* temp = head;
		int steps = 0;
		while (temp && steps < 20) { 
			cout << temp->id << " -> ";
			temp = temp->next;
			steps++;
		}
		cout << "NULL\n";
	}

	~Network() {
		Router* temp;
		while (head) {
			temp = head;
			head = head->next;
			delete temp;
		}
	}
};

int main() {
	Network network;

	network.addRouter(1);
	network.addRouter(2);
	network.addRouter(3);
	network.addRouter(4);
	network.addRouter(5);

	network.display();

	network.createCircularReference(3);

	if (network.detectCircularReference()) {
		cout << "Circular reference detected in the network routing system!\n";
	}
	else {
		cout << "No circular reference found.\n";
	}
	system("pause");
	return 0;
}
