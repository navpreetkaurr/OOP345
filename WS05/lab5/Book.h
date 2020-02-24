// Name: Navpreet Kaur
// Seneca Student ID: 148332182
// Seneca email: nk79
// Date of completion: 12 Feb,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#pragma once
#ifndef SDDS_BOOK_H__
#define SDDS_BOOK_H__

#include<string>
using namespace std;
namespace sdds {
	class Book {
		string m_author;
		string m_title;
		string m_country;
		size_t m_year;
		double m_price;
		string m_description;
	public:
		Book();
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		Book(const std::string& strBook);
		friend void operator<<(std::ostream& os, Book& obj);
		void trim(std::string& str) const;
	};
}
#endif