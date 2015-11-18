#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include "src/word.h"
#include "src/kwic.h"


void extensiveTest() {
	std::istringstream s{"this is a test\nthis is another test"};
	std::ostringstream os{};
	kwic(s, os);
	ASSERT_EQUAL("a test this is\nanother test this is\nis a test this\nis another test this\ntest this is a\ntest this is another\nthis is a test\nthis is another test", os.str());
}

void testRotatesOneLine() {
	std::istringstream s{"this is a test"};
	std::ostringstream os{};
	kwic(s, os);
	ASSERT_EQUAL("a test this is\nis a test this\ntest this is a\nthis is a test", os.str());
}
void runAllTests(int argc, char const *argv[]){
	cute::suite s;
	s.push_back(CUTE(extensiveTest));
	s.push_back(CUTE(testRotatesOneLine));
	cute::xml_file_opener xmlfile(argc,argv);
	cute::xml_listener<cute::ide_listener<> >  lis(xmlfile.out);
	cute::makeRunner(lis,argc,argv)(s, "AllTests");
}

int main(int argc, char const *argv[]){
    runAllTests(argc,argv);
    return 0;
}



