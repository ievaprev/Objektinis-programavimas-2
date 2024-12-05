#include "Mylib.h"
#include "Human.h"

class Stud : public Human {
public:
	vector<int>ND;
	double vid, med, egz;

	Stud() : vid(0), med(0), egz(0) {}
	Stud(string vardas, string pavarde, vector<int> nd, int egz) : 
		 Human(vardas,pavarde), ND(nd), egz(egz), vid(0), med(0) {}

	Stud(std::istream& is) : Stud() { 
		is >> *this;
	}

	//operatoriai
	friend istream& operator>>(istream& in, Stud& student);
	friend ostream& operator<<(ostream& out, const Stud& student);

	//metodu perdengimas
	void input(Stud& Lok);
	void input(const string& fileName, const int& number);
	void input(const string& fileName, list <Stud>& stud);
	void output(list<Stud>& stud, int choice);
	void output(const string& fileName, list<Stud>& stud);

	~Stud() { ND.clear(); }//I. destruktorius

	//II. copy constructor
	Stud(const Stud& copy) 
		: Human(copy), 
			ND(copy.ND),
			vid(copy.vid),
			med(copy.med),
			egz(copy.egz){}

	///III. copy ssigment
	Stud& operator=(const Stud& other) {
		if (this != &other) {
			Human::operator=(other);
			ND = other.ND;
			vid = other.vid;
			med = other.med;
			egz = other.egz;
		}
		return *this;
	}

	void whoAmI() const { std::cout << "As esu is Stud klasės\n"; }
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
