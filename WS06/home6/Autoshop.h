// Name: Navpreet Kaur
// Seneca Student ID: 148332182
// Seneca email: nk79
// Date of completion: 8 march, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H
#include <vector>
#include <list>
#include "Car.h"
namespace sdds {
	class Autoshop
	{
		std::vector<Vehicle*> m_vehicles;
	public:
		template<typename T>
		void select(T test, std::list<const Vehicle*>& vehicles) {

			for (auto& obj : m_vehicles)
				if (test(obj))
					vehicles.push_back(obj);
		}
		Autoshop& operator+=(Vehicle* theVehicle);
		void display(std::ostream& os) const;
		~Autoshop();
	};
}
#endif