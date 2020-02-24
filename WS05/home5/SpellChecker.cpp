// Name: Navpreet Kaur
// Seneca Student ID: 148332182
// Seneca email: nk79@myseneca.ca
// Date of completion: 23 feb,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iomanip>
#include <algorithm>
#include "SpellChecker.h"
#include "Book.h"
namespace sdds {
	SpellChecker::SpellChecker(const char* filename) {
		if (filename == nullptr || filename[0] == '\0')
			throw "Bad file name!";
		else {
			std::ifstream myfile(filename);
			if (!myfile) {
				throw "Bad file name!";
			}
			else {
				int i = 0;
				std::string temp;
				do {
					std::getline(myfile, temp);
					size_t index = temp.find(' ');
					m_badWords[i] = temp.substr(0, index);
					temp.erase(0, index + 1);
					m_goodWords[i] = removeLSpaces(temp);
					i++;
				} while (myfile && i < 5);
				myfile.close();
			}
		}
	}
	void SpellChecker::operator()(std::string & text) const {
		size_t index;
		for (int i = 0; i < 5; i++) {
			index = text.find(m_badWords[i]);
			while (index != std::string::npos) {
				text.replace(index, m_badWords[i].length(), m_goodWords[i]);
				index = text.find(m_badWords[i]);
			}
		}
	}
}
