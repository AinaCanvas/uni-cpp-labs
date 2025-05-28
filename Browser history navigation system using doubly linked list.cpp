#include<iostream>
#include<string>
using namespace std;

class History{
private:
	string URL;
	string title;
public:
	History(string url="",string t=""){
		URL = url;
		title = t;
	}
	void display(){
		cout << URL << " - " << title << endl;
	}
};

struct Node{
	History h;
	Node* prev;
	Node* next;

	Node(string url = "", string t = ""){
		h = History(url, t);
		prev = nullptr;
		next = nullptr;
	}
};

class BrowserHistory{
private:
	Node* head;
	Node* current;
public:
	void visitPage(string url, string title){
		Node* newPage = new Node(url, title);
		if (!head) {
			head = newPage;
		}
		else {
			current->next = newPage;
			newPage->prev = current;
		}
		current = newPage;
	}

	// – Go back to the previous page
	void back(){
		if (current && current->prev)
		current = current->prev;
	}

	// – Go forward to the next pag
	void forward(){
		if (current && current->next)
		current = current->next;
	}

	// – Show the current page
	void currentPage(){
		cout << "Cuurent page:\n";
		current->h.display();
		cout << endl;
	}

	// – Display the entire history
	void showHistory(){
		cout << "Browser history: \n";
		Node* temp = head;
		while (temp){
			temp->h.display();
			temp = temp->next;
		}
		cout << endl;
	}

	//destructor
	~BrowserHistory() {
		Node* temp = head;
		while (temp) {
			Node* nextNode = temp->next;
			delete temp;
			temp = nextNode;
		}
	}
};

int main(){
	BrowserHistory bh;
	bh.visitPage("google.com","Google");
	bh.visitPage("openai.com","OpenAI");
	bh.visitPage("github.com","GitHub");
	bh.back();
	bh.currentPage();
	bh.forward();
	bh.currentPage();
	bh.showHistory();

	system("pause");
	return 0;
}