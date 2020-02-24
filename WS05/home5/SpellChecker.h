// Name: Navpreet Kaur
// Seneca Student ID: 148332182
// Seneca email: nk79@myseneca.ca
// Date of completion: 23 feb,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#pragma once
#ifndef _SDDS_SPELLCHECKER_H
#define _SDDS_SPELLCHECKER_H
#include<string>
using namespace std;
namespace sdds {
	class SpellChecker {
		string m_badWords[5];
		string m_goodWords[5];
	public:
		SpellChecker(const char* filename);
		void operator()(std::string& text) const;
	};
}
#endif