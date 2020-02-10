// Name: Navpreet Kaur
// Seneca Student ID: 148332182
// Seneca email: nk79@myseneca.ca
// Date of completion:  2 feb,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#pragma once
#ifndef SDDS_PAIRSUMMABLE_H__
#define SDDS_PAIRSUMMABLE_H__

#include <iostream>
#include <string>
#include "Pair.h"
namespace sdds {
	template<typename K, typename V>
	class PairSummable : public Pair<K, V>
	{
		static V initialValue;
		static size_t fieldWidth;
	public:
		static const V& getInitialValue() {
			return initialValue;
		}

		PairSummable() :Pair<K, V >() {

		}
		PairSummable(const K& key, const V& value) :Pair<K, V>(key, value) {
			if (fieldWidth < key.length()) {
				fieldWidth = key.length();
			}
		}

		V sum(const K& key, const V& value)const {
			return (this->key() == key) ? this->value() + value : value;
		}

		void display(std::ostream& os)const {
			os << std::left << std::setw(fieldWidth);
			Pair<K, V>::display(os);
			os << std::right;
		}

	};

	template<typename K, typename V>
	size_t PairSummable<K, V>::fieldWidth = 0u;

	template <typename K, typename V>
	V PairSummable<K, V>::initialValue = 0u;

	template <>
	std::string PairSummable<std::string, std::string>::initialValue = "";

	template <>
	std::string PairSummable<std::string, std::string>::sum(const std::string& key, const std::string& value)const {
		std::string v = "";
		if (PairSummable<std::string, std::string>::key() == key) {
			if (value == "") v = this->value();
			else v = value + ", " + this->value();
		}
		else
			v = value;
		return v;
	}

}
#endif

