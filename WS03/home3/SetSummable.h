// Name: Navpreet Kaur
// Seneca Student ID: 148332182
// Seneca email: nk79@myseneca.ca
// Date of completion:  2 feb,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#pragma once
#ifndef SDDS_SETSUMMABLE_H__
#define SDDS_SETSUMMABLE_H__
#include "Set.h"

namespace sdds {
	template<typename T, size_t N, typename K, typename V>
	class SetSummable : public Set<T, N> {

	public:

		SetSummable() : Set<T, N>(){}
		V accumulate(const K& Key)const {
			V InitialValue = this->operator[](0).getInitialValue();

			for (size_t i = 0; i < this->size(); i++)
			{
				InitialValue = (this->operator[](i)).sum(Key, InitialValue);
			}

			return InitialValue;
		}
	};
}
#endif
