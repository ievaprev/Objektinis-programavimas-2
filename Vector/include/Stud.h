#include "Mylib.h"

class Stud {
private:
	string vardas, pavarde;
public:
	vector<int>ND;
	double vid, med, egz;

	Stud() : egz(0) { }
	Stud(std::istream& is);
	void setName(string tempVardas) {
		vardas = tempVardas;}
	inline string getName() const { return vardas;}
	void setLastName(string tempPavarde) { 
		pavarde = tempPavarde; }
	inline string getLastName() const { return pavarde;}
	std::istream& readStudent(std::istream&);

	~Stud() = default;

};

void ived(Stud& Lok);
void outputMean(vector<Stud>& stud);
void outputMedian(vector<Stud>& stud);
void val(Stud& Lok);
void finalgrade(Stud& Lok);
void readFile(const string& fileName, vector <Stud>& stud);
double median(const vector <int>& ND);
double mean(const vector <int>& ND);
void generateFile(const string& fileName, const int& number); 
void grouping1(vector<Stud>& smart, vector<Stud>& dumb, vector<Stud>& list);
void grouping2(vector<Stud>& smart, vector<Stud>& list);
void grouping3(vector<Stud>& smart, vector<Stud>& list);
bool sortByName(Stud& a, Stud& b);
bool sortBySurname(Stud& a, Stud& b);
bool sortDecending(Stud& a, Stud& b);
bool sortAscending(Stud& a, Stud& b);
void sortByChoice(vector<Stud>& stud, const int& choice);
void outputFile(vector<Stud>& stud);
void outputInFile(const string& fileName, vector<Stud>& stud);
