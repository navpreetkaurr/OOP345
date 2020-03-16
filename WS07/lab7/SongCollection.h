#ifndef SDDS_SONGCOLLECTION_H__
#define SDDS_SONGCOLLECTION_H__
#include<iostream>
#include<vector>
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
	};
	std::ostream& operator<<(std::ostream& out, const Song& theSong);
}
#endif
