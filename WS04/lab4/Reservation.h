// Name: Navpreet Kaur
// Seneca Student ID: 148332182
// Seneca email: nk79
// Date of completion: 04 Feb,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#pragma once
#ifndef SDDS_RESERVATION_H__
#define SDDS_RESERVATION_H__

#include<string>
using namespace std;
namespace sdds {
	class Reservation {
		string reservation_id;
		string res_name;
		string email;
		size_t noOfPeople;
		int day;
		int hour;
	public:
		Reservation();
		Reservation(const std::string& res);
		friend void operator<<(std::ostream& os, const Reservation& obj);
	};
	
}
#endif