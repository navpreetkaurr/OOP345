// Name: Navpreet Kaur
// Seneca Student ID: 148332182
// Seneca email: nk79@myseneca.ca
// Date of completion: 5 feb,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<iomanip>
#include<cstring>

#include "Reservation.h"
#include <string>
using namespace std;

namespace sdds {
	Reservation::Reservation() {
		reservation_id = '\0';
		res_name = '\0';
		email = '\0';
		noOfPeople = 0;
		day = 0;
		hour = 0;
	}
	Reservation::Reservation(const std::string& res) {
		string temp;
		temp = res;
		int len = temp.length();
		for (int i = 0; i < len; i++) {
			if (temp[i] == ' ')
			{
				for (int j = i; j < len; j++) {
					temp[j] = temp[j + 1];
				}
				len--;
				i--;
			}
		}
		int index;
		for (int k = 0; k < len; k++) {
			if (temp[k] == ':') {
				index = k;
			}
		}
		reservation_id = temp.substr(0, index);
		int index1 = temp.find(",");
		int len1 = index1 - index;
	    res_name = temp.substr(index + 1, len1 - 1);
		int index2 = temp.find(",", index1 + 1);
		int len2 = index2 - index1;
		email = "<" + temp.substr(index1 + 1, len2 - 1) + ">";
		int index3 = temp.find(",", index2 + 1);
		int len3 = index3 - index2;
		noOfPeople = std::stoi(temp.substr(index2 + 1, len3));
		int index4 = temp.find(",", index3 + 1);
		int len4 = index4 - index3;
		day = std::stoi(temp.substr(index3 + 1, len4));
		int index5 = temp.find("\n", index4);
		int len5 = index5 - index4;
		hour = std::stoi(temp.substr(index4 + 1, len5));
	}
	void operator<<(std::ostream& os, const Reservation& obj) {
		if ((obj.hour >= 6) && (obj.hour <= 9)) {
			os << "Reservation " << obj.reservation_id << ": " << right << setw(10) << obj.res_name << "  " << left << setw(20) << obj.email << "    Breakfast on day " << obj.day << " @ " << obj.hour << ":00 for " << obj.noOfPeople << " people." << endl;
		}
		else if ((obj.hour >= 11) && (obj.hour <= 15)) {
			os << "Reservation " << obj.reservation_id << ": " << right << setw(10) << obj.res_name << "  " << left << setw(20) << obj.email << "    Lunch on day " << obj.day << " @ " << obj.hour << ":00 for " << obj.noOfPeople << " people." << endl;
		}
		else if ((obj.hour >= 17) && (obj.hour <= 21)) {
			os << "Reservation " << obj.reservation_id << ": " << right << setw(10) << obj.res_name << "  " << left << setw(20) << obj.email << "    Dinner on day " << obj.day << " @ " << obj.hour << ":00 for " << obj.noOfPeople
				<< " people." << endl;
		}
		else {
			os << "Reservation " << obj.reservation_id << ": " << right << setw(10) << obj.res_name << "  " << left << setw(20) << obj.email << "    Drinks on day " << obj.day << " @ " << obj.hour << ":00 for " << obj.noOfPeople << " people." << endl;
		}
	}
}


