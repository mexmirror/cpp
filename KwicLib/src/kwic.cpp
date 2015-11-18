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
		for(unsigned int i = 1; i < line.size(); i++) {
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
		std::ostream_iterator<int> os(out, " ");
		//copy(cbegin(line), cend(line), os);
		for_each(cbegin(line), cend(line), [&out] (Word word) {
			out << word << " ";
		});
		out << "\n";
	});
}
void kwic(std::istream &in, std::ostream &out) {
	std::vector<std::vector<Word>> lines{};
	lines = getLines(in);
	std::vector<std::vector<Word>> rotations{};
	rotations = getRotations(lines);
	out << "Length of rotations: " << rotations.size() << "\n";
	out << "=====================\n" << "lines before sorting:\n";
	for_each(cbegin(rotations), cend(rotations), [&out](std::vector<Word> line) {
		std::ostream_iterator<int> os(out, " ");
		//copy(cbegin(line), cend(line), os);
		for_each(cbegin(line), cend(line), [&out] (Word word) {
			out << word << " ";
		});
		out << "\n";
	});
	out << "======================\n";

	std::set<std::vector<Word>, bool(*)(std::vector<Word>, std::vector<Word>)> sortedLines{cbegin(rotations), cend(rotations), sortRotationsFunction};
	printLines(sortedLines, out);
}
