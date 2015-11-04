/*
 * Word.cpp
 *
 *  Created on: 28.10.2015
 *      Author: hsr
 */

#include "Word.h"

Word::Word(std::istream& in) {
	read(in);
	if(in.fail()) throw std::out_of_range{"invalid word"};
};

std::ostream & Word::print(std::ostream& out) const {
	out << currentContent;
	return out;
}

std::istream & Word::read(std::istream& in) {
	currentContent = "";
	std::istream_iterator<char> it{};
	char c;
	if(in.eof()) {
		in.setstate(std::ios::failbit | in.rdstate());
	}else if(in.good()) {
		in >> c;
		while(!isalpha(c)) {
			in.ignore(1);
		}
		while(isalpha(c)) {
			currentContent += c;
			in >> c;
		}
		while(!isalpha(c)) {
			in.ignore(1);
		}
	}
	in.clear();

	return in;
}


