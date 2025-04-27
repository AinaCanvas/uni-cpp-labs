////Remove a specific song from your playlist by its ID.
//#include<iostream>
//#include<string>
//using namespace std;
//
//class song{
//public:
//	int ID;
//	string name;
//	song *next;
//	song(int id,string n) :ID(id),name(n), next(nullptr){}
//};
//
//class playList{
//private:
//	song* head;
//public:
//	playList() :head(nullptr){}
//
//	void insertAtEnd(int id, string n){
//		song* newsong = new song(id,n);
//		if (!head){
//			head = newsong;
//			return;
//		}
//		song* temp = head;
//		while (temp->next){
//			temp = temp->next;
//		}
//		temp->next = newsong;
//	}
//	void removeSong(int songid){
//		if (!head){
//			cout << "Playlist is empty." << endl;
//			return;
//		}
//		if (head->ID == songid){
//			song* temp = head;
//			head = head->next;
//			delete temp;
//			cout << "Song with ID " << songid << " removed from the playlist.\n";
//			return;
//		}
//		song* temp = head;
//		while (temp->next&&temp->next->ID != songid){
//			temp = temp->next;
//		}
//		if (temp->next){
//			song* toDelete = temp->next;
//			temp->next = temp->next->next;
//			delete toDelete;
//			cout << "Song with ID " << songid << " removed from the playlist.\n";
//		}
//		else {
//			cout << "Song with ID " << songid << " not found.\n";
//		}
//	}
//	void display(){
//		song* temp = head;
//		cout << "Playlist: ";
//		while (temp){
//			cout <<"["<<temp->ID<<"] " << temp->name << " -> ";
//			temp = temp->next;
//		}
//		cout << "NULL\n";
//	}
//	~playList(){
//		song* temp;
//		while (head){
//			temp = head;
//			head = head->next;
//			delete temp;
//		}
//	}
//};
//int main(){
//	playList Playlist;
//	Playlist.insertAtEnd(01,"song1");
//	Playlist.insertAtEnd(02,"song2");
//	Playlist.insertAtEnd(03,"song3");
//	Playlist.insertAtEnd(04,"song4");
//	Playlist.insertAtEnd(05,"song5");
//	Playlist.display();
//
//	Playlist.removeSong(03);
//	Playlist.display();
//	system("pause");
//	return 0;
//}
