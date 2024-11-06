#include "Mylib.h"

struct Stud {
	string vardas, pavarde;
	vector<int>ND;
	double vid, med, egz;
};

void ived(Stud& Lok);
void outputMean(list<Stud>& stud);
void outputMedian(list<Stud>& stud);
void val(Stud& Lok);
void finalgrade(Stud& Lok);
void readFile(const string& fileName, list <Stud>& stud);
double median(const vector <int>& ND);
double mean(const vector <int>& ND);
void generateFile(const string& fileName, const int& number); 
void grouping1(list<Stud>& smart, list<Stud>& dumb, list<Stud>& list);
void grouping2(list<Stud>& smart, list<Stud>& list);
void grouping3(list<Stud>& smart, list<Stud>& list);
bool sortByName(Stud& a, Stud& b);
bool sortBySurname(Stud& a, Stud& b);
bool sortDecending(Stud& a, Stud& b);
bool sortAscending(Stud& a, Stud& b);
void sortByChoice(list<Stud>& stud, const int& choice);
void outputFile(list<Stud>& stud);
void outputInFile(const string& fileName, list<Stud>& stud);
