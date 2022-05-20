#include <iostream>
using std::string;

class AbstructEmployee{
	virtual void AskForPromotion() = 0;
};

class Employee: AbstructEmployee {
private:
	string Company;
	int Age;
protected:
	string Name;
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

class Developer:public Employee {
private:
	string FavProgrammingLanguage;
public:
	void setFavProgrammingLanguage(string FavProgrammingLanguage) {
		this->FavProgrammingLanguage = FavProgrammingLanguage;
	}
	string getFavProgrammingLanguage() {
		return FavProgrammingLanguage;
	}
	Developer(string Name, string Company, int Age, string FavProgrammingLanguage): Employee(Name, Company, Age) {
		this->FavProgrammingLanguage = FavProgrammingLanguage;
	}
	void printFavProgrammingLanguage() {
		std::cout << Name << "'s Favorite Programming Language is " << FavProgrammingLanguage << std::endl;
	}
};

class Teacher:public Employee {
private:
	string Subject;
public:
	void setSubject(string Subject) {
		this->Subject = Subject;
	}
	string getSubject() {
		return Subject;
	}
	Teacher(string Name, string Company, int Age, string Subject): Employee(Name, Company, Age) {
		this->Subject = Subject;
	}
	void teachersSubject() {
		std::cout << Name << " Teaches " << Subject << std::endl;
	}
};

int main () {
	// Employee employee1("Mahbubul Alam", "_", 25);
	// employee1.IntroduceYourself();
	// employee1.setName("Mahbubul Alam Sabuj");
	// std::cout << employee1.getName() << std::endl;
	// employee1.AskForPromotion();
	// Employee employee2("John Doe", "DSoft", 32);
	// employee2.AskForPromotion();
	// Developer developer1("John Doe", "Dsoft", 32, "C++");
	// developer1.AskForPromotion();
	// developer1.printFavProgrammingLanguage();
	// std::cout << std::endl;
	Teacher teacher1("Farhan Sadek Sakib", "D University", 26, "English");
	teacher1.IntroduceYourself();
	teacher1.teachersSubject();
    teacher1.AskForPromotion();
}
