#include "IndexableSet.h"
#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"

void testIndexableSet(){
	indexableSet<int> set {1,2,3,4,5,6};
	ASSERT_EQUAL(6, set.size());
}
void testFront(){
	indexableSet<int> set {1,2,3,4,5,6};
	ASSERT_EQUAL(1, set.front());
}
void testBack(){
	indexableSet<int> set {1,2,3,4,5,6};
	ASSERT_EQUAL(6, set.back());
}
void testIndexAccess(){
	indexableSet<int> set {1,2,3,5,8,13};
	ASSERT_EQUAL(5, set[3]);
}
void testCompareCaseless(){
	indexableSet<std::string, caselessCompare> set {"Angular", "Amgular", "Abular"};
	ASSERT_EQUAL("Abular", set[0]);
}
void testOutOfRange(){
	indexableSet<std::string, caselessCompare> set {"Bono", "Bond", "Bobo"};
	ASSERT_THROWS(set[4], std::out_of_range);
}
void testNegativeOutOfRange(){
	indexableSet<std::string, caselessCompare> set {"Bono", "Bond", "Bobo"};
	ASSERT_THROWS(set[-4], std::out_of_range);
}

void runAllTests(int argc, char const *argv[]){
	cute::suite s;
	s.push_back(CUTE(testIndexableSet));
	s.push_back(CUTE(testFront));
	s.push_back(CUTE(testBack));
	s.push_back(CUTE(testCompareCaseless));
	s.push_back(CUTE(testIndexAccess));
	s.push_back(CUTE(testOutOfRange));
	s.push_back(CUTE(testNegativeOutOfRange));
	cute::xml_file_opener xmlfile(argc,argv);
	cute::xml_listener<cute::ide_listener<> >  lis(xmlfile.out);
	cute::makeRunner(lis,argc,argv)(s, "AllTests");
}

int main(int argc, char const *argv[]){
    runAllTests(argc,argv);
    return 0;
}



