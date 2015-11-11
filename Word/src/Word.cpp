/*
 * Word.cpp
 *
 *  Created on: 28.10.2015
 *      Author: hsr
 */

#include "Word.h"

Word::Word() {
	std::string currentContent{};
};

std::ostream & Word::print(std::ostream& out) const {
	out << currentContent;
	return out;
}

std::istream & Word::read(std::istream& in) {
	currentContent = "";

	if(in.eof()) {
		in.setstate(std::ios::failbit | in.rdstate());
	}

	while(in.good() && !isalpha(in.peek())) {
		in.ignore(1);
	}

	while(in.good() && isalpha(in.peek())) {
		currentContent += in.get();
	}

	if(!in) {
		in.clear();
	}

	return in;
}


