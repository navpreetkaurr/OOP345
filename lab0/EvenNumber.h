#ifndef EVENNUMBER_H__
#define EVENNUMBER_H__
using namespace std;
namespace sdds {
	class EvenNumber
	{
		int m_value;
	public:
		EvenNumber();
		EvenNumber(int);
		int getValue();
		EvenNumber getNext();
		EvenNumber getPrevious();
	};
}

#endif