#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include "src/Word.h"

void testDoesntReadGarbageFROMSTDString() {
	std::string s{"'''--"};
	std::ostringstream os{};
	Word word;
	s >> word;
	os << word;
	ASSERT_EQUAL("", os.str());
}

void testReadsFromSTDString() {
	std::string s{"hello"};
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
	while(!in.eofbit) {
		in >> word;
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
	while(!in.eofbit) {
		in >> word;
		os << word;
	}
	ASSERT_EQUAL("abik", os.str());
}

void testIgnoresTabs() {
	std::istringstream in {"		ab	\t ik"};
	std::ostringstream os {};
	Word word{};
	while(!in.eofbit) {
		in >> word;
		os << word;
	}
	ASSERT_EQUAL("abik", os.str());
}

void testIgnoresWhiteSpace() {
	std::istringstream in {"                ab             ik"};
	std::ostringstream os {};
	Word word{};
	while(!in.eofbit) {
		in >> word;
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
	while(!in.eofbit) {
		in >> word;
		os << word << ", ";
	}
	ASSERT_EQUAL("compl, tely, weird, matted, in, put, ", os.str());

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
	s.push_back(CUTE(testReadsFromSTDString));
	s.push_back(CUTE(testDoesntReadGarbageFROMSTDString));
	cute::xml_file_opener xmlfile(argc,argv);
	cute::xml_listener<cute::ide_listener<> >  lis(xmlfile.out);
	cute::makeRunner(lis,argc,argv)(s, "AllTests");
}

int main(int argc, char const *argv[]){
    runAllTests(argc,argv);
    return 0;
}



