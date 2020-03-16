#include "SongCollection.h"
#include <fstream>
#include<string>
#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
namespace sdds {
	SongCollection::SongCollection(std::string fileName)
	{
		std::ifstream sourceFile(fileName);
		if (sourceFile) {
			string line;
			while (sourceFile && !sourceFile.eof()) {
				Song s;
				string detail;
				getline(sourceFile, detail, '\n');
				string temp;
				int index;
				temp = detail.substr(0, 25);
				index = temp.find_last_not_of(" ");
				s.m_title = temp.substr(temp.find_first_not_of(" "), index + 1);
				if (s.m_title.length() > 20) {
					s.m_title = s.m_title.substr(temp.find_first_not_of(" ") - 1, 20);
				}
				detail.erase(0, 25);
				temp = detail.substr(0, 25);
				index = temp.find_last_not_of(" ");
				s.m_artist = temp.substr(temp.find_first_not_of(" "), index + 1);
				detail.erase(0, 25);
				temp = detail.substr(0, 25);
				index = temp.find_last_not_of(" ");
				s.m_album = temp.substr(temp.find_first_not_of(" "), index + 1);
				detail.erase(0, 25);
				temp = detail.substr(0, 5);
				if (temp == "     ") {
					s.m_year = 0;
				}
				else {
					index = temp.find_last_not_of(" ");
					s.m_year = stoi(temp.substr(0, index + 1));
				}
				detail.erase(0, 5);
				temp = detail.substr(0, 5);
				index = temp.find_last_not_of(" ");
				s.m_length = stoi(temp.substr(0, index + 1));
				detail.erase(0, 5);
				temp = detail.substr(0, 5);
				index = temp.find_last_not_of(" ");
				s.m_price = stod(temp.substr(0, index + 1));
				detail.erase(0, 5);
				m_songs.push_back(s);
			}
		}
		else {
			throw "Unable to open file";
		}
	}

	void SongCollection::display(std::ostream& out) const
	{
		std::for_each(m_songs.begin(), m_songs.end(), [&](const Song song) {
			out << song;
			});
	}
	std::ostream& operator<<(std::ostream& out, const Song& theSong) {
		out << "| " << std::setw(20) << std::left << theSong.m_title << " | " << std::setw(15) << std::left << theSong.m_artist << " | "
			<< std::setw(20) << std::left << theSong.m_album << " | ";
		if (theSong.m_year != 0) {
			out << std::setw(6) << std::right << theSong.m_year;
		}
		else {
			out << std::setw(6) << "";
		}
		int min = theSong.m_length / 60;
		int sec = theSong.m_length % 60;

		out << " | " << min << ":";
		out << std::setw(2) << std::setfill('0') << sec << " | " << std::setfill(' ') << theSong.m_price << " |" << std::endl;
		out.precision(2);
		out.setf(std::ios::fixed);
		return out;
	}
}