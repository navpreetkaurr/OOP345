// Name: Navpreet Kaur
// Seneca Student ID: 148332182
// Seneca email: nk79
// Date of completion: 8 march, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <sstream>
#include <string>
#include "Car.h"
#include "Racecar.h"
#include"Utilities.h"
using namespace std;

namespace sdds {
	Vehicle* createInstance(std::istream& is)
	{
		bool debug = false;

		auto Trim = [](std::string& str) { 
			while (str.at(0) == ' ')
				str = str.substr(1, str.length() - 1);
			while (str.at(str.length() - 1) == ' ')
				str = str.substr(0, str.length() - 1);
		};
		std::string line;

		stringstream sstream;
		Vehicle* temp = nullptr;
		getline(is, line);
		if (debug) cout << "----Utilities createInstance--------" << endl << "line : " << line << endl << "------------------------------------------------" << endl << endl;

		if (!line.empty()) {
			Trim(line); 
			sstream << line; 
			if (sstream.str().at(0) == 'c' || sstream.str().at(0) == 'C') {
				temp = new Car(sstream);
			}
			else if (sstream.str().at(0) == 'r' || sstream.str().at(0) == 'R') {
				temp = new Racecar(sstream);
			}
			else {
				throw std::string("Unrecognized record type: [") + sstream.str().at(0) + "]";
			}
		}
		return temp;
	}
}