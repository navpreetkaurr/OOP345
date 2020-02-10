#include "EvenNumber.h"

namespace sdds {
	EvenNumber::EvenNumber()
	{
		m_value = 0;
	}
	EvenNumber::EvenNumber(int value)
	{	
		if (value % 2 == 0)
		{
			m_value = value;
		}
		else
		{
			m_value = -1;
		}
	}
	
	int EvenNumber::getValue()
	{
		return m_value;
	}

	EvenNumber EvenNumber::getNext()
	{
		EvenNumber next;
		next.m_value=m_value+2;
		return next;
	}

	EvenNumber EvenNumber::getPrevious()
	{
		EvenNumber pre;
		pre.m_value =m_value-2;
		return pre;
	}
}