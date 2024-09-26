#include "Mylib.h"
#include "Stud.h"

int main()
{
    vector<Stud> Vec1;
    Stud Temp;
    cout << "How many students you have: ";
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
    cout << "Do you want to see the median or mean of the final grade? (0 - mean, 1 - median)"  << endl;
    int choice;
    cin >> choice; 
    cout << setw(15) << left << "Student Name" << setw(15) << left << "Surname"<< setw(3) << right << "Final grade" << endl;
    
    for (int i = 0; i < n; i++)
    {
        if (choice == 0)
        {
            outputMean(Vec1.at(i));
        }
        else if (choice == 1)
        {
            outputMedian(Vec1.at(i));
        }
        else
        {
            cout << "Invalid choice!" << endl;
            return 1;
        }
    }
    system("pause");
}
