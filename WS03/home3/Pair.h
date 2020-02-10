// Name: Navpreet Kaur
// Seneca Student ID: 148332182
// Seneca email: nk79@myseneca.ca
// Date of completion: 2 feb,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include<iostream>
#pragma once
#ifndef SDDS_PAIR_H__
#define SDDS_PAIR_H__
using namespace std;
namespace sdds {

	template<typename K, typename V>
	class Pair {
		K mKey;
		V mValue;
	public:
		Pair() {}

		Pair(const K& key, const V& value) {
			mKey = key;
			mValue = value;
		}
		const K& key()const {
			return mKey;
		}
		const V& value() const {
			return mValue;
		}
		void display(std::ostream& os)const {
			os << mKey << " : " << mValue << std::endl;
		}
	};

	template<typename K, typename V>
	ostream& operator<<(ostream& os, const Pair<K, V>& pair) {
		pair.display(os);
		return os;
	}
}
#endif