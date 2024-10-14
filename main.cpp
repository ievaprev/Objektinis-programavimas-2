#include "Mylib.h"
#include "Stud.h"
#include "Timer.h"

int main()
{
    vector<Stud> Vec1;
    vector<Stud> smart, dumb; 
    Stud Temp;
    cout << "Ar norite nuskaityti informacija is tekstinio failo? (0 - taip, 1 - ne)" << endl;
    int textAts;
    string textFile; 

    while (true) {
        try {
            if (!(cin >> textAts)) {  
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                throw invalid_argument("Klaida: prasome ivesti skaiciu, o ne raide.");
            }

            if (textAts != 0 && textAts != 1) {  
                throw runtime_error("Klaida: prasome pasirinkti 0 - taip arba 1 - ne.");
            }

            break;  
        }
        catch (const exception& e) {
            cerr << e.what() << endl;  
  
        }
    }

    if (textAts == 0) {
        cout << "Ar norite sugeneruoti failus? (0 - taip, 1 - ne)" << endl;
        int genrAts;
        while (true) {
            try {
                if (!(cin >> genrAts)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    throw invalid_argument("Klaida: prasome ivesti skaiciu, o ne raide.");
                }

                if (genrAts != 0 && genrAts != 1) {
                    throw runtime_error("Klaida: prasome pasirinkti 0 - taip arba 1 - ne.");
                }

                break;
            }
            catch (const exception& e) {
                cerr << e.what() << endl;
            }
        }

        if (genrAts == 0) {
            int b = 1000;

            for (int i = 0; i < 5; i++)
            {
                generateFile("studentai" + to_string(b) + ".txt", b);
                readFile("studentai" + to_string(b) + ".txt", Vec1);

                Timer t;
                for (Stud& Temp : Vec1) {
                    grouping(smart, dumb, Temp);
                }
                cout << "Studentu grupavimas uztruko: " << t.elapsed() << " s\n";

                cout << "    " << endl;

                cout << "Pasirinkite pagal ka noretumete rusiuoti sugrupuotus studentus:\n1 - varda, 2 - pavarde, 3 - galutini rezultata maz., 4 - galutini rezultata did." << endl;
                int ats;
                while (true) {
                    try {
                        if (!(cin >> ats)) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            throw invalid_argument("Klaida: prasome ivesti skaiciu, o ne raide.");
                        }

                        if (ats != 1 && ats != 2 && ats != 3 && ats != 4) {
                            throw runtime_error("Klaida: prasome pasirinkti viena is 4 variantu.");
                        }
                        break;
                    }
                    catch (const exception& e) {
                        cerr << e.what() << endl;
                    }
                }

                sort(smart, dumb, ats);
                cout << "   " << endl;

                outputInFile("Smart studentai" + to_string(b) + ".txt", smart);
                outputInFile("Dumb studentai" + to_string(b) + ".txt", dumb);

                b *= 10;
                system("pause");
            }
            
        }
        else {
            cout << "Pateikite failo varda: " << endl;
            cin >> textFile;
            readFile(textFile, Vec1);

            cout << setw(18) << left << "Pavarde" << setw(15) << left << "Vardas" 
            << setw(10) << right << "Galutinis (Vid.)" << "    "
            << setw(10) << right << "Galutinis (Med.)" << endl;

            for (Stud& student : Vec1) {
                finalgrade(student);
            }
            outputFile(Vec1);

        }
    }
    else if (textAts == 1) {
        cout << "Studentu skaicius: " << endl;
        int n;

        while (true) {
            try {
                if (!(cin >> n)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    throw invalid_argument("Klaida: prasome ivesti skaiciu, o ne raide.");
                }
                break;
            }
            catch (const exception& e) {
                cerr << e.what() << endl;
            }
        }
        
        for (int i = 0; i < n; i++) 
        {
            cout << "Studento vardas, pavarde: " << endl;
            ived(Temp);
            finalgrade(Temp);
            Vec1.push_back(Temp);
            val(Temp);
        }

        cout << "Ar norite galutini ivertinima skaiciuoti su mediana ar vidurkiu? (0 - vidurkiu, 1 - mediana)"  << endl;
        int choice;
        while (true) {
            try {
                if (!(cin >> choice)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    throw invalid_argument("Klaida: prasome ivesti skaiciu, o ne raide.");
                }

                if (choice != 0 && choice != 1) {
                    throw runtime_error("Klaida: prasome pasirinkti 0 - vidurkiu arba 1 - mediana.");
                }

                break;
            }
            catch (const exception& e) {
                cerr << e.what() << endl;
            }
        }
    
        cout << setw(15) << left << "Studento vardas" << "   " << setw(15) << left << "Pavarde" << setw(3) << right << "Galutinis ivertinimas" << endl;

        for (int i = 0; i < n; i++)
        {
            if (choice == 0){
                outputMean(Vec1.at(i));
            }
            else if (choice == 1){
                outputMedian(Vec1.at(i));
            }
        }
    }
}

