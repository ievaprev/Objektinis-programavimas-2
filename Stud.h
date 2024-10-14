#include "Mylib.h"

struct Stud {
	string vardas, pavarde;
	vector<int>ND;
	double vid, med, egz;
};

void ived(Stud& Lok);
void outputMean(Stud& Lok);
void outputMedian(Stud& Lok);
void val(Stud& Lok);
void finalgrade(Stud& Lok);
void readFile(const string& fileName, vector <Stud>& stud);
double median(const vector <int>& ND);
double mean(const vector <int>& ND);
void generateFile(const string& fileName, const int& number); 
void grouping(vector<Stud>& smart, vector<Stud>& dumb, Stud& Lok);
void sort(vector<Stud>& smart, vector<Stud>& dumb, const int& choice);
void outputFile(vector<Stud>& stud);
void outputInFile(const string& fileName, vector<Stud>& stud);
