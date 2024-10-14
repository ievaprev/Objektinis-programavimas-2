#include "Stud.h"
#include "Timer.h"

void readFile(const string& fileName, vector <Stud>& stud) {

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
	cout << "Failo nuskaitymas uztruko: " << r.elapsed() << " s\n";
}

void generateFile(const string& fileName, const int& number)
{
	Timer t;
	ofstream outfile(fileName);

	//header line
	outfile << setw(18) << left << "Studento vardas" << setw(18) << left << "Pavarde";
	for (int i = 1; i <= 15; i++) {
		outfile << setw(6) << right << "ND" + to_string(i);
	}
	outfile << setw(15) << right << "Egzamino rez" << endl;

	//student data
	for (int i = 1; i <= number; i++)
	{
		outfile << setw(18) << left << "Vardas" + to_string(i) << setw(18) << left << "Pavarde" + to_string(i);
		for (int j = 0; j < 15; j++) {
			outfile << setw(6) << right << (rand() % 10) + 1;
		}
		outfile << setw(15) << right << (rand() % 10) + 1 << endl;
	}

	outfile.close();

	cout << "Failas " << fileName << " uzdarytas" << endl;

	cout << "Failo generavimas uztruko: " << t.elapsed() << " s\n";

}

void outputFile(vector<Stud>& stud)
{
	sort(stud.begin(), stud.end(), [](const Stud& a, const Stud& b) {
		return a.vardas < b.vardas;
		});

	for (Stud& duom : stud)
	{
		cout << setw(18) << left << duom.pavarde << setw(15) << left << duom.vardas
			<< setw(3) << right << fixed << setprecision(2) << duom.vid << "                "
			<< setw(3) << right << fixed << setprecision(2) << duom.med << endl;
	}
}

void outputFile(const string& fileName, vector<Stud>& stud)
{
	Timer t; 

	ofstream outfile(fileName);

	for (Stud& duom : stud)
	{
		outfile << setw(18) << left << duom.pavarde << setw(15) << left << duom.vardas
			<< setw(3) << right << fixed << setprecision(2) << duom.vid;
	}

	outfile.close();

	cout << "Failo generavimas uztruko: " << t.elapsed() << " s\n";
}
