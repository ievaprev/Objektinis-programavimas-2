#include "Stud.h"

void ived(Stud &Lok) 
{
	cout << "Input Student Name, Surname and egzam points: ";
	cin >> Lok.vardas >> Lok.pavarde >> Lok.egz;
}

void output(Stud &Lok)
{
	cout << setw(15) << left << Lok.vardas << setw(15) << left << Lok.pavarde << setw(3) << right << Lok.egz << endl;
}

void val(Stud &Lok)
{
	Lok.vardas.clear();
	Lok.pavarde.clear();
	Lok.ND.clear();
}