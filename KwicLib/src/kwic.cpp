#include "kwic.h"
#include "Word.h"

#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <iterator>

bool sortRotationsFunction (std::vector<Word> i, std::vector<Word> j) {
	return i.front() < j.front();
}
std::vector<Word> getWords(std::string currentLine) {
	std::istringstream line{currentLine};
	std::vector<Word> words{};
	while(line) {
		Word word{};
		line >> word;
		words.push_back(word);
	}
	return words;
}

std::vector<std::vector<Word>> getRotations(std::vector<std::vector<Word>> lines) {
	std::vector<std::vector<Word>> rotations{};
	for_each(cbegin(lines), cend(lines), [&rotations](std::vector<Word> line) {
		std::vector<Word> rotationLine{};
		for(unsigned int i = 0; i < line.size(); i++) {
			std::rotate_copy(cbegin(line), ++cbegin(line), cend(line), back_inserter(rotationLine));
		}
		rotations.push_back(rotationLine);
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

std::vector<std::vector<Word>> sortRotations(std::vector<std::vector<Word>> rotations) {
	std::sort(begin(rotations), end(rotations), sortRotationsFunction);
	return rotations;
}

void printLines(std::vector<std::vector<Word>> lines, std::ostream &out) {
	for_each(cbegin(lines), cbegin(lines), [&out](std::vector<Word> line) {
		for_each(cbegin(line), cbegin(line), [&out] (Word word) {
			out << word;
		});
		out << "\n";
	});
}
void kwic(std::istream &in, std::ostream &out) {
	std::vector<std::vector<Word>> lines{};
	lines = getLines(in);
	std::vector<std::vector<Word>> rotations{};
	rotations = getRotations(lines);
	std::vector<std::vector<Word>> sortedLines{};
	sortedLines = sortRotations(rotations);
	printLines(sortedLines, out);
}
