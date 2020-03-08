// Name: Navpreet Kaur
// Seneca Student ID: 148332182
// Seneca email: nk79
// Date of completion: 8 march, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include "Autoshop.h"
namespace sdds {
	Autoshop& sdds::Autoshop::operator+=(Vehicle* theVehicle)
	{
		m_vehicles.push_back(theVehicle);
		return *this;
	}
	void Autoshop::display(std::ostream& os) const
	{
		os << "--------------------------------" << std::endl;
		os << "| Cars in the autoshop!        |" << std::endl;
		os << "--------------------------------" << std::endl;

		for (auto& obj : m_vehicles) {
			obj->display(os);
			os << std::endl;
		}
		os << "--------------------------------" << std::endl;
	}
	Autoshop::~Autoshop()
	{
		for (auto& obj : m_vehicles)
			delete obj;
	}
}
