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
#include "ConfirmationSender.h"
using namespace std;

namespace sdds {
	size_t ConfirmationSender::s()
	{
		return count;
	}
	ConfirmationSender::ConfirmationSender()
	{
		preservation = nullptr;
		count = 0u;
	}
	ConfirmationSender::ConfirmationSender(const ConfirmationSender& src)
	{
		*this = src;
	}
	ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& src)
	{
		count = src.count;
		preservation = nullptr;
		delete[] preservation;
		preservation = new const Reservation * [count];
		for (size_t i = 0u; i < count; i++) {
			preservation[i] = src.preservation[i];
		}
		return *this;

	}
	ConfirmationSender::ConfirmationSender(ConfirmationSender&& src)
	{
		*this = move(src);
	}
	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& src)
	{
		count = src.count;
		preservation = nullptr;
		delete[] preservation;
		preservation = new const Reservation * [count];
		for (size_t i = 0u; i < count; i++) {
			preservation[i] = src.preservation[i];
		}
		src.preservation = nullptr;
		src.count = 0u;
		return *this;

	}
	ConfirmationSender::~ConfirmationSender()
	{
		delete[] preservation;
	}
	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res)
	{
		int counter = 0;
		for (size_t i = 0u; i < count; i++) {
			if (preservation[i] == &res) {
				counter = 1;
			}
			else {
				counter = 0;
			}
		}
		if (counter == 0) {
			ConfirmationSender temp = *this;
			delete[] preservation;
			count++;
			preservation = new const Reservation * [count];
			for (size_t i = 0u; i < count - 1; i++) {
				preservation[i] = temp.preservation[i];
			}
			preservation[count - 1] = &res;
		}
		return *this;
	}
	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res)
	{
		int counter = 0;
		for (size_t i = 0u; i < count; i++) {
			if (preservation[i] == &res) {
				counter = 1;
				preservation[i] = nullptr;
			}
			else {
				counter = 0;
			}
		}
		if (counter == 1) {
			ConfirmationSender temp = *this;
			delete[] preservation;
			count--;
			preservation = new const Reservation * [count];
			for (size_t i = 0; i < count; i++) {
				if (preservation != nullptr) {
					preservation[i] = temp.preservation[i];
				}
			}
		}
		return *this;

	}
	void ConfirmationSender::display(std::ostream& os) const
	{
		if (count == 0u) {
			os << "--------------------------" << endl;
			os << "Confirmations to Send" << endl;
			os << "--------------------------" << endl;
			os << "The object is empty!" << endl;
			os << "--------------------------" << endl;
		}
		else {
			os << "--------------------------" << endl;
			os << "Confirmations to Send" << endl;
			os << "--------------------------" << endl;
			for (size_t i = 0u; i < count; i++) {
				(*preservation[i]).display(os);
			}
			os << "--------------------------" << endl;
		}
	}

	void operator<<(std::ostream& os, const ConfirmationSender& obj)
	{
		obj.display(os);
	}
}