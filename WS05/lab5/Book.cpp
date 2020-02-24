// Name: Navpreet Kaur
// Seneca Student ID: 148332182
// Seneca email: nk79@myseneca.ca
// Date of completion: 12 feb,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<iomanip>
#include<cstring>

#include "Book.h"
using namespace std;

namespace sdds {
	Book::Book()
	{
		m_author[0] = '\0';
		m_title[0] = '\0';
		m_country[0] = '\0';
		m_year = 0u;
		m_price = 0.0;
		m_description = '\0';
	}
	const std::string& Book::title() const
	{
		return m_title;
	}
	const std::string& Book::country() const
	{
		return m_country;
	}
	const size_t& Book::year() const
	{
		return m_year;
	}
	double& Book::price()
	{
		return m_price;
	}
	void Book::trim(std::string& str) const
	{
		size_t i = 0u;
		for (i = 0u; i < str.length() && str[i] == ' '; ++i);
		str = str.substr(i);

		for (i = str.length(); i > 0 && str[i - 1] == ' '; --i);
		str = str.substr(0, i);
	}
	Book::Book(const std::string& strBook)
	{
		string temp;
		temp = strBook;
		int index = temp.find(",");
		this->trim(m_author = temp.substr(0, index));
		int temp1 = index;
		int index1 = temp.find(",", temp1 + 1);
		int temp2 = index1 - index;
		this->trim(m_title = temp.substr(index + 1, temp2 - 1));
		int index2 = temp.find(",", index1 + 1);
		int temp3 = index2 - index1;
		this->trim(m_country = temp.substr(index1 + 1, temp3 - 1));
		int index3 = temp.find(",", index2 + 1);
		int temp4 = index3 - index2;
		m_price = std::stod(temp.substr(index2 + 1, temp4));
		int index4 = temp.find(",", index3 + 1);
		int temp5 = index4 - index3;
		m_year = std::stoi(temp.substr(index3 + 1, temp5));
		int index5 = temp.find("\n", index4);
		int temp6 = index5 - index4;
		this->trim(m_description = temp.substr(index4 + 1, temp6));
	}
	void operator<<(std::ostream& os, Book& obj)
	{
		os << right;
		os << setw(20);
		os << obj.m_author << " |";
		os << right;
		os << setw(23);
		os << obj.m_title << " |";
		os << right;
		os << setw(6);
		os << obj.m_country << " |";
		os << setw(5);
		os << obj.m_year << " |";
		os << right;
		os << setw(7);
		os << std::fixed;
		os << setprecision(2) << obj.price() << " | ";
		os << left;
		os << obj.m_description << endl;
	}

}