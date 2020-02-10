// Name: Navpreet Kaur
// Seneca Student ID: 148332182
// Seneca email: nk79@myseneca.ca
// Date of completion: 22 Jan,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<iomanip>
#include<cstring>
#include<fstream>
#include "RecordSet.h"
#include "TimedEvents.h"
#include <string>
using namespace std;

namespace sdds {
	RecordSet::RecordSet()
	{
		s = nullptr;
		count = 0;
	}

	RecordSet::RecordSet(const char* fileName)
	{
		ifstream file(fileName);
		int space = 0;
		string buffer;
		//file.open(fileName);
		if (file.is_open()) {
			while (getline(file, buffer, ' ')) {
				space++;
			}
			count = space;
			file.clear();
			file.seekg(0, ios::beg);

			s = new string[count];
			int i = 0;
			while (!file.eof()) {
				getline(file, s[i], ' ');
				//file >> s[i];
				i++;
			}
		}
	}

	RecordSet::RecordSet(const RecordSet& src) {
		count = src.count;
		s = new string[count];
		for (size_t i = 0; i < count; i++) {
			s[i] = src.s[i];
		}
	}

	RecordSet& RecordSet::operator=(const RecordSet& src) {
		if (this != &src)
		{
			this->count = src.count;
			delete[]this->s;
			this->s = new string[count];
			for (long unsigned int index = 0; index < count; index++)
			{
				this->s[index] = src.s[index];
			}
		}
		else {
			s = nullptr;
		}
		return *this;
	}

	RecordSet::RecordSet(RecordSet&& src)
	{
		*this = move(src);
	}

	RecordSet& RecordSet::operator=(RecordSet&& src)
	{
		if (this != &src) {
			delete[] s;
			s = src.s;
			count = src.count;
			src.s = nullptr;
			src.count = 0u;
		}
		return *this;

	}

	RecordSet::~RecordSet() {
		delete[] this->s;
	}

	size_t RecordSet::size()
	{
		return count;
	}

	string RecordSet::getRecord(size_t index)
	{
		string str;
		if (index < count) {
			if (s == nullptr) {
				str = "";
			}
			else {
				str = s[index];
			}
		}
		else if (index >= count) {
			str = "";
		}
		return str;
	}
}
