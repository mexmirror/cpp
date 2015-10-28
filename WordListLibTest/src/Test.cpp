#include "WordList.h"
#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include "istream"
#include "ostream"

void testEqualString(){
	std::istringstream in {"Hello Hello"};
	std::ostringstream os {};
	wlist(in, os);
	ASSERT_EQUAL("Hello\n", os.str());
}

void testTwoEqualStrings(){
	std::istringstream in {"Hello hello Bye bye"};
	std::ostringstream os {};
	wlist(in, os);
	ASSERT_EQUAL("Bye\nHello\n", os.str());
}

void testUnequalString(){
	std::istringstream in {"Xylophon Klavier Gitarre Bass"};
	std::ostringstream os {};
	wlist(in, os);
	ASSERT_EQUAL("Bass\nGitarre\nKlavier\nXylophon\n", os.str());
}
void testInvalidInput(){
	std::istringstream in {"Baum, Haus, Buch"};
	std::ostringstream os{};
	wlist(in, os);
	ASSERT_EQUAL("Baum,\nBuch\nHaus,\n", os.str());
}
void runAllTests(int argc, char const *argv[]){
	cute::suite s;
	s.push_back(CUTE(testEqualString));
	s.push_back(CUTE(testTwoEqualStrings));
	s.push_back(CUTE(testUnequalString));
	s.push_back(CUTE(testInvalidInput));
	cute::xml_file_opener xmlfile(argc,argv);
	cute::xml_listener<cute::ide_listener<> >  lis(xmlfile.out);
	cute::makeRunner(lis,argc,argv)(s, "AllTests");
}

int main(int argc, char const *argv[]){
    runAllTests(argc,argv);
    return 0;
}



