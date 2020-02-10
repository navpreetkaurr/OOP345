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
		description[0] = '\0';
		time = 0;
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
			strncpy(description, array,strlen(array));
			description[strlen(array)] = '\0';
			time = g_sysClock;
		}
	}

}