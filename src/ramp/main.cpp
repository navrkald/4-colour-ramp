#include "Display.h"
#include "ParamParser.h"
#include "ColourRamp.h"

#include <string>
#include <iostream>

using namespace std;

int main(int argc, const char* argv[])
{
	ColourRGB565 topLeft, topRight, bottomLeft, bottomRight;
	const char* displayName;
	Error err(ok);

	if ((err = ParamParser::ParseArguments(argc, argv, displayName, topLeft, topRight, bottomLeft, bottomRight)).Failed()) {
		err.PrintErrorMessageAndExit();
	}

	Display d;

	ColourRamp colourRamp(d, displayName);

	if ((err = colourRamp.Create4ColourRam(topLeft, topRight, bottomLeft, bottomRight)).Failed()) {
		err.PrintErrorMessageAndExit();
	}

    return 0;
}

