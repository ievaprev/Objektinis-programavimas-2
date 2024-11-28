#include "Mylib.h"

class Stud {
private:
	string vardas, pavarde;
public:
	vector<int>ND;
	double vid, med, egz;

	Stud() : vardas(""), pavarde(""), vid(0), med(0), egz(0) {}
	Stud(string vardas, string pavarde, vector<int> nd, int egz) : 
		vardas(vardas), pavarde(pavarde), ND(nd), egz(egz), vid(0), med(0) {}

	Stud(std::istream& is) : Stud() { 
		is >> *this;
	}

	void setName(string tempVardas) {
		vardas = tempVardas;
	}
	inline string getName() const { return vardas; }
	void setLastName(string tempPavarde) {
		pavarde = tempPavarde;
	}
	inline string getLastName() const { return pavarde; }

	//operatoriai
	friend std::istream& operator>>(std::istream& in, Stud& student);
	friend std::ostream& operator<<(std::ostream& out, const Stud& student);

	//metodu perdengimas
	void input(Stud& Lok);
	void input(const string& fileName, const int& number);
	void input(const string& fileName, list <Stud>& stud);
	void output(list<Stud>& stud, int choice);
	void output(list<Stud>& stud);
	void output(const string& fileName, list<Stud>& stud);

	~Stud() {}//I. destruktorius

	//II. copy constructor
	Stud(const Stud& copy) {
		vardas = copy.vardas;
		pavarde = copy.pavarde;
		ND = copy.ND; 
		vid = copy.vid;
		med = copy.med;
		egz = copy.egz;
	}

	///III. copy ssigment
	Stud& operator=(const Stud& other) {
		if (this != &other) {
			vardas = other.vardas;
			pavarde = other.pavarde;
			ND = other.ND;
			vid = other.vid;
			med = other.med;
			egz = other.egz;
		}
		return *this;
	}
};

void val(Stud& Lok);
void finalgrade(Stud& Lok);
double median(const vector <int>& ND);
double mean(const vector <int>& ND);
void grouping1(list<Stud>& smart, list<Stud>& dumb, list<Stud>& list);
void grouping2(list<Stud>& smart, list<Stud>& list);
void grouping3(list<Stud>& smart, list<Stud>& list);
bool sortByName(Stud& a, Stud& b);
bool sortBySurname(Stud& a, Stud& b);
bool sortDecending(Stud& a, Stud& b);
bool sortAscending(Stud& a, Stud& b);
void sortByChoice(list<Stud>& stud, const int& choice);
void demonstration();
