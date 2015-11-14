#include "Word.h"
#include <cctype>
#include <iterator>
#include <algorithm>

Word::Word() {
	std::string currentContent {};
}

std::ostream & Word::print(std::ostream& out) const {
	out << currentContent;
	return out;
}
bool Word::operator <(Word const& rhs) const{
	std::string s1 {}, s2 {};
	std::transform(begin(currentContent), end(currentContent), begin(s1), ::tolower);
	std::transform(begin(rhs.currentContent), end(rhs.currentContent),begin(s2), ::tolower);
	return s1 < s2;
}
std::istream & Word::read(std::istream& in) {
	if(in.eof()) {
		in.setstate(in.failbit);
	} if(in.good()) {
		std::string temp {};
		char c {};
		while(in.peek() != EOF){
			in.get(c);
			if(std::isalpha(c)){
				temp += c;
			} else if(!temp.empty()){
				break;
			}
		}

		if(!temp.empty()) {
			currentContent = temp;
		} else {
			in.setstate(in.failbit);
		}

		return in;
	}
	return in;
}
