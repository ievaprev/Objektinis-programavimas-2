#include "Stud.h"


void ived(Stud &Lok) 
{
	cin >> Lok.vardas >> Lok.pavarde;
	cout << "Ar noretumete automatiskai sugeneruoti namu darbu ir egzamino rezultatus? (0 - taip, 1 - ne) " << endl;
	int gchoice;
	while (true) {
		try {
			if (!(cin >> gchoice)) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				throw invalid_argument("Klaida: prasome ivesti skaiciu, o ne raide.");
			}

			if (gchoice != 0 && gchoice != 1) {
				throw runtime_error("Klaida: prasome pasirinkti 0 - taip arba 1 - mne.");
			}

			break;
		}
		catch (const exception& e) {
			cerr << e.what() << endl;
		}
	}

	if (gchoice == 0) {

		int NDnumber = (rand() % 10) + 1;
		for (int i = 0; i < NDnumber; i++) {
			Lok.ND.push_back(rand() % 10 + 1);
		}

		Lok.egz = 1 + (rand() % 10);
	}
	else if (gchoice == 1) {

		cout << "Iveskite namu darbu rezultatus (noredami uzbaigti spauskite 0 ir enter):" << endl; 

		int grade;

		while (true) {
			try {

				if (!(cin >> grade)) { 
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
					throw invalid_argument("Klaida: prasome ivesti skaiciu.");  
				}

				if (grade == 0) {
					break; 
				}
				else if (grade >= 1 && grade <= 10) {
					Lok.ND.push_back(grade); 
				}
				else {
					throw out_of_range("Pazimys turi buti nuo 1 iki 10.");  
				}
			}
			catch (const exception& e) {
				cout << e.what() << endl; 
				cin.clear(); 
				cin.ignore(numeric_limits<streamsize>::max(), '\n');  
			}
		}

		cout << "Iveskite egzamino ivertinima: " << endl;

		while (true) {
			try {
				if (!(cin >> Lok.egz)) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					throw invalid_argument("Klaida: prasome ivesti skaiciu, o ne raide.");
				}

				if (Lok.egz < 1 || Lok.egz > 10) {
					throw runtime_error("Klaida: prasome ivesti skaiciu nuo 1 iki 10.");
				}

				break;
			}
			catch (const exception& e) {
				cerr << e.what() << endl;

			}
		}
	}
}

void outputMean(Stud &Lok)
{
	cout << setw(18) << left << Lok.vardas << setw(15) << left << Lok.pavarde 
		<< setw(3) << right << fixed << setprecision(2) << Lok.vid << endl;
}

void outputMedian(Stud& Lok)
{
	cout << setw(18) << left << Lok.vardas << setw(15) << left << Lok.pavarde
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
	if (ND.empty())
		return 0;
	double med;
	vector<int> sortedND = ND;
	sort(sortedND.begin(), sortedND.end());
	size_t elements = ND.size();
	if (elements % 2 == 0) {
		med = (sortedND[elements / 2 - 1] + sortedND[elements / 2]) / 2.0;
	}
	else {
		med = sortedND[elements / 2];
	}
	return med;
}

double mean(const vector <int>& ND)
{
	if (ND.empty())
		return 0;
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
