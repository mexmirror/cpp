#include "Word.h"
#include "kwic.h"

#include <sstream>
#include <string>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <set>


std::vector<Word> getWords(std::string const currentLine) {
	std::istringstream line{currentLine};
	std::istream_iterator<Word> const eof {};
	std::istream_iterator<Word> it {line};
	std::vector<Word> const words{it, eof};
	return words;
}

std::vector<std::vector<Word>> getRotations(std::vector<std::vector<Word>> const lines) {
	std::vector<std::vector<Word>> rotations{};
	for_each(cbegin(lines), cend(lines), [&rotations](std::vector<Word> const line) {
		for(unsigned int i = 0; i < line.size(); i++) {
			std::vector<Word> rotationLine{};
			std::rotate_copy(cbegin(line), cbegin(line) + i, cend(line), back_inserter(rotationLine));
			rotations.push_back(rotationLine);
		}
	});
	return rotations;
}

std::vector<std::vector<Word>> getLines(std::istream &in) {
	std::string currentLine{};
	std::vector<std::vector<Word>> lines;
	while(std::getline(in, currentLine)) {
		lines.push_back(getWords(currentLine));
	}
	return lines;
}

void printLines(std::set<std::vector<Word>> const lines, std::ostream &out) {
	std::ostream_iterator<Word> os(out, " ");
	for_each(cbegin(lines), cend(lines), [&out, &os](std::vector<Word> line) {
		copy(cbegin(line), cend(line), os);
		out << "\n";
	});
}
void kwic(std::istream &in, std::ostream &out) {
	auto const lines = getLines(in);
	auto const rotations = getRotations(lines);
	std::set<std::vector<Word>> const sortedLines{cbegin(rotations), cend(rotations)};
	printLines(sortedLines, out);
}
