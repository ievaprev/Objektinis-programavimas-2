#include "Stud.h"

void ived(Stud &Lok) 
{
	cin >> Lok.vardas >> Lok.pavarde;
	cout << "How many homework greades will you enter? " << endl;
	int k, grade;
	cin >> k;
	cout << "Enter homework grades:" << endl;
	for (int i = 0; i < k; i++)
	{
		cin >> grade;
		Lok.ND.push_back(grade);
	}
	cout << "Enter exam points: ";
	cin >> Lok.egz;
	
}

void output(Stud &Lok)
{
	cout << setw(15) << left << Lok.vardas << setw(15) << left << Lok.pavarde 
	<< setw(3) << right << fixed << setprecision(2) << Lok.rez << endl;
}

void val(Stud &Lok)
{
	Lok.vardas.clear();
	Lok.pavarde.clear();
	Lok.ND.clear();
}

void finalgrade(Stud &Lok)
{
	int elements = Lok.ND.size();
	int sum = 0;
	for (int i = 0; i < elements; i++)
	{
		sum = sum + Lok.ND[i];
	}
	Lok.vid = double(sum / elements);
	Lok.rez= 0.4 * Lok.vid + 0.6 * Lok.egz;
}

void median(Stud &Lok)
{
	int elements = Lok.ND.size();
	if (elements % 2 == 0) {
		Lok.med = (Lok.ND[elements - 1] + Lok.ND[elements + 1]) / 2;
	}
	else {
		Lok.med = Lok.ND[elements / 2];
	}
}
