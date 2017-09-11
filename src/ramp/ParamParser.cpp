#include "ParamParser.h"
#include <cstdlib>
#include <errno.h>
#include <sstream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <cctype>

#define MIN_PARAM_COUNT 4
#define MAX_PARAM_COUNT 6

using namespace std;

Error ParamParser::ParseArguments(int argc, const char * argv[], const char* &displayName, ColourRGB565 & topLeft, ColourRGB565 & topRight, ColourRGB565 & bottomLeft, ColourRGB565 & bottomRight)
{
	if (argc < 4 || argc > 6) {
		return Error(paramCount);
	}

	displayName = argv[1];
	unsigned short number;
	for (int i = 2; i < argc; i++) {
		if (!ConvertToUnsignedShort(argv[i], number)) {
			return Error(paramFormat);
		}

		switch (i)
		{
			case 2:
				topLeft.Initialize(number);
				break;
			case 3:
				topRight.Initialize(number);
				break;
			case 4:
				bottomLeft.Initialize(number);
				break;
			case 5:
				bottomRight.Initialize(number);
				break;
		}
	}

	if (bottomLeft.IsEmpty()) bottomLeft = topLeft;
	if (bottomRight.IsEmpty()) bottomRight = topRight;

	return Error(ok);
}

bool ParamParser::ConvertToUnsignedShort(const char * str, unsigned short& value)
{
	string tmp = str;
	// Trim whitespace
	tmp.erase(std::remove_if(tmp.begin(), tmp.end(), std::isspace), tmp.end());
	std::istringstream ss(tmp);
	ss >> std::setbase(0) >> value;
	bool b1, b2;
	b1 = !ss.fail();
	b2 = ss.eof();
	return !ss.fail() && ss.eof();
/*	

	int base = 10;
	if (str[0] == '0' && (str[1] == 'x' || 'X')) base = 16;
	char* endPos;
	unsigned long result = strtoul(str, &endPos, base);
	
 	if (errno != 0 || endPos == str) {
		errno = 0;
		return false;
	}

	// Check if unsinged long value in result is not bigger that unsigned short
	const unsigned short maxUnsignedshort = -1;
	const unsigned long maxUnsignedLong = -1;
	if (((maxUnsignedLong - maxUnsignedshort) & result) > 0) {
		return false;
	}
	else {
		value = (unsigned short) result;
	}

	return true;
	*/
}
