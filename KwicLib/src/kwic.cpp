#include "Word.h"
#include "kwic.h"
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <iterator>
#include<set>


bool sortRotationsFunction (std::vector<Word> i, std::vector<Word> j) {
	return i.front() < j.front();
}
std::vector<Word> getWords(std::string currentLine) {
	std::istringstream line{currentLine};
	std::vector<Word> words{};
	Word word{};
	while(line >> word) {
		words.push_back(word);
	}
	return words;
}

std::vector<std::vector<Word>> getRotations(std::vector<std::vector<Word>> lines) {
	std::vector<std::vector<Word>> rotations{};
	for_each(cbegin(lines), cend(lines), [&rotations](std::vector<Word> line) {
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

void printLines(std::set<std::vector<Word>, bool(*)(std::vector<Word>, std::vector<Word>)> lines, std::ostream &out) {
	for_each(cbegin(lines), cend(lines), [&out](std::vector<Word> line) {
		std::ostream_iterator<Word> os(out, " ");
		copy(cbegin(line), cend(line), os);
		out << "\n";
	});
}
void kwic(std::istream &in, std::ostream &out) {
	std::vector<std::vector<Word>> lines{};
	lines = getLines(in);
	std::vector<std::vector<Word>> rotations{};
	rotations = getRotations(lines);
	std::set<std::vector<Word>, bool(*)(std::vector<Word>, std::vector<Word>)> sortedLines{cbegin(rotations), cend(rotations), sortRotationsFunction};
	printLines(sortedLines, out);
}
