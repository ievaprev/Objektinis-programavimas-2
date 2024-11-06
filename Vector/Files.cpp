#include "Stud.h"
#include "Timer.h"

void readFile(const string& fileName, vector<Stud>& stud) {

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
			Stud Lok1;
			int score;

			iss >> Lok1.pavarde >> Lok1.vardas;

			Lok1.ND.clear();
			while (iss >> score) {
				Lok1.ND.push_back(score);
			}

			if (Lok1.ND.empty()) {
				cerr << "Error: No ND scores found in line " << endl;
				continue;
			}
			for (int i = 0; i < Lok1.ND.size(); i++) {
				if (Lok1.ND.at(i) < 1 || Lok1.ND.at(i) > 10) {
					throw runtime_error("Error: ND score must be between 1 and 10");
				}
			}

			Lok1.egz = Lok1.ND.back();
			Lok1.ND.pop_back();

			stud.push_back(Lok1);

		}
		inFile.close();
	}
	catch (exception& e) {
		cerr << e.what() << endl;
		exit(EXIT_FAILURE);
	}

	cout << "Failo " << fileName <<" nuskaitymas uztruko : " << r.elapsed() << " s\n";
}


void generateFile(const string& fileName, const int& number)
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

void outputFile(vector<Stud>& stud)
{
	sort(stud.begin(), stud.end(), sortByName);

	for (Stud& duom : stud)
	{
		cout << setw(18) << left << duom.pavarde << setw(15) << left << duom.vardas
			<< setw(3) << right << fixed << setprecision(2) << duom.vid << "                "
			<< setw(3) << right << fixed << setprecision(2) << duom.med << endl;
	}
}

void outputInFile(const string& fileName, vector<Stud>& stud)
{
	Timer t; 
	stringstream input;
	

	input << setw(18) << left << "Pavarde" << setw(15) << left << "Vardas"
		<< setw(10) << right << "Galutinis (Vid.)" << endl;


	for (Stud& duom : stud)
	{
		input << setw(18) << left << duom.pavarde << setw(15) << left << duom.vardas
			<< setw(3) << right << fixed << setprecision(2) << duom.vid << endl;
	}

	ofstream outfile(fileName);
	outfile << input.str();
	outfile.flush();
	outfile.close();

	cout << "Suskirstytu studentu irasymas i " << fileName << " faila utruko: " << t.elapsed() << " s\n";
}