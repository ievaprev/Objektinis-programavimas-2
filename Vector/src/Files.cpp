#include "Stud.h"
#include "Timer.h"


void Stud::input(const string& fileName, vector<Stud>& stud) {

	Timer r;
	ifstream inFile(fileName);

	try {
		if (!inFile.is_open()) {
			throw runtime_error("Error: unable to open file: " + fileName);
		}

		string line;
		getline(inFile, line);

		while (getline(inFile, line)) {
			istringstream iss(line);

			Stud Lok1(iss);  //copy constructor
			stud.push_back(Lok1);
		}

		inFile.close();
	}
	catch (const exception& e) {
		cerr << e.what() << endl;
		exit(EXIT_FAILURE);
	}

	cout << "Failo " << fileName << " nuskaitymas uztruko : " << r.elapsed() << " s\n";
}


void Stud::input(const string& fileName, const int& number)
{
	Timer t;

	stringstream input; 

	input << setw(18) << left << "Studento vardas" << setw(18) << left << "Pavarde";
	for (int i = 1; i <= 15; i++) {
		input << setw(6) << right << "ND" + to_string(i);
	}
	input << setw(15) << right << "Egzamino rez" << endl;

	for (int i = 1; i <= number; i++)
	{
		input << setw(18) << left << "Vardas" + to_string(i) << setw(18) << left << "Pavarde" + to_string(i);
		for (int j = 0; j < 15; j++) {
			input << setw(6) << right << (rand() % 10) + 1;
		}
		input << setw(15) << right << (rand() % 10) + 1 << endl;
	}

	ofstream outfile(fileName);

	if (!outfile.is_open()) {
		cerr << "Error: unable to open file: " << fileName << endl;
		return; 
	}

	outfile << input.str();
	outfile.flush();
	outfile.close();

	cout << "----------------------------------------------------" << endl;

	cout << "Failas " << fileName << " uzdarytas" << endl;

	cout << "     " << endl;

	cout << "Failo generavimas uztruko: " << t.elapsed() << " s\n";

}

void Stud::output(const string& fileName, vector<Stud>& stud)
{
	Timer t; 
	stringstream input;
	

	input << setw(18) << left << "Pavarde" << setw(15) << left << "Vardas"
		<< setw(10) << right << "Galutinis (Vid.)" << endl;


	for (Stud& duom : stud)
	{
		input << setw(18) << left << duom.getLastName() << setw(15) << left << duom.getName()
			<< setw(3) << right << fixed << setprecision(2) << duom.vid << endl;
	}

	ofstream outfile(fileName);
	outfile << input.str();
	outfile.flush();
	outfile.close();

	cout << "Suskirstytu studentu irasymas i " << fileName << " faila utruko: " << t.elapsed() << " s\n";
}
