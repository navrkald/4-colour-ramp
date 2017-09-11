#ifndef COLOUR_RAMP_H
#define COLOUR_RAMP_H

#include "Display.h"
#include "ColourRGB565.h"
#include "Error.h"


class ColourRamp
{
private:
	IDisplay& m_display;
	const char* m_displayName;
	ColourRGB565 m_topLeft, m_topRight, m_downLeft, m_downRight;
	int m_width, m_height;
	Error SetAndCheckDimensions();
	unsigned short CalculateOneColorComponent(
		unsigned short topLeft, unsigned short topRight, 
		unsigned short downLeft, unsigned short downRight,
		double relativeX, double relativeY);
	ColourRGB565 CalculateOnePixel(int x, int y);
public:
	ColourRamp(IDisplay& display, const char* displayName) : m_display(display), m_displayName(displayName) {}
	Error Create4ColourRam(ColourRGB565 topLeft, ColourRGB565 topRight, ColourRGB565 downLeft, ColourRGB565 downRight);
};

#endif // !COLOUR_RAMP_H