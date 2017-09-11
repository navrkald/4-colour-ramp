#include "TestParamParser.h"
#include "TestColourRamp.h"

int main()
{
	TestParamParser::TestNumberOfParrams();
	TestParamParser::TestParamFormat();
	TestParamParser::TestDefaultValues();
	TestParamParser::TestLongNumbers();
	TestColourRamp::TestCouldNotConnectToDisplay();
	TestColourRamp::TestToSmallDisplay();
	TestColourRamp::TestBasicRamps();
    return 0;
}

