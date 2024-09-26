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

void outputMean(Stud &Lok)
{
	cout << setw(15) << left << Lok.vardas << setw(15) << left << Lok.pavarde 
		<< setw(3) << right << fixed << setprecision(2) << Lok.vid << endl;
}

void outputMedian(Stud& Lok)
{
	cout << setw(15) << left << Lok.vardas << setw(15) << left << Lok.pavarde
		<< setw(3) << right << fixed << setprecision(2) << Lok.med<< endl;
}
	

void val(Stud &Lok)
{
	Lok.vardas.clear();
	Lok.pavarde.clear();
	Lok.ND.clear();
}

void finalgrade(Stud &Lok)
{
	Lok.med = 0.4 * median(Lok.ND) + 0.6 * Lok.egz;
	Lok.vid = 0.4 * mean(Lok.ND) + 0.6 * Lok.egz;
}

double median(const vector <int>& ND)
{
	double med;
	vector<int> sortedND = ND;
	sort(sortedND.begin(), sortedND.end());
	size_t elements = ND.size();
	if (elements % 2 == 0) {
		med = (ND[elements / 2 - 1] + ND[elements / 2]) / 2.0;
	}
	else {
		med = ND[elements / 2];
	}
	return med;
}

double mean(const vector <int>& ND)
{
	double vidurkis;
	size_t elements = ND.size();
	int sum = 0;
	for (int i = 0; i < elements; i++)
	{
		sum = sum + ND[i];
	}
	vidurkis = double(sum) / elements;

	return vidurkis;
}
