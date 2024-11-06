#include "Mylib.h"
#include "Stud.h"
#include "Timer.h"

int main(){

    list<Stud> List1;
    list<Stud> smart, dumb; 
    Stud Temp;

    /*
    textAts - the choice of whether you want to read information from a file or not
    genrAts - the choice of whether you want to generate new files or not
    whichAts - the choice of the files the user want to read information from
    sortAts - the choice of how the user wants to sort users
    n - number of students
    finalChoice - the choice of how the user wants to present final grade
    */
    int textAts, genrAts, whichAts, sortAts, n, finalChoice;

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
                generateFile("studentai" + to_string(b) + ".txt", b);
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

                    readFile("studentai" + to_string(b) + ".txt", List1);

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

                    sortByChoice(List1, sortAts);

                    Timer t;
                    for (Stud& Temp : List1) {
                        grouping(smart, dumb, Temp);
                    }
                    cout << "Studentu grupavimas uztruko: " << t.elapsed() << " s\n";

                    cout << "    " << endl;

                    

                    outputInFile("Smart studentai" + to_string(b) + ".txt", smart);
                    outputInFile("Dumb studentai" + to_string(b) + ".txt", dumb);

                    b *= 10;
                    system("pause");
                }

            }
            else {
                cout << "Pateikite failo varda: " << endl;
                cin >> textFile;
                readFile(textFile, List1);

                cout << setw(18) << left << "Pavarde" << setw(15) << left << "Vardas" 
                << setw(10) << right << "Galutinis (Vid.)" << "    "
                << setw(10) << right << "Galutinis (Med.)" << endl;
                for (Stud& student : List1) {
                    finalgrade(student);
                }
                outputFile(List1);
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
            ived(Temp);
            finalgrade(Temp);
            List1.push_back(Temp);
            val(Temp);
        }

        cout << "Ar norite galutini ivertinima skaiciuoti su mediana ar vidurkiu? (0 - vidurkiu, 1 - mediana)"  << endl;
       
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
    
        cout << setw(18) << left << "Studento vardas" << setw(15) << left << "Pavarde" 
            << setw(15) << left << "Galutinis bal." << setw(15) << left << "Struct Adresas" << endl;

        if (finalChoice == 0){
            outputMean(List1);
        }
        else if (finalChoice == 1){
            outputMedian(List1);
        }
    }
}