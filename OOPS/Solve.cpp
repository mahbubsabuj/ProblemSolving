#include <iostream>
using std::string;

class Employee {
//Encapsulation :
//is the idea of bundling data and methods inside the class.
//anybody who needs to change the data have to go through user defined methods to modify certain data
//Abstruction:
//Hiding complex logic
private:
	string Name;
	string Company;
	int Age;
public:
	void setName(string Name) {
		this->Name = Name;
	}
	string getName() {
		return Name;
	}
	void setCompany(string Company) {
		this->Company = Company;
	}
	string getCompany() {
		return Company;
	}
	void setAge(int Age) {
		this->Age = Age;
	}
	int getAge() {
		return Age;
	}
	Employee(string Name, string Company, int Age) {
		this->Name = Name;
		this->Company = Company;
		this->Age = Age;
	}
	void IntroduceYourself() {
		std::cout << "Hello, My name is " << Name << " I work for " << Company << " & My Age is " << Age << std::endl;
	}
};

int main () {
	Employee employee1("Mahbubul Alam", "_", 25);
	employee1.IntroduceYourself();
	employee1.setName("Mahbubul Alam Sabuj");
	std::cout << employee1.getName();
}
