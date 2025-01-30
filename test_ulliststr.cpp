#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

using namespace std;

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  /*

  ULListStr testList;

  // This is for push back
  cout << "PB: Size before: " << testList.size() << endl;

  testList.push_back("first back String");
  testList.push_back("second back String");

  cout << testList.back() << " " << testList.front() << endl;
  cout << "PB: Size after: " << testList.size() << endl;

  // This is for push front
  cout << "PF: Size before: " << testList.size() << endl;

  testList.push_front("first front String");
  testList.push_front("second front String");

  cout << testList.back() << " " << testList.front() << endl;
  cout << "PF: Size after: " << testList.size() << endl;

  // This is for pop back
  cout << "POB: Size before: " << testList.size() << endl;
  
  testList.pop_back();

  cout << testList.back() << endl;
  cout << "POB: Size after: " << testList.size() << endl;

  // This is for pop front
  cout << "POF: Size before: " << testList.size() << endl;
  
  testList.pop_front();

  cout << testList.front() << endl;
  cout << "POF: Size after: " << testList.size() << endl;

  //cout << testList.get(3);
  // cout << testList.back();

  ULListStr testList2;
  testList2.push_back("1");
  testList2.push_back("2");
  testList2.push_back("3");
  testList2.push_back("4");
  testList2.push_back("5");
  testList2.push_back("6");
  testList2.push_back("7");
  testList2.push_back("8");
  testList2.push_back("9");
  testList2.push_back("10");
  testList2.push_back("11");
  testList2.push_back("12");

  testList2.pop_back(); 
  testList2.pop_front(); 
  testList2.pop_front();


  cout << testList2.get(0) << endl;
  cout << testList2.get(1) << endl;
  cout << testList2.get(2) << endl;
  //cout << testList2.get() << endl;

  */

  // TEST(ListRemove, SongOfBackAndFront)
	ULListStr list;

	list.push_back("oldfront");
	list.push_back("oldback");

	// EXPECT_TRUE(checkListContent(&list, {"oldfront", "oldback"}));
  cout << list.get(0) << endl;
  cout << list.get(1) << endl;

	// this should create an empty slot at the front of the list, and the new element can be put there
	list.pop_front();
	list.push_front("newfront");

	// EXPECT_TRUE(checkListContent(&list, {"newfront", "oldback"}));
  cout << list.get(0) << endl;
  cout << list.get(1) << endl;

	// now, a new element struct should get created at the front
	list.pop_back();
	list.push_front("cloudfront");

	// EXPECT_TRUE(checkListContent(&list, {"cloudfront", "newfront"}));
  cout << list.get(9) << endl;
  cout << list.get(10) << endl;
  // Should be Bad Location
  // cout << list.get(11) << endl;

	// now, the original head should get deleted
	list.pop_back();

	// EXPECT_TRUE(checkListContent(&list, {"cloudfront"}));
  // Should be a Bad Location
  // cout << list.get(10) << endl;

  // the whole list should be empty
	list.pop_front();

	// EXPECT_TRUE(checkListContent(&list, {}));
  cout << list.empty() << endl;
  // Should output 1 or True
  // cout << list.get(9)

  // a new and only element added
	list.push_front("newback");

	// EXPECT_TRUE(checkListContent(&list, {"newback"}));
  cout << list.get(0) << endl;

}
