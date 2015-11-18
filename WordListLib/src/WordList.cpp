#include "WordList.h"
#include <set>
#include <string>
#include <istream>
#include <ostream>
#include <algorithm>
#include <iterator>
#include <cctype>

void wlist(std::istream& in, std::ostream& out){
	std::istream_iterator<std::string> it {in};
	std::istream_iterator<std::string> eof {};
	auto const isLess = [](std::string s1, std::string s2){
		std::transform(begin(s1), end(s1), begin(s1), ::tolower);
		std::transform(begin(s2), end(s2),begin(s2), ::tolower);
		return s1 < s2;
	};
	std::set<std::string, bool(*)(std::string, std::string)> set{it, eof, isLess};
	std::copy(begin(set), end(set), std::ostream_iterator<std::string>(out, "\n"));
}
