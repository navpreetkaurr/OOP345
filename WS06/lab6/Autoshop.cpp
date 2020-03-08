// Name: Navpreet Kaur
// Seneca Student ID: 148332182
// Seneca email: nk79
// Date of completion: 4 march, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include "Autoshop.h"
#include<vector>
namespace sdds {
	Autoshop& sdds::Autoshop::operator+=(Vehicle* v)
	{
		m_vehicles.push_back(v);
		return *this;
	}
	void Autoshop::display(std::ostream& os) const
	{
		os << "--------------------------------\n";
		os << "| Cars in the autoshop!        |\n";
		os << "--------------------------------\n";
		if (m_vehicles.size() != 0) {
			for (auto i = m_vehicles.begin(); i != m_vehicles.end(); i++) {
				(*i)->display(os);
			}
		}
		else {
			os << "Empty Project";
		}
		os << "--------------------------------\n";
	}
}