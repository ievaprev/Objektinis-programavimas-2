#include "Mylib.h"
#include "Stud.h"
#include "Timer.h"

int main() {

    vector<Stud> Vec1;
    vector<Stud> smart, dumb;
    Stud Temp;

    /*
    textAts - the choice of whether you want to read information from a file or not
    genrAts - the choice of whether you want to generate new files or not
    whichAts - the choice of the files the user want to read information from
    sortAts - the choice of how the user wants to sort users
    n - number of students
    finalChoice - the choice of how the user wants to present final grade
    strategy - is a choice for the user of which grouping strategy he wants to use
    */
    int textAts, genrAts, whichAts, sortAts, n, finalChoice, strategy;

    demonstration();

    cout << "Ar norite nuskaityti informacija is tekstinio failo? (0 - taip, 1 - ne)" << endl;

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
        cout << "Ar norite sugeneruoti naujus failus? (0 - taip, 1 - ne)" << endl;

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
                Temp.input("studentai" + to_string(b) + ".txt", b);
                b *= 10;
            }

        }
        else {

            cout << "Ar norite nuskaityti generuotus failus ar savo turimus?(0 - generuotus, 1 - turimus)" << endl;

            while (true) {
                try {
                    if (!(cin >> whichAts)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        throw invalid_argument("Klaida: prasome ivesti skaiciu, o ne raide.");
                    }

                    if (whichAts != 0 && whichAts != 1) {
                        throw runtime_error("Klaida: prasome pasirinkti viena is 4 variantu.");
                    }
                    break;
                }
                catch (const exception& e) {
                    cerr << e.what() << endl;
                }
            }
            if (whichAts == 0) {

                int b = 1000;

                for (int i = 0; i < 5; i++) {
                    cout << "----------------------------------" << endl;

                    Temp.input("studentai" + to_string(b) + ".txt", Vec1);

                    cout << "Pasirinkite pagal ka noretumete rusiuoti sugrupuotus studentus:\n1 - varda, 2 - pavarde, 3 - galutini rezultata maz., 4 - galutini rezultata did." << endl;

                    while (true) {
                        try {
                            if (!(cin >> sortAts)) {
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                throw invalid_argument("Klaida: prasome ivesti skaiciu, o ne raide.");
                            }

                            if (sortAts != 1 && sortAts != 2 && sortAts != 3 && sortAts != 4) {
                                throw runtime_error("Klaida: prasome pasirinkti viena is 4 variantu.");
                            }
                            break;
                        }
                        catch (const exception& e) {
                            cerr << e.what() << endl;
                        }
                    }
                    for (Stud& temp : Vec1) {
                        finalgrade(temp);
                    }

                    sortByChoice(Vec1, sortAts);

                    cout << "Pasirinkite grupavimo strategija: (Pasirinkimai 1, 2, 3)" << endl;
                    cin >> strategy;
                    if (strategy != 1 && strategy != 2 && strategy != 3) {
                        throw runtime_error("Klaida: prasome pasirinkti viena is 4 variantu.");
                    }
                    if (strategy == 1) {
                        grouping1(smart, dumb, Vec1);
                        cout << "    " << endl;
                        Temp.output("Smart studentai" + to_string(b) + ".txt", smart);
                        Temp.output("Dumb studentai" + to_string(b) + ".txt", dumb);
                    }
                    else if (strategy == 2) {
                        grouping2(smart, Vec1);
                        cout << "    " << endl;
                        Temp.output("Smart studentai" + to_string(b) + ".txt", smart);
                        Temp.output("Dumb studentai" + to_string(b) + ".txt", Vec1);
                    }
                    else if (strategy == 3) {
                        grouping3(smart, Vec1);
                        cout << "    " << endl;
                        Temp.output("Smart studentai" + to_string(b) + ".txt", smart);
                        Temp.output("Dumb studentai" + to_string(b) + ".txt", Vec1);
                    }

                    b *= 10;
                   
                }

            }
            else {
                cout << "Pateikite failo varda: " << endl;
                cin >> textFile;
                Temp.input(textFile, Vec1);

                cout << setw(18) << left << "Studento vardas" << setw(15) << left << "Pavarde"
                    << setw(15) << left << "Galutinis bal." << setw(15) << left << "Struct Adresas" << endl;
                for (Stud& student : Vec1) {
                    finalgrade(student);
                }
                Temp.output(Vec1, 1);
            }
        }
    }
    else if (textAts == 1) {

        cout << "Studentu skaicius: " << endl;

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
            Temp.input(Temp);
            finalgrade(Temp);
            Vec1.push_back(Temp);
            val(Temp);
        }

        cout << "Ar norite galutini ivertinima skaiciuoti su mediana ir vidurkiu ar tik su vidurkiu? (0 - tik vidurkis, 1 - ir mediana)" << endl;

        while (true) {
            try {
                if (!(cin >> finalChoice)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    throw invalid_argument("Klaida: prasome ivesti skaiciu, o ne raide.");
                }

                if (finalChoice != 0 && finalChoice != 1) {
                    throw runtime_error("Klaida: prasome pasirinkti 0 - vidurkiu arba 1 - mediana.");
                }

                break;
            }
            catch (const exception& e) {
                cerr << e.what() << endl;
            }
        }

        Temp.output(Vec1, finalChoice);
    }
}
