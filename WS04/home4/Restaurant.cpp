// Name: Navpreet Kaur
// Seneca Student ID: 148332182
// Seneca email: nk79@myseneca.ca
// Date of completion: 9 feb,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<iomanip>
#include<cstring>

#include "Restaurant.h"

using namespace std;

namespace sdds {
	Restaurant::Restaurant()
	{
		m_reservations = nullptr;
		m_count = 0u;
	}
	Restaurant::Restaurant(const Restaurant& src)
	{
		m_reservations = nullptr;
		delete[] m_reservations;
		if (this != &src) {
			m_count = src.m_count;
			m_reservations = new Reservation[m_count];
			for (size_t j = 0u; j < m_count; j++) {
				m_reservations[j] = src.m_reservations[j];
			}
		}
	}

	Restaurant::Restaurant( Restaurant&& src)
	{
		m_reservations = nullptr;
		delete[] m_reservations;
		if (this != &src) {
			m_count = src.m_count;
			m_reservations = new Reservation[m_count];
			for (size_t i = 0u; i < m_count; i++) {
				m_reservations[i] = src.m_reservations[i];
			}
			src.m_count = 0u;
			src.m_reservations = nullptr;
		}
	}
	Restaurant::Restaurant(Reservation* reservations[], size_t cnt)
	{
		m_reservations = nullptr;
		m_count = 0u;
		delete[] m_reservations;
		m_reservations = new Reservation[cnt];
		for (size_t i = 0u; i < cnt; i++) {
			m_reservations[i] = *reservations[i];
			m_count++;
		}
	}
	void Restaurant::display(ostream& os)const
	{
		if (m_count == 0) {
			os << "--------------------------" << endl;
			os << "Fancy Restaurant" << endl;
			os << "--------------------------" << endl;
			os << "The object is empty!" << endl;
			os << "--------------------------" << endl;
		}
		else {
			os << "--------------------------" << endl;
			os << "Fancy Restaurant" << endl;
			os << "--------------------------" << endl;
			for (size_t i = 0u; i < m_count; i++) {
				os << m_reservations[i];
			}
			os << "--------------------------" << endl;
		}
	}
	void operator<<(ostream& os, Restaurant& src)
	{
		src.display(os);
	}
	Restaurant::~Restaurant()
	{
		delete[] m_reservations;
		m_reservations = nullptr;
	}
	size_t Restaurant::size()
	{
		return m_count;
	}

}