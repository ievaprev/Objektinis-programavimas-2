#include "Stud.h"

void ived(Stud &Lok) 
{
	//cout << "Input Student Name, Surname and egzam points: ";
	cin >> Lok.vardas >> Lok.pavarde;
	cout << "How many homework greades will you enter? " << endl;
	int k, grade;
	cin >> k;
	cout << "Enter homework grades and exam grade at the end:" << endl;
	for (int i = 0; i < k; i++)
	{
		cin >> grade;
		Lok.ND.push_back(grade);
	}
	cin >> Lok.egz;
	
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
