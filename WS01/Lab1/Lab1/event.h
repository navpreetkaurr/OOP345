#ifndef EVENT_H__
#define EVENT_H__

#include<iostream>
#include<iomanip>
using namespace std;
extern unsigned long g_sysClock;

namespace sdds {
	class Event {
		char description[129];
		unsigned long time;
	public:
		Event();
		ostream& display()const;
		void setDescription(char* array);
	};
}
#endif