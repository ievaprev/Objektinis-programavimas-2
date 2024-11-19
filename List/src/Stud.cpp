#include "Stud.h"
#include "Timer.h"

Stud::Stud(std::istream& is) {

	readStudent(is);
}
std::istream& Stud::readStudent(std::istream& is) {
	string name, lastName;

	is >> lastName >> name;
	setLastName(lastName);
	setName(name);

	ND.clear();
	int grade;

	while (is >> grade) {
		if (grade < 1 || grade > 10) {
			throw std::runtime_error("Error: ND score must be between 1 and 10");
		}
		ND.push_back(grade);
	}

	if (ND.empty()) {
		throw std::runtime_error("Error: No ND scores found for student");
	}

	egz = ND.back();
	ND.pop_back();

	return is;
}

void ived(Stud &Lok) 
{
	string vardas, pavarde;
	cin >> vardas >> pavarde;
	Lok.setName(vardas);
	Lok.setLastName(pavarde);

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
				throw runtime_error("Klaida: prasome pasirinkti 0 - taip arba 1 - ne.");
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

void outputMean(list<Stud>& stud)
{
	for(const Stud& student : stud)
		cout << setw(18) << left << student.getName() << setw(15) << left << student.getLastName()
		<< setw(15) << left << fixed << setprecision(2) << student.vid << setw(15) << left << &student << endl;
}

void outputMedian(list<Stud>& stud)
{
	for (const Stud& student : stud)
		cout << setw(18) << left << student.getName() << setw(15) << left << student.getLastName()
		<< setw(15) << left << fixed << setprecision(2) << student.med << setw(15) << left << &student << endl;

}
	

void val(Stud &Lok)
{
	Lok.setName("");
	Lok.setLastName("");
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

bool sortByName(Stud& a, Stud& b) {
	return a.getName() < b.getName();
}
bool sortBySurname(Stud& a, Stud& b) {
	return a.getLastName() < b.getLastName();
}
bool sortDecending(Stud& a, Stud& b) {
	return a.vid > b.vid;
}
bool sortAscending(Stud& a, Stud& b) {
	return a.vid < b.vid;
}
void sortByChoice(list<Stud>& stud, const int& choice) {
	Timer t;

	if (choice == 1) {
		stud.sort(sortByName);
	}
	else if (choice == 2) {
		stud.sort(sortBySurname);
	}
	else if (choice == 3) {
		stud.sort(sortDecending);
	}
	else if (choice == 4) {
		stud.sort(sortAscending);
	}

	cout << "Surikiuoti studentus, pagal jusu pasirinkima, uztruko: " << t.elapsed() << " s\n" << endl;
}
