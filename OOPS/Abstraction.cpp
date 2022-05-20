#include <iostream>
using std::string;

class AbstructEmployee{
	virtual void AskForPromotion() = 0;
};

class Employee: AbstructEmployee {
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
	void AskForPromotion() {
		if (Age > 30) {
			std::cout << Name << " Got promoted!" << std::endl;
		} else {
			std::cout << Name << ", sorry NO promotion for You!" << std::endl;
		}
	}
};

int main () {
	Employee employee1("Mahbubul Alam", "_", 25);
	employee1.IntroduceYourself();
	employee1.setName("Mahbubul Alam Sabuj");
	std::cout << employee1.getName() << std::endl;
	employee1.AskForPromotion();
	Employee employee2("John Doe", "DSoft", 32);
	employee2.AskForPromotion();
}
