/*
 * Word.cpp
 *
 *  Created on: 28.10.2015
 *      Author: hsr
 */

#include "Word.h"
#include <cctype>

Word::Word() {
	std::string currentContent {};
}

std::ostream & Word::print(std::ostream& out) const {
	out << currentContent;
	return out;
}


std::istream & Word::read(std::istream& in) {
	if(in.eof()) {
		in.setstate(std::ios::failbit | in.rdstate());
	} if(in.good()) {
		bool firstChar = true;
		std::string temp {};
		char c {};
		in.get(c);
		while(in.peek() != EOF){
			if(std::isalpha(c)){
				temp += c;
				in.get(c);
				firstChar = false;
			} else if(firstChar){
				in >> c;
			} else {
				currentContent = temp;
				return in;
			}
		}
		currentContent = temp;
	}
	return in;
}
