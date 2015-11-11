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
		std::string temp {};
		char c {};
		in.get(c);
		while(in.peek() != EOF){
			int size = in.gcount();
			if(std::isalpha(c)){
				temp += c;
				in.get(c);
			} else if(temp.size() == 0){
				in.get();
			} else {
				currentContent = temp;

				return in;
			}
		}
		currentContent = temp;
	}
	return in;
}
