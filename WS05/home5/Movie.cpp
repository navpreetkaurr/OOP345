// Name: Navpreet Kaur
// Seneca Student ID: 148332182
// Seneca email: nk79@myseneca.ca
// Date of completion: 23 feb,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include "Movie.h"
#include "Book.h"
namespace sdds {
	Movie::Movie(const std::string& strMovie) {
		std::string temp = strMovie;
		m_title = removeRSpaces(removeLSpaces(removeAll(m_title, temp)));
		m_year = removeAll(m_year, temp);
		m_desc = removeLSpaces(temp);
	}
	std::ostream& operator<<(std::ostream& os, const Movie& mv) {
		os << std::setw(40) << mv.m_title << " | " << std::setw(4) << mv.m_year << " | " << mv.m_desc << std::endl;
		return os;
	}
}