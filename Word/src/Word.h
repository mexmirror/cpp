#ifndef WORD_H_
#define WORD_H_

#include <iostream>
#include <cctype>
#include<iterator>
#include <algorithm>

class Word {

	std::string currentContent{};

public:
	Word();
	std::istream & read(std::istream& in);
	std::ostream & print(std::ostream& out) const;

	inline bool operator<(Word const& rhs) const{
		std::string s1 {}, s2 {};
		std::transform(begin(this->currentContent), end(this->currentContent), begin(s1), ::tolower);
		std::transform(begin(rhs.currentContent), end(rhs.currentContent),begin(s2), ::tolower);
		return s1 < s2;
	}

	inline std::ostream& operator<<(std::ostream& out) {
		this->print(out);
		return out;
	}

	inline std::istream& operator>>(std::istream& in) {
		this->read(in);
		return in;
	}
};


inline bool operator >(Word const& lhs, Word const& rhs) {
	return rhs < lhs;
}

inline bool operator >=(Word const& lhs, Word const& rhs) {
	return !(lhs < rhs);
}

inline bool operator <=(Word const& lhs, Word const& rhs) {
	return !(rhs < lhs);
}

inline bool operator ==(Word const& lhs, Word const& rhs) {
	return !(lhs < rhs) && !(rhs < lhs);
}

inline bool operator !=(Word const& lhs, Word const& rhs) {
	return !(lhs == rhs);
}

#endif
