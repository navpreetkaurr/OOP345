#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<cstring>
#include "event.h"
using namespace std;
unsigned long g_sysClock;
namespace sdds {
	Event::Event()
	{
		description = nullptr;
		time = 0;
	}
	Event::Event(const Event& desc)
	{
		description = nullptr;
		*this = desc;
	}
	Event& Event::operator=(const Event& src) {
		if (this != &src) {
			time = src.time;
			delete[] description;
			if (src.description != nullptr) {
				description = new char[strlen(src.description) + 1];
				strcpy(description, src.description);
			}
			else {
				description = nullptr;
			}
		}
		return *this;
	}
	Event::~Event()
	{
		delete[] description;
		description = nullptr;
	}
	ostream& Event::display() const
	{
		static int counter = 1;
		int hr = time / 3600;
		int min = (time % 3600) / 60;
		int sec = (time % 3600) % 60;
		if (description[0] == '\0' || description == nullptr) {
			cout << setw(3) << setfill(' ') << counter << ". [ No Event ]" << endl;
		}
		else {
			cout << setw(3) << setfill(' ') << counter << ". " << " " << setw(2) << setfill('0') << hr << ":" << setw(2) << setfill(' ') << min << ":" << setw(2) << setfill('0') << sec << " -> " << description << endl;
		}
		counter++;
		return cout;
	}
	void Event::setDescription(char* array) {
		if (array == nullptr || array[0] == '\0') {
			description[0] = '\0';
			time = 0;
		}
		else {
			description = new char[strlen(array) + 1];
			strcpy(description, array);
			time = g_sysClock;
		}
	}

}