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

public:
	Word();
	std::istream & read(std::istream& in);
	std::ostream & print(std::ostream& out) const;
	bool operator<(Word const& rhs) const;
};

inline bool operator>(Word const & lhs, Word const & rhs) {
     return rhs < lhs;
}
inline bool operator>=(Word const & lhs, Word const & rhs) {
     return!(lhs < rhs);
}
inline bool operator<=(Word const & lhs, Word const & rhs) {
     return!(rhs < lhs);
}
inline bool operator==(Word const & lhs, Word const & rhs) {
     return!(lhs < rhs) && !(rhs < lhs);
}
inline bool operator!=(Word const & lhs, Word const & rhs) {
     return!(lhs == rhs);
}
inline std::ostream& operator<<(std::ostream& out, Word const& word) {
	word.print(out);
	return out;
}

inline std::istream& operator>>(std::istream& in, Word & word) {
	word.read(in);
	return in;
}




#endif /* WORD_H_ */
