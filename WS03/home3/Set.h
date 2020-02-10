// Name: Navpreet Kaur
// Seneca Student ID: 148332182
// Seneca email: nk79@myseneca.ca
// Date of completion: 29 Jan,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#pragma once
#ifndef SDDS_SET_H__
#define SDDS_SET_H__
namespace sdds {
	template <class T, size_t N>
	class Set {
		T array[N];
		size_t elements = 0;

	public:
		size_t size() const{
			return elements;
		}
		const T& operator[](size_t idx)const {
			return array[idx];
		}
		void operator+=(const T& item) {
			if (elements < N) {
				array[elements] = item;
				elements++;
			}
		}
	};
}
#endif
