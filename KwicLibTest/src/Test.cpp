#include "Word.h"
#include "kwic.h"
#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"


void extensiveTest() {
	std::istringstream s{"this is a test\nthis is another test"};
	std::ostringstream os{};
	kwic(s, os);
	ASSERT_EQUAL(	"a test this is \n"
					"another test this is \n"
					"is a test this \n"
					"is another test this \n"
					"test this is a \n"
					"test this is another \n"
					"this is a test \n"
					"this is another test \n",
					os.str());
}

void testRotatesOneLine() {
	std::istringstream s{"this is a test"};
	std::ostringstream os{};
	kwic(s, os);
	ASSERT_EQUAL(	"a test this is \n"
					"is a test this \n"
					"test this is a \n"
					"this is a test \n", os.str());
}

void testSimpleCase() {
	std::istringstream s{"is a"};
	std::ostringstream os{};
	kwic(s, os);
	ASSERT_EQUAL("a is \nis a \n", os.str());
}
void testEmptyString() {
	std::istringstream is {""};
	std::ostringstream os{};
	kwic(is, os);
	ASSERT_EQUAL("", os.str());
}
void testGarbageString(){
	std::istringstream is {"Maus!!//Moritz283Mag][-Jeder[[``"};
	std::ostringstream os{};
	kwic(is, os);
	ASSERT_EQUAL(	"Jeder Maus Moritz Mag \n"
					"Mag Jeder Maus Moritz \n"
					"Maus Moritz Mag Jeder \n"
					"Moritz Mag Jeder Maus \n",
					os.str());
}
void testSingleString(){
	std::istringstream is {"Maus"};
	std::ostringstream os {};
	kwic(is, os);
	ASSERT_EQUAL("Maus \n", os.str());
}
void testWhitespace(){
	std::istringstream is {"    ab     ik    ki    ba"};
	std::ostringstream os{};
	kwic(is, os);
	ASSERT_EQUAL(	"ab ik ki ba \n"
					"ba ab ik ki \n"
					"ik ki ba ab \n"
					"ki ba ab ik \n"
					, os.str());
}
void testNewLine(){
	std::istringstream is {	"do\n"
							"not\n"
							"talk\n"
							"about\n"
							"fight\n"
							"club"};
	std::ostringstream os {};
	kwic(is, os);
	ASSERT_EQUAL(	"about \n"
					"club \n"
					"do \n"
					"fight \n"
					"not \n"
					"talk \n"
					, os.str());
}
void testCaseSensitivity(){
	std::istringstream is{"DO NOT TALK about fight club"};
	std::ostringstream os{};
	kwic(is, os);
	ASSERT_EQUAL(	"about fight club DO NOT TALK \n"
					"club DO NOT TALK about fight \n"
					"DO NOT TALK about fight club \n"
					"fight club DO NOT TALK about \n"
					"NOT TALK about fight club DO \n"
					"TALK about fight club DO NOT \n"
					, os.str());
}
void testTabBetweenWords(){
	std::istringstream is{"	May	the	force	be	with	you"};
	std::ostringstream os {};
	kwic(is, os);
	ASSERT_EQUAL(	"be with you May the force \n"
					"force be with you May the \n"
					"May the force be with you \n"
					"the force be with you May \n"
					"with you May the force be \n"
					"you May the force be with \n"
					, os.str());
}
void testDuplicateWord(){
	std::istringstream is {"Bond James Bond"};
	std::ostringstream os {};
	kwic(is, os);
	ASSERT_EQUAL(	"Bond Bond James \n"
					"Bond James Bond \n"
					"James Bond Bond \n"
					, os.str());
}
void testGarbage(){
	std::istringstream is {"2390492423492309489023!!::::::...---;..."};
	std::ostringstream os {};
	kwic(is, os);
	ASSERT_EQUAL("", os.str());
}
void runAllTests(int argc, char const *argv[]){
	cute::suite s;
	s.push_back(CUTE(extensiveTest));
	s.push_back(CUTE(testRotatesOneLine));
	s.push_back(CUTE(testSimpleCase));
	s.push_back(CUTE(testEmptyString));
	s.push_back(CUTE(testGarbageString));
	s.push_back(CUTE(testSingleString));
	s.push_back(CUTE(testWhitespace));
	s.push_back(CUTE(testNewLine));
	s.push_back(CUTE(testCaseSensitivity));
	s.push_back(CUTE(testTabBetweenWords));
	s.push_back(CUTE(testGarbage));
	s.push_back(CUTE(testDuplicateWord));
	cute::xml_file_opener xmlfile(argc,argv);
	cute::xml_listener<cute::ide_listener<> >  lis(xmlfile.out);
	cute::makeRunner(lis,argc,argv)(s, "AllTests");
}

int main(int argc, char const *argv[]){
    runAllTests(argc,argv);
    return 0;
}



