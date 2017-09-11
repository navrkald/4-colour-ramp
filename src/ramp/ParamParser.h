#ifndef PARAM_PARSER_H
#define PARAM_PARSER_H

#include "Error.h"
#include "ColourRGB565.h"
class ParamParser
{
public:
	static Error ParseArguments(int argc, const char* argv[],
		const char* &displayName,
		ColourRGB565& topLeft, ColourRGB565& topRight,
		ColourRGB565& bottomLeft, ColourRGB565& bottomRight);
private:
	static bool ConvertToUnsignedShort(const char* string, unsigned short& value);
};

#endif // !PARAM_PARSER_H
