// Name: Navpreet Kaur
// Seneca Student ID: 148332182
// Seneca email: nk79
// Date of completion: 04 Feb,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#pragma once
#ifndef SDDS_RESTAURANT_H__
#define SDDS_RESTAURANT_H__

#include<string>
#include"Reservation.h"
using namespace std;
namespace sdds {
	class Restaurant{
		Reservation* m_reservations;
		size_t m_count;
	public:
		Restaurant();
		Restaurant(Reservation* reservations[], size_t cnt);
		Restaurant(const Restaurant&);
		Restaurant( Restaurant&&);
		size_t size();
		void display(ostream& os)const;
		friend void operator<<(ostream&, Restaurant&);
		~Restaurant();
	};
}
#endif