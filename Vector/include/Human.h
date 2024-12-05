#include "Mylib.h"

class Human {
protected:
	string vardas, pavarde;
public:
	Human() : vardas(""), pavarde("") {};
	Human(string vardas, string pavarde) :
		vardas(vardas), pavarde(pavarde) {
	}

	//setters and getters
	void setName(string tempVardas) {
		vardas = tempVardas;
	}
	inline string getName() const { return vardas; }

	void setLastName(string tempPavarde) {
		pavarde = tempPavarde;
	}
	inline string getLastName() const { return pavarde; }

	//II. copy constructor
	Human(const Human& copy) {
		vardas = copy.vardas;
		pavarde = copy.pavarde;
	}
	//III.copy assigment
	Human& operator=(const Human& other) {
		if (this != &other) {
			vardas = other.vardas;
			pavarde = other.pavarde;
		}
		return *this;
	}

	~Human() { vardas.clear(); pavarde.clear(); }

	virtual void whoAmI() const = 0;
};