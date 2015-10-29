/*
 * Word.h
 *
 *  Created on: 28.10.2015
 *      Author: hsr
 */

#ifndef WORD_H_
#define WORD_H_

#include <iostream>

class Word {

	static std::string word{};
	explicit Word(std::istream& in);

public:

	std::istream & read(std::istream& in);
	std::ostream & print(std::ostream& out) const;

	bool operator<(Word const& rhs) const;

	inline std::ostream& operator<<(std::ostream& out, Word const& w) {
		w.print(out);
		return out;
	}

	inline std::istream& operator>>(std::istream& in, Word& w) {
		w.read(in);
		return in;
	}
};


inline bool operator>(Word const& lhs, Word const& rhs) const {
	return rhs < lhs;
}

inline bool operator>=(Word const& lhs, Word const& rhs) const {
	return !(lhs < rhs);
}

inline bool operator<=(Word const& lhs, Word const& rhs) const {
	return !(rhs < lhs);
}

inline bool operator==(Word const& lhs, Word const& rhs) const {
	return !(lhs < rhs) && !(rhs < lhs);
}

inline bool operator!=(Word const& lhs, Word const& rhs) const {
	return !(lhs == rhs);
}




#endif /* WORD_H_ */
