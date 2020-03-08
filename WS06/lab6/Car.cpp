// Name: Navpreet Kaur
// Seneca Student ID: 148332182
// Seneca email: nk79
// Date of completion: 4 march, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <algorithm>
#include <cctype>
#include <string>
#include <iostream>
#include <cctype>
#include <iomanip>
#include <functional>
#include "Car.h"
using namespace std;
namespace sdds {
	bool Car::debug = false;
	std::string Car::delim = ",";
	std::string Car::getDelim() const
	{
		return delim;
	}

	bool Car::isAnInt(std::string src) const { 
		bool isInt = (src.find_first_not_of("0123456789.") == std::string::npos);
		if (debug)  std::cout << "IsAnInt |" << src << "|" << (isInt ? "true" : "false");
		return isInt;
	};


	void Car::Trim(std::string& src) {
		if (!src.empty()) {
			while (src.at(0) == ' ')
				src = src.substr(1, src.length() - 1);
			while (src.at(src.length() - 1) == ' ')
				src = src.substr(0, src.length() - 1);
		}
	}

	void Car::SetToSafeEmptyState()
	{
		if (debug) cout << "Car Object set to an empty safe state" << std::endl;
		m_condition = Empty_Safe_State;
		m_manufacture = "EMPTY_STATE";
		m_top_speed = 0;
		isEmpty = true; 
	}

	Car::Car() 
	{
		if (debug) cout << "Default Constructor Called on Car Object" << endl;
		SetToSafeEmptyState();
	}

	Car::Car(std::istream& is)
	{
		if (debug) cout << "----------Car (std::istream& is ) -----------------------------------" << endl;
		*this = Car(); 
		isEmpty = false; 
		std::string token;
		std::string delim(",");
		auto isConditionValid = [&](char& c) { 
			if (debug) {

				cout << "Condition char sent : " << c << endl;
				cout << "Possible conditions : " << " " << Brand_New << " " << Used << " " << " " << Broken << endl;
			}
			bool isValid = (c == Brand_New || c == Used || c == Broken);
			if (debug) cout << "Condition is " << (isValid ? "True" : "False") << endl;
			return isValid; 
		};
		for (int i = 0; i < 4 && isEmpty == false; ++i) { 
			std::getline(is, token, ','); 
			if (i != 2) { 
				Trim(token);
			}
			if (debug) {
				cout << "i : " << i << endl;
				cout << "isEmpty : " << (isEmpty ? "True" : "False") << endl << endl;
				cout << "Token : " << token << endl;
			}
			switch (i) {
			case 0:
				if (debug) cout << "Tag Grabbed: " << token << endl;
				break;
			case 1:  //Set Manufacture 
				m_manufacture = token;
				if (debug) cout << "Manufacture : |" << m_manufacture << "|" << endl;
				break;
			case 2: //Set Condition
				if (token.find_first_not_of(' ') != std::string::npos) {
					Trim(token);
					if (isConditionValid(token[0])) {
						m_condition = Car_Condition(token[0]);
						if (debug) cout << "Condition : |" << m_condition << "|" << endl;
					}
					else {
						throw std::string("Invalid record!");
					}
				}
				else {
					m_condition = Brand_New;
				}
				break;
			case 3:
				if (isAnInt(token)) {
					m_top_speed = stol(token);
					if (debug) cout << "Top speed : " << m_top_speed << endl;
				}
				else {
					throw std::string("Invalid record!");
				}
				break;
			}
		}
		if (debug) cout << "----------------Car (std::istream& is) ended------------------------------" << endl << endl;
	}

	Car::~Car(){}

	double Car::topSpeed() const
	{
		return m_top_speed;
	}

	void Car::display(std::ostream& os) const
	{
		if (m_condition != Empty_Safe_State) {
			os << "| ";
			os << std::right << std::setw(10) << m_manufacture;
			os << " | ";
			os << std::left << std::setw(6) << condition();
			os << " | ";
			os << std::setw(6) << std::setprecision(2) << std::fixed << m_top_speed;
			os << " |";
			os << endl;
		}
		else {
			os << "EMPTY ITEM";
		}
	}

	std::string Car::condition() const //return condition
	{
		std::string cond = "Safe Empty State"; 
		if (m_condition == Car_Condition::Brand_New) {
			cond = "new";
		}
		else if (m_condition == Car_Condition::Used) {
			cond = "used";
		}
		else if (m_condition == Car_Condition::Broken) {
			cond = "broken";
		}
		return cond;
	}
}