#include "Word.h"
#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"

void testSmallerAs() {
	std::istringstream in1 {"abc"};
	std::istringstream in2 {"xyz"};
	Word word1{};
	Word word2{};
	in1 >> word1;
	in2 >> word2;
	ASSERT(word1 < word2);
}

void testSmallerAsNegative() {
	std::istringstream in1 {"abc"};
	std::istringstream in2 {"xyz"};
	Word word1{};
	Word word2{};
	in1 >> word1;
	in2 >> word2;
	ASSERT(!(word2 < word1));
}

void testSmallerAsIgnoresCase() {
	std::istringstream in1 {"abc"};
	std::istringstream in2 {"XYZ"};
	Word word1{};
	Word word2{};
	in1 >> word1;
	in2 >> word2;
	ASSERT(word1 < word2);
}

void testLargerAs() {
	std::istringstream in1 {"abc"};
	std::istringstream in2 {"xyz"};
	Word word1{};
	Word word2{};
	in1 >> word1;
	in2 >> word2;
	ASSERT(word2 > word1);
}

void testLargerAsNegative() {
	std::istringstream in1 {"abc"};
	std::istringstream in2 {"xyz"};
	Word word1{};
	Word word2{};
	in1 >> word1;
	in2 >> word2;
	ASSERT(!(word1 > word2));
}

void testLargerAsIgnoresCase() {
	std::istringstream in1 {"abc"};
	std::istringstream in2 {"XYZ"};
	Word word1{};
	Word word2{};
	in1 >> word1;
	in2 >> word2;
	ASSERT(word2 > word1);
}

void testLargerEqualsAs() {
	std::istringstream in1 {"abc"};
	std::istringstream in2 {"xyz"};
	Word word1{};
	Word word2{};
	in1 >> word1;
	in2 >> word2;
	ASSERT(word2 >= word1);
}

void testLargerEqualsAsNegative() {
	std::istringstream in1 {"abc"};
	std::istringstream in2 {"xyz"};
	Word word1{};
	Word word2{};
	in1 >> word1;
	in2 >> word2;
	ASSERT(!(word1 >= word2));
}

void testLargerEqualsAsIgnoresCase() {
	std::istringstream in1 {"abc"};
	std::istringstream in2 {"XYZ"};
	Word word1{};
	Word word2{};
	in1 >> word1;
	in2 >> word2;
	ASSERT(word2 >= word1);
}

void testLargerEqualsAsWhenEquals() {
	std::istringstream in1 {"abc"};
	std::istringstream in2 {"abc"};
	Word word1{};
	Word word2{};
	in1 >> word1;
	in2 >> word2;
	ASSERT(word2 >= word1);
}

void testLargerEqualsAsWhenEqualsIgnoresCase() {
	std::istringstream in1 {"XYZ"};
	std::istringstream in2 {"XYZ"};
	Word word1{};
	Word word2{};
	in1 >> word1;
	in2 >> word2;
	ASSERT(word2 >= word1);
}


void testSmallerEqualsAs() {
	std::istringstream in1 {"abc"};
	std::istringstream in2 {"xyz"};
	Word word1{};
	Word word2{};
	in1 >> word1;
	in2 >> word2;
	ASSERT(word1 <= word2);
}

void testSmallerEqualsAsNegative() {
	std::istringstream in1 {"abc"};
	std::istringstream in2 {"xyz"};
	Word word1{};
	Word word2{};
	in1 >> word1;
	in2 >> word2;
	ASSERT(!(word2 <= word1));
}

void testSmallerEqualsAsIgnoresCase() {
	std::istringstream in1 {"abc"};
	std::istringstream in2 {"XYZ"};
	Word word1{};
	Word word2{};
	in1 >> word1;
	in2 >> word2;
	ASSERT(word1 <= word2);
}

void testSmallerEqualsAsWhenEquals() {
	std::istringstream in1 {"abc"};
	std::istringstream in2 {"abc"};
	Word word1{};
	Word word2{};
	in1 >> word1;
	in2 >> word2;
	ASSERT(word2 <= word1);
}

void testSmallerEqualsAsWhenEqualsIgnoresCase() {
	std::istringstream in1 {"XYZ"};
	std::istringstream in2 {"XYZ"};
	Word word1{};
	Word word2{};
	in1 >> word1;
	in2 >> word2;
	ASSERT(word2 <= word1);
}

void testEquals() {
	std::istringstream in1 {"xyz"};
	std::istringstream in2 {"xyz"};
	Word word1{};
	Word word2{};
	in1 >> word1;
	in2 >> word2;
	ASSERT(word2 == word1);
}

void testEqualsNegative() {
	std::istringstream in1 {"abc"};
	std::istringstream in2 {"xyz"};
	Word word1{};
	Word word2{};
	in1 >> word1;
	in2 >> word2;
	ASSERT(!(word2 == word1));
}

void testEqualsIgnoreCase() {
	std::istringstream in1 {"xyz"};
	std::istringstream in2 {"XYZ"};
	Word word1{};
	Word word2{};
	in1 >> word1;
	in2 >> word2;
	ASSERT(word2 == word1);
}

void testUnequals() {
	std::istringstream in1 {"xyz"};
	std::istringstream in2 {"abc"};
	Word word1{};
	Word word2{};
	in1 >> word1;
	in2 >> word2;
	ASSERT(word2 != word1);
}

void testUnequalsNegative() {
	std::istringstream in1 {"abc"};
	std::istringstream in2 {"abc"};
	Word word1{};
	Word word2{};
	in1 >> word1;
	in2 >> word2;
	ASSERT(!(word2 != word1));
}

void testUnequalsIgnoreCase() {
	std::istringstream in1 {"xyz"};
	std::istringstream in2 {"XYZ"};
	Word word1{};
	Word word2{};
	in1 >> word1;
	in2 >> word2;
	ASSERT(!(word2 != word1));
}


void testDoesntReadGarbageFromString() {
	std::istringstream s{"'''--"};
	std::ostringstream os{};
	Word word;
	s >> word;
	os << word;
	ASSERT_EQUAL("", os.str());
}

void testReadsFromString() {
	std::istringstream s{"hello"};
	std::ostringstream os {};
	Word word;
	s >> word;
	os << word;
	ASSERT_EQUAL("hello", os.str());
}

void testDoesntConstructFromEmptyString() {
	std::istringstream in{"Maus"};
	std::ostringstream os {};
	Word word{};
	in >> word;
	in >> word;
	os << word;
	ASSERT_EQUAL("Maus", os.str());
}
void testSeperateWordsFromGarbage() {
	std::istringstream in {"Maus!!//Moritz283Mag][-Jeder[[``"};
	std::ostringstream os {};
	Word word{};
	while(in >> word) {
		os << word;
	}
	ASSERT_EQUAL("MausMoritzMagJeder", os.str());
}

void testExtracsWordFromGarbage() {
	std::istringstream in {"!!.test//"};
	std::ostringstream os {};
	Word word{};
	in >> word;
	os << word;
	ASSERT_EQUAL("test", os.str());
}

void testReadsSingleWord() {
	std::istringstream in {"test"};
	std::ostringstream os {};
	Word word{};
	in >> word;
	os << word;
	ASSERT_EQUAL("test", os.str());
}

void testIgnoresLinebrake() {
	std::istringstream in {"		ab	\n ik"};
	std::ostringstream os {};
	Word word{};
	while(in >> word) {
		os << word;
	}
	ASSERT_EQUAL("abik", os.str());
}

void testIgnoresTabs() {
	std::istringstream in {"		ab	\t ik"};
	std::ostringstream os {};
	Word word{};
	while(in >> word) {
		os << word;
	}
	ASSERT_EQUAL("abik", os.str());
}

void testIgnoresWhiteSpace() {
	std::istringstream in {"                ab             ik"};
	std::ostringstream os {};
	Word word{};
	while(in >> word) {
		os << word;
	}
	ASSERT_EQUAL("abik", os.str());
}

void testSetsFailBit() {
	std::istringstream in {"!!"};
	Word word {};
	in >> word;
	ASSERT(in.failbit);
}

void testEmptyInputStreamResult() {
	std::istringstream in {""};
	Word word{};
	in >> word;
	ASSERT(in.eofbit);
}
void testEmptyInputResult() {
	std::istringstream in {""};
	std::ostringstream os{};
	Word word{};
	in >> word;
	os << word;
	ASSERT_EQUAL("", os.str());
}

void testForFailBit() {
	std::istringstream in {"22"};
	Word word{};
	in >> word;
	ASSERT(in.eofbit);
}

void testDoesntReadGarbage() {
	std::istringstream in {"2390492423492309489023!!::::::...---;..."};
	std::ostringstream os {};
	Word word{};
	in >> word;
	os << word;
	ASSERT_EQUAL("", os.str());
}
void complicatedTest() {
	std::istringstream in {"compl33tely ~ weird !!??!! 4matted in_put"};
	std::ostringstream os {};
	Word word{};
	while(in >> word) {
		os << word << ", ";
	}
	ASSERT_EQUAL("compl, tely, weird, matted, in, put, ", os.str());
}

void testStringInConstructor(){
	std::string str {"Maus"};
	std::ostringstream os {};
	Word word{str};
	os << word;
	ASSERT_EQUAL(str, os.str());
}
void testWrongStringInConstructor(){
	std::string str {"Die Maus ist im Haus"};
	std::ostringstream os {};
	Word word(str);
	os << word;
	ASSERT_EQUAL("Die", os.str());
}

void testInvalidStringForConstructor() {
	std::string str{"!!//??    %%&&"};
	ASSERT_THROWS(Word word{str};, std::invalid_argument);
}

void runAllTests(int argc, char const *argv[]){
	cute::suite s;
	s.push_back(CUTE(complicatedTest));
	s.push_back(CUTE(testSeperateWordsFromGarbage));
	s.push_back(CUTE(testExtracsWordFromGarbage));
	s.push_back(CUTE(testReadsSingleWord));
	s.push_back(CUTE(testIgnoresLinebrake));
	s.push_back(CUTE(testIgnoresTabs));
	s.push_back(CUTE(testIgnoresWhiteSpace));
	s.push_back(CUTE(testSetsFailBit));
	s.push_back(CUTE(testEmptyInputStreamResult));
	s.push_back(CUTE(testEmptyInputResult));
	s.push_back(CUTE(testForFailBit));
	s.push_back(CUTE(testDoesntReadGarbage));
	s.push_back(CUTE(testDoesntConstructFromEmptyString));
	s.push_back(CUTE(testReadsFromString));
	s.push_back(CUTE(testDoesntReadGarbageFromString));
	s.push_back(CUTE(testUnequalsIgnoreCase));
	s.push_back(CUTE(testUnequalsNegative));
	s.push_back(CUTE(testUnequals));
	s.push_back(CUTE(testEqualsIgnoreCase));
	s.push_back(CUTE(testEqualsNegative));
	s.push_back(CUTE(testEquals));
	s.push_back(CUTE(testSmallerEqualsAsWhenEqualsIgnoresCase));
	s.push_back(CUTE(testSmallerEqualsAsWhenEquals));
	s.push_back(CUTE(testSmallerEqualsAsIgnoresCase));
	s.push_back(CUTE(testSmallerEqualsAsNegative));
	s.push_back(CUTE(testSmallerEqualsAs));
	s.push_back(CUTE(testLargerEqualsAsWhenEqualsIgnoresCase));
	s.push_back(CUTE(testLargerEqualsAsWhenEquals));
	s.push_back(CUTE(testLargerEqualsAsIgnoresCase));
	s.push_back(CUTE(testLargerEqualsAsNegative));
	s.push_back(CUTE(testLargerEqualsAs));
	s.push_back(CUTE(testLargerAsIgnoresCase));
	s.push_back(CUTE(testLargerAsNegative));
	s.push_back(CUTE(testLargerAs));
	s.push_back(CUTE(testSmallerAsIgnoresCase));
	s.push_back(CUTE(testSmallerAsNegative));
	s.push_back(CUTE(testSmallerAs));
	s.push_back(CUTE(testStringInConstructor));
	s.push_back(CUTE(testWrongStringInConstructor));
	s.push_back(CUTE(testInvalidStringForConstructor));
	cute::xml_file_opener xmlfile(argc,argv);
	cute::xml_listener<cute::ide_listener<> >  lis(xmlfile.out);
	cute::makeRunner(lis,argc,argv)(s, "AllTests");
}

int main(int argc, char const *argv[]){
    runAllTests(argc,argv);
    return 0;
}



