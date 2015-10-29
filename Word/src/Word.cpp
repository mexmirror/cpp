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
	out << word;
	return out;
}

std::istream & Word::read(std::istream& in) {
	if(in.eof()) {
		in.setstate(std::ios::failbit | in.rdstate());
	} if(in.good()) {
		// TODO
	}

	return in;
}


