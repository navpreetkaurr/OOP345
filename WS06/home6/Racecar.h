// Name: Navpreet Kaur
// Seneca Student ID: 148332182
// Seneca email: nk79
// Date of completion: 8 march, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef _SDDS_RACECAR_H
#define _SDDS_RACECAR_H
#include <iostream>
#include "Car.h"
namespace sdds {
	class Racecar : public Car {
		double m_booster;
		static bool debug; 
		void setToEmpty();
	public:
		Racecar();
		Racecar(std::istream& is);
		void display(std::ostream& os) const;
		double topSpeed() const;
	};
}
#endif