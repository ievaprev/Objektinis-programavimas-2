#include "Mylib.h"
#include "Stud.h"

int main()
{
    vector<Stud> Vec1;
    Stud Temp;
    cout << "How many students you have: " << endl;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) 
    {
        cout << "Please input user data (Student name, surname): " << endl;
        ived(Temp);
        finalgrade(Temp);
        Vec1.push_back(Temp);
        val(Temp);
    }
    cout << setw(15) << left << "Student Name" << setw(15) << left << "Surname"<< setw(3) << right << "Egzam points" << endl;
    for (int i = 0; i < n; i++) 
    {
        output(Vec1.at(i));
    }
    
    system("pause");
}

