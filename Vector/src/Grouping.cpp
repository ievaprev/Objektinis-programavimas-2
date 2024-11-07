#include "Stud.h"
#include "Timer.h"

void grouping1(vector<Stud>& smart, vector<Stud>& dumb, vector<Stud>& vec)
{
	Timer t;
	for (Stud& stud : vec) {
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
void grouping2(vector<Stud>& smart, vector<Stud>& vec)
{
	Timer t;

	auto it = vec.begin();
	while (it != vec.end()) {
		if (it->vid > 5) {
			smart.push_back(move(*it));  
			*it = move(vec.back());     
			vec.pop_back();              
		}
		else {
			++it; 
		}
	}

	cout << "Studentu grupavimas uztruko: " << t.elapsed() << " s\n";
}
void grouping3(vector<Stud>& smart, vector<Stud>& vec)
{
	Timer t;

	auto it = std::partition(vec.begin(), vec.end(), [](const Stud& s) { return s.vid > 5; });
	smart.insert(smart.end(), make_move_iterator(vec.begin()), make_move_iterator(it));

	vec.erase(vec.begin(), it);

	cout << "Studentu grupavimas uztruko: " << t.elapsed() << " s\n";
}