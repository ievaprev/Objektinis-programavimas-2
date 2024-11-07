#include "Stud.h"
#include "Timer.h"

void grouping1(list<Stud>& smart, list<Stud>& dumb, list<Stud>& list)
{
	Timer t;
	for (Stud& stud : list) {
		finalgrade(stud);
		if (stud.vid >= 5.0) {
			smart.push_back(stud);
		}
		else if (stud.vid < 5) {
			dumb.push_back(stud);
		}
	}
	cout << "Studentu grupavimas pagal 1 strategija uztruko: " << t.elapsed() << " s\n";
	
}
void grouping2(list<Stud>& smart, list<Stud>& list)
{
	Timer t;
	for (auto it = list.begin(); it != list.end(); ) {
		if (it->vid > 5) {
			smart.push_back(*it);
			it = list.erase(it);
		}
		else {
			++it;
		}
	}
	cout << "Studentu grupavimas uztruko: " << t.elapsed() << " s\n";
}
void grouping3(list<Stud>& smart, list<Stud>& list)
{
	Timer t;

	auto it = partition(list.begin(), list.end(), [](const Stud& s) { return s.vid > 5; });
	smart.splice(smart.end(), list, list.begin(), it);

	cout << "Studentu grupavimas uztruko: " << t.elapsed() << " s\n";
}