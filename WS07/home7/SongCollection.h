// Name:Navpreet Kaur
// Seneca Student ID: 148332182
// Seneca email: nk79
// Date of completion: 15 March, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#ifndef _SDDS_SONGCOLLECTION_H
#define _SDDS_SONGCOLLECTION_H
#include<iostream>
#include<vector>
#include<list>
namespace sdds {
	struct Song {
		std::string m_artist;
		std::string m_title;
		std::string m_album;
		int m_year;
		double m_price;
		int m_length;
	};
	class SongCollection {
		std::vector<Song> m_songs;
	public:
		SongCollection(std::string fileName);
		void display(std::ostream& out) const;
		void display_total(std::ostream& out) const;
		void sort(const char*);
		void cleanAlbum();
		bool inCollection(const char*) const;
		std::list<Song> getSongsForArtist(std::string) const;
	};
	bool sortByTitle(Song& s1, Song& s2);
	bool sortByAlbum(Song& s1, Song& s2);
	bool sortByLength(Song& s1, Song& s2);
	std::ostream& operator<<(std::ostream& out, const Song& theSong);
}
#endif

