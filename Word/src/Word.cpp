#include "Word.h"
#include <cctype>
#include <iterator>
#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>


Word::Word() {
	std::string currentContent {};
}
Word::Word(std::string &word){
	std::string currentContent {};
	std::istringstream is {word};
	is >> *this;
}
std::ostream & Word::print(std::ostream& out) const {
	out << currentContent;
	return out;
}
bool Word::operator<(Word const& rhs) const{
	std::string s1 {}, s2 {};
	std::transform(currentContent.cbegin(), currentContent.cend(), back_inserter(s1), [](char c){return std::tolower(c);});
	std::transform(begin(rhs.currentContent), end(rhs.currentContent), back_inserter(s2), ::tolower);
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
