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
Word::Word(const std::string &string){
	std::string currentContent {};
	std::istringstream is {string};
	is >> *this;
	if(this->currentContent.empty()) {
		throw std::invalid_argument("Invalid string");
	}
}
std::ostream & Word::print(std::ostream& out) const {
	out << currentContent;
	return out;
}

bool charCaseLess(std::string const &lhs, std::string const &rhs) {
	return std::lexicographical_compare(
			begin(lhs), end(lhs), begin(rhs), end(rhs),
			[](char l, char r) {
		return std::tolower(l) < std::tolower(r);
	});
}

bool Word::operator<(Word const& rhs) const{
	return charCaseLess(currentContent, rhs.currentContent);
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

