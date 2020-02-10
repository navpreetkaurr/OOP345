// Name: Navpreet Kaur
// Seneca Student ID: 148332182
// Seneca email: nk79@myseneca.ca
// Date of completion: 22 Jan,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_RECORDSET_H__
#define SDDS_RECORDSET_H__

#include<iostream>
#include<iomanip>
#include<cstring>
#include <chrono>

namespace sdds {
	class RecordSet {
		std::string* s;
		size_t count;
	public:
		RecordSet();
		RecordSet(const char*);
		RecordSet(const RecordSet&);
		RecordSet& operator=(const RecordSet&);
		RecordSet(RecordSet&&);
		RecordSet& operator=(RecordSet&&);
		size_t size();
		std::string getRecord(size_t);
		~RecordSet();
	};
}
#endif


