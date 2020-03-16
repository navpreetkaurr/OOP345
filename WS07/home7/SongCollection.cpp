// Name:Navpreet Kaur
// Seneca Student ID: 148332182
// Seneca email: nk79
// Date of completion: 15 March, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include <fstream>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<iomanip>
#include "SongCollection.h"

using namespace std;
namespace sdds {
	int space = 0;
	int total_time = 0;
	SongCollection::SongCollection(std::string fileName)
	{
		std::ifstream sourceFile(fileName);
		if (sourceFile) {
			while (!sourceFile.eof()) {
				string line;
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
		total_time = 0;
		std::for_each(m_songs.begin(), m_songs.end(), [&](const Song song) {
			out << song << endl;
			total_time += song.m_length;
			});
		display_total(out);
	}
	void SongCollection::display_total(std::ostream& out) const
	{
		int hour = total_time / 3600;
		int min = (total_time % 3600) / 60;
		int sec = (total_time % 3600) % 60;
		out << std::setw(89) << std::setfill('-') << '\n' << std::setfill(' ');
		out << "| " << std::right << std::setw(77) << "Total Listening Time: " << hour << ":";
		out << std::setw(2) << std::setfill('0') << min << ":" << std::setw(2) << std::setfill('0') << sec << std::right << " |\n";
	}
	bool sortByTitle(Song& s1, Song& s2)
	{
		return (s1.m_title < s2.m_title);
	}
	bool sortByAlbum(Song& s1, Song& s2)
	{
		return (s1.m_album < s2.m_album);
	}
	bool sortByLength(Song& s1, Song& s2)
	{
		return (s1.m_length < s2.m_length);
	}
	void SongCollection::sort(const char* row)
	{
		if (strcmp(row, "title") == 0) {
			std::sort(m_songs.begin(), m_songs.end(), sortByTitle);
		}
		else if (strcmp(row, "length") == 0) {
			std::sort(m_songs.begin(), m_songs.end(), sortByLength);
		}
		else if (strcmp(row, "album") == 0) {
			std::sort(m_songs.begin(), m_songs.end(), sortByAlbum);
		}
	}
	void SongCollection::cleanAlbum()
	{
		auto FindNone = [](Song& song) {

			if (song.m_album == std::string("[None]") || song.m_album == std::string("[None]    "))
				song.m_album.clear();

		};

		std::for_each(m_songs.begin(), m_songs.end(), FindNone);
	}
	bool SongCollection::inCollection(const char* artist) const
	{
		bool result = false;
		std::for_each(m_songs.begin(), m_songs.end(), [&](const Song song) {
			if (song.m_artist == artist) {
				result = true;
			}
			});
		return result;
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
		out << std::setw(2) << std::setfill('0') << sec << " | " << std::setfill(' ') << theSong.m_price << " |";
		out.precision(2);
		out.setf(std::ios::fixed);
		return out;
	}
	std::list<Song> SongCollection::getSongsForArtist(std::string art) const {
		std::list<Song>song_list;

		std::for_each(m_songs.begin(), m_songs.end(), [&](const Song so) {
			int index = so.m_artist.find_last_not_of(" ");
			string temp = so.m_artist.substr(0, index + 1);
			if (temp == art) {
				song_list.push_back(so);
			}
			space = 1;
			});
		return song_list;
	}
}
