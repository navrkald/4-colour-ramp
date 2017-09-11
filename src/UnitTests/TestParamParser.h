#ifndef TEST_PARAM_PARSER
#define TEST_PARAM_PARSER


#include "../ramp/ParamParser.h"
#include <iostream>

using namespace std;

class TestParamParser
{
private:
	static ColourRGB565 tl, tr, bl, br;
	static const char* displayName;
public:
	static void TestNumberOfParrams();
	static void TestParamFormat();
	static void TestDefaultValues();
	static void TestLongNumbers();
	static void ClearVariables();
};

#endif // !TEST_PARAM_PARSER
