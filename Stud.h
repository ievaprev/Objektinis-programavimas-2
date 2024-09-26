#include "Mylib.h"

struct Stud {
	std::string vardas, pavarde;
	std::vector<double>ND;
	double vid, med, egz, rez;
};

void ived(Stud &Lok);
void output(Stud& Lok);
void val(Stud &Lok);
void finalgrade(Stud &Lok);
void median(Stud& Lok);
