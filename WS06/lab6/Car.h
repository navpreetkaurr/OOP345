// Name: Navpreet Kaur
// Seneca Student ID: 148332182
// Seneca email: nk79
// Date of completion: 4 march, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_CAR_H
#define SDDS_CAR_H


#include <string>
#include <istream>
#include "Vehicle.h"

namespace sdds {
	enum  Car_Condition : char { Brand_New = 'n', Used = 'u', Broken = 'b', Empty_Safe_State = 's' };

	class Car : public Vehicle
	{
		std::string m_manufacture;
		Car_Condition m_condition;
		double m_top_speed;
		bool isEmpty;
		static std::string delim;
		static bool debug; //used for debugging reasons :)
		void SetToSafeEmptyState();
	public:

		Car();
		Car(std::istream& is);
		~Car();
		std::string getDelim() const;
		bool isAnInt(std::string src) const;
		void Trim(std::string& src);
		double topSpeed() const;
		void display(std::ostream& os) const;
		std::string condition() const;
	};
}
#endif // !SDDS_CAR_H
