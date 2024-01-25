#include <iostream>
using namespace std;

class Locker {
public:
	Locker() { id = 0; pass = 0; }//default constructor
	Locker(int pass) {			//overloaded constructor
		this->id = ++objectCount;
		this->pass = pass;
	}
	int getId() { return id; }
	int getPass() { return pass; }
	void setId(int newid) { this->id = newid; }
	void setPass(int newPass) { this->pass = newPass; }
	static int objectCount;
private:
	int id, pass;
};
int Locker::objectCount = 0;//starter value for static member
int main() {

	const int numLockers = 50;
	Locker lockers[numLockers];
	//populate lockers array
	for (int i = 0; i < numLockers; ++i) {
		int pass = 10000 + rand() % 10000;
		lockers[i] = Locker(pass);
	}
	//display locker detail 
	for (int i = 0; i < numLockers; ++i) {
		cout << "Locker id : " << lockers[i].getId() << "  Locker Password: " << lockers[i].getPass() << endl;
	}
	//allow for change to locker numbers
	Locker* lockerPtr = &lockers[0];
	for (int i = 0; i < numLockers; ++i) {
		cout << "New locker numbers " << (lockerPtr + i)->getId() << endl;
	}
	return 0;
}