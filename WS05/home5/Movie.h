// Name: Navpreet Kaur
// Seneca Student ID: 148332182
// Seneca email: nk79@myseneca.ca
// Date of completion: 23 feb,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#pragma once
#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H
#include <iostream>
namespace sdds {
	class Movie {
		std::string m_title{};
		int m_year{ 0 };
		std::string m_desc{};
	public:
		Movie() {};
		const std::string& title() const { return m_title; };
		Movie(const std::string& strMovie);
		template <typename T>
		void fixSpelling(T spellChecker) {
			spellChecker(m_title);
			spellChecker(m_desc);
		};
		friend std::ostream& operator<<(std::ostream& os, const Movie& mv);
	};
}
#endif