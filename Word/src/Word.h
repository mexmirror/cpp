/*
 * Word.h
 *
 *  Created on: 28.10.2015
 *      Author: hsr
 */

#ifndef WORD_H_
#define WORD_H_

#include <iostream>
#include <cctype>
#include <iterator>
#include <algorithm>



class Word {

	std::string currentContent{};
	explicit Word(std::istream& in);

public:

	std::istream & read(std::istream& in);
	std::ostream & print(std::ostream& out) const;

	inline bool operator<(Word const& rhs) const {
		std::string s1{}, s2{};
		std::transform(begin(this->currentContent), end(this->currentContent), begin(s1), ::tolower);
		std::transform(begin(rhs.currentContent), end(rhs.currentContent), begin(s1), ::tolower);
		return s1 < s2;
	}

	inline bool operator>(Word const& rhs) const{
		return rhs < *this;
	}

	inline bool operator>=(Word const& rhs) const{
		return !(*this < rhs);
	}

	inline bool operator<=(Word const& rhs) const{
		return !(rhs < *this);
	}

	inline bool operator==(Word const& rhs) const{
		return !(*this < rhs) && !(rhs < *this);
	}

	inline bool operator!=(Word const& rhs) const{
		return !(*this == rhs);
	}

};

inline std::ostream& operator<<(std::ostream& out, Word const& rhs) {
	rhs.print(out);
	return out;
}

inline std::istream& operator>>(std::istream& in, Word & rhs) {
	rhs.read(in);
	return in;
}




#endif /* WORD_H_ */
