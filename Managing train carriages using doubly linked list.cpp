#include<iostream>
#include<string>
using namespace std;

class Carraige{
private:
	int CarraigeNum;
	string type;
	int capacity;
public:
	Carraige(int n = 0, string t = "", int c = 0){
		CarraigeNum = n;
		type = t;
		capacity = c;
	}
	int getNum(){
		return CarraigeNum;
	}
	void display(){
		cout << "Carraige " << CarraigeNum << " - " << type << " - " << capacity << " seats\n";
	}
};

struct Node{
	Carraige c;
	Node* prev;
	Node* next;

	Node(int num = 0, string t = "", int cap = 0){
		c = Carraige(num, t, cap);
		prev = nullptr;
		next = nullptr;
	}
};

class Train{
private:
	Node* head;
public:
	Train(){
		head = nullptr;
	}
	void addCarriageFront(int num, string type, int capacity){
		Node* newNode = new Node(num, type, capacity);
		if (!head){
			head = newNode;
		}
		else {
			newNode->prev = nullptr;
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
		}
		cout << "Carriage added to front: " << num << endl;
	}
	void addCarriageEnd(int num, string type, int capacity){
		Node* newNode = new Node(num, type, capacity);
		if (!head){
			head = newNode;
		}
		else{
			Node* temp = head;
			while (temp->next != nullptr){
				temp = temp->next;
			}
			temp->next = newNode;
			newNode->prev = temp;
		}
		cout << "Carriage added to end: " << num << endl;
	}
	void removeCarriageByNumber(int num) {
		Node* temp = head;

		while (temp != nullptr) {
			if (temp->c.getNum() == num) {
				if (temp == head) {
					head = head->next;
					if (head != nullptr) {
						head->prev = nullptr;
					}
					delete temp;
					cout << "Carriage removed: " << num << endl;
					return;
				}
				else {
					if (temp->prev) temp->prev->next = temp->next;
					if (temp->next) temp->next->prev = temp->prev;
					delete temp;
					return;
				}
			}
			temp = temp->next;
		}
		cout << "Carriage not found: " << num << endl;
	}

	void displayTrainForward(){
		Node* temp = head;
		cout << "\nTrain forward:" << endl;
		while (temp){
			temp->c.display();
			temp = temp->next;
		}
	}
	void displayTrainBackward(){
		Node* temp = head;
		if (!temp){
			return;
		}
		else {
			while (temp->next != nullptr){
				temp = temp->next;
			}
			cout << "\nTrain backword:" << endl;
			while (temp){
				temp->c.display();
				temp = temp->prev;
			}
		}
	}

};
int main(){
	Train t;
	t.addCarriageEnd(101, "Passenger", 80);
	t.addCarriageEnd(102, "Cargo", 100);
	t.addCarriageFront(100, "Passenger", 60);

	t.displayTrainForward();
	t.removeCarriageByNumber(102);
	t.displayTrainBackward();

	system("pause");
	return 0;
}