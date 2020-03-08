// Name: Navpreet Kaur
// Seneca Student ID: 148332182
// Seneca email: nk79
// Date of completion: 8 march, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <iostream>
#include <iomanip>
#include <sstream>
#include "Racecar.h"
namespace sdds {
	bool Racecar::debug = false;
	void Racecar::setToEmpty()
	{
		if (debug) std::cout << "Race car set to safe empty state" << std::endl;
		m_booster = 0;
	}

	Racecar::Racecar() : Car()
	{
		setToEmpty();
	}

	Racecar::Racecar(std::istream& is) : Car(is)
	{
		if (debug) std::cout << "-------------- Racecar Constructor (istream&) Called -------------------" << std::endl;
		setToEmpty();
		std::string token;
		std::getline(is, token); 
		if (debug) std::cout << "token before trim : " << token << std::endl;
		Car::Trim(token);
		if (debug) std::cout << "Token after TRIM : " << std::endl;
		if (!token.empty()) {
			if (debug) std::cout << "m_booster Token : " << token << std::endl;
			if (Car::isAnInt(token))
				m_booster = stod(token);
		}
		if (debug) std::cout << "-------------- Racecar Constructor (istream&) Called -------------------" << std::endl << std::endl;
	}

	void Racecar::display(std::ostream& os) const
	{
		std::string line;
		std::stringstream ss;
		Car::display(ss); 
		line = ss.str();
		line = line.substr(0, 23);
		os << line;
		os << " " << std::setw(6) << std::setprecision(2) << std::fixed << this->topSpeed();
		os << " |*";
	}

	double Racecar::topSpeed() const
	{
		return Car::topSpeed() + (Car::topSpeed() * m_booster);
	}
}