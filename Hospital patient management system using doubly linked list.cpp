#include<iostream>
#include<string>
using namespace std;

class Patient{
private:
	int Patient_ID;
	string Name;
	int Age;
	string Disease_Description;
public:
	Patient(int id = 0, string n = "", int a = 0, string d = ""){
		Patient_ID = id;
		Name = n;
		Age = a;
		Disease_Description = d;
	}
	int getID(){
		return Patient_ID;
	}
	void display(){
		cout << "PatientID: " << Patient_ID << endl;
		cout << "Nmae: " << Name << endl;
		cout << "Age: " << Age << endl;
		cout << "Disease_Description: " << Disease_Description << endl << endl;
	}
};

struct PatientNode{
	Patient patient;
	PatientNode* prev;
	PatientNode* next;

	PatientNode(int id, string name, int age, string disease){
		patient = Patient(id, name, age, disease);
		prev = nullptr;
		next = nullptr;
	}
};

class DoublyLinkedList{
private:
	PatientNode* head;
	PatientNode* tail;
public:
	DoublyLinkedList(){
		head = nullptr;
	}
	void admitPatient(int id, string name, int age, string disease){
		PatientNode* newNode = new PatientNode(id, name, age, disease);
		if (!head){
			head = tail = newNode;
		}
		else{
			tail->next = newNode;
			newNode->prev = tail;
			tail = newNode;

		}
		cout << "Patient admitted. ID:" << id << endl;
	}
	void emergencyDischarge(){
		if (!head)
		{
			cout << "No emergency patient to discharge.\n";
			return;
		}
		PatientNode* temp = head;
		cout << "Emergency case: " << endl;
		temp->patient.display();
		head = head->next;
		if (head){
			head->prev = nullptr;
		}
		else{
			tail = nullptr;
		}
		delete temp;
	}

	void dischargeByID(int id){
		if (!head)
		{
			cout << "No patient to discharge.\n";
			return;
		}
		PatientNode* temp = head;
		while (temp){
			if (temp->patient.getID() == id){
				if (temp == head){
					head = temp->next;
				}
				if (temp == tail){
					tail = temp->prev;
				}
				if (temp->prev){
					temp->prev->next = temp->next;
				}
				if (temp->next){
					temp->next->prev = temp->prev;
				}
				cout << "Discharging patient with ID: " << id << endl;
				delete temp;
				return;
			}
			temp = temp->next;
		}
		cout << "Patient with ID " << id << " not found.\n";
	}

	void displayPatientsForward(){
		if (!head)
		{
			cout << "No patient to display.\n";
			return;
		}
		PatientNode* temp = head;
		cout << "\n\tPatient details forward\n";
		while (temp){
			temp->patient.display();
			temp = temp->next;
		}
	}

	void displayPatientsBackward(){
		if (!tail)
		{
			cout << "No patient to display.\n";
			return;
		}
		PatientNode* temp = tail;
		cout << "\n\tPatient details backward\n";
		while (temp){
			temp->patient.display();
			temp = temp->prev;
		}
	}

	bool searchPatient(int id){
		if (!head)
		{
			cout << "No patient to search.\n";
			return false;
		}
		PatientNode* temp = head;
		while (temp){
			if (temp->patient.getID() == id){
				return true;
			}
			temp = temp->next;
		}
		return false;
	}

	int countPatients(){
		int count = 0;
		PatientNode* temp = head;
		while (temp){
			count++;
			temp = temp->next;
		}
		return count;
	}

	void clearAllPatients(){
		while (head){
			PatientNode* temp = head;
			head = head->next;
			delete temp;
		}
		tail = nullptr;
		cout << "All patient records cleared.\n";
	}
	~DoublyLinkedList(){
		clearAllPatients();
	}
};
int main(){
	DoublyLinkedList hospital;
	hospital.admitPatient(01, "Ali", 23, "Cancer");
	hospital.admitPatient(02, "Ahmad", 29, "Diabetes");
	hospital.admitPatient(03, "Umar", 13, "Flu");
	hospital.admitPatient(04, "Aiman", 50, "Headache");
	hospital.admitPatient(05, "Aila", 40, "Fever");

	hospital.displayPatientsForward();
	hospital.displayPatientsBackward();

	if (hospital.searchPatient(3)){
		cout << "Found." << endl;
	}
	else{
		cout << "Not Found." << endl;
	}
	hospital.emergencyDischarge();

	hospital.dischargeByID(4);

	hospital.displayPatientsForward();

	cout << "The total number of remaining patients:" << hospital.countPatients() << endl;

	hospital.clearAllPatients();
	hospital.displayPatientsForward();

	system("pause");
	return 0;
}