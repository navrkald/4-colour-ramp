#include "TestParamParser.h"
#include <assert.h>

#define SIZE_OF_ARRAY(ARRAY) (((sizeof(ARRAY))/sizeof((ARRAY)[0])))

ColourRGB565 TestParamParser::tl, TestParamParser::tr, TestParamParser::bl, TestParamParser::br;
const char* TestParamParser::displayName;

void TestParamParser::TestNumberOfParrams() {
	ClearVariables();
	const char* argv[] = { "programName.exe", "firstParam" };
	assert( ParamParser::ParseArguments(SIZE_OF_ARRAY(argv), argv, displayName, tl, tr, bl, br) == Error(paramCount));
	ClearVariables();
	const char* argv2[] = { "programName.exe", "displayName", "1", "2", "3", "4", "5" };
	assert(ParamParser::ParseArguments(SIZE_OF_ARRAY(argv2), argv2, displayName, tl, tr, bl, br) == Error(paramCount));
	ClearVariables();
	const char* argv3[] = { "programName.exe", "displayName", "1", "2", "3", "4" };
	assert(ParamParser::ParseArguments(SIZE_OF_ARRAY(argv3), argv3, displayName, tl, tr, bl, br) == Error(ok));
}

void TestParamParser::TestParamFormat()
{
	ClearVariables();
	const char* argv[] = { "programName.exe",  "displayName", "   1", "0x2", "0X3", "  4somemess  " };
	assert(ParamParser::ParseArguments(SIZE_OF_ARRAY(argv), argv, displayName, tl, tr, bl, br) == Error(paramFormat));
	// Fail2
	ClearVariables();
	const char* argv2[] = { "programName.exe",  "displayName", "   1", "0x2", "0X3", "someMess" };
	assert(ParamParser::ParseArguments(SIZE_OF_ARRAY(argv2), argv2, displayName, tl, tr, bl, br) == Error(paramFormat));
	
	// Correct tests1
	ClearVariables();
	const char* argv3[] = { "programName.exe",  "displayName", "   1", "0x2", "0X3", "  4   " };
	assert(ParamParser::ParseArguments(SIZE_OF_ARRAY(argv3), argv3, displayName, tl, tr, bl, br) == Error(ok));
	assert(tl.GetValue() == 1);
	assert(tr.GetValue() == 2);
	assert(bl.GetValue() == 3);
	assert(br.GetValue() == 4);
	
	// Correct test2
	ClearVariables();
	const char* argv4[] = { "programName.exe",  "displayName", "   1", "0xA", "0Xb", "0" };
	assert(ParamParser::ParseArguments(SIZE_OF_ARRAY(argv4), argv4, displayName, tl, tr, bl, br) == Error(ok));
	assert(tl.GetValue() == 1);
	assert(tr.GetValue() == 10);
	assert(bl.GetValue() == 11);
	assert(br.GetValue() == 0);
}

void TestParamParser::TestDefaultValues()
{
	ClearVariables();
	const char* argv[] = { "programName.exe",  "displayName", "0x66", "0x0"};
	assert(ParamParser::ParseArguments(SIZE_OF_ARRAY(argv), argv, displayName, tl, tr, bl, br) == Error(ok));
	assert(tl.GetValue() == 102);
	assert(tr.GetValue() == 0);
	assert(bl.GetValue() == 102);
	assert(br.GetValue() == 0);

	ClearVariables();
	const char* argv2[] = { "programName.exe",  "displayName", "0x1", "0x0", "0x6"};
	assert(ParamParser::ParseArguments(SIZE_OF_ARRAY(argv2), argv2, displayName, tl, tr, bl, br) == Error(ok));
	assert(tl.GetValue() == 0x1);
	assert(tr.GetValue() == 0);
	assert(bl.GetValue() == 6);
	assert(br.GetValue() == 0);
}

void TestParamParser::TestLongNumbers()
{
	ClearVariables(); 
	const char* argv[] = { "programName.exe",  "displayName", "65536", "65536" };
	assert(ParamParser::ParseArguments(SIZE_OF_ARRAY(argv), argv, displayName, tl, tr, bl, br) == Error(paramFormat));

	ClearVariables();
	const char* argv2[] = { "programName.exe",  "displayName", "65535", "65535", "-1" };
	assert(ParamParser::ParseArguments(SIZE_OF_ARRAY(argv2), argv2, displayName, tl, tr, bl, br) == Error(ok));
	assert(tl.GetValue() == 65535);
	assert(tr.GetValue() == 65535);
	assert(bl.GetValue() == 65535);
	assert(br.GetValue() == 0xffff);
} 

void TestParamParser::ClearVariables()
{
	tl.Clear(); 
	tr.Clear(); 
	bl.Clear(); 
	br.Clear();
	displayName = nullptr;
}
