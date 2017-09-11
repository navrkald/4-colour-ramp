#include "ColourRamp.h"

Error ColourRamp::Create4ColourRam(ColourRGB565 topLeft, ColourRGB565 topRight, ColourRGB565 downLeft, ColourRGB565 downRight)
{
	// Try to connect to display
	if (!m_display.connect(m_displayName)) {
		return Error(displayConnect);
	}

	m_topLeft = topLeft;
	m_topRight = topRight;
	m_downLeft = downLeft;
	m_downRight = downRight;
	Error err(ok);
	if ((err = SetAndCheckDimensions()).Failed()) {
		return err;
	}
	unsigned short* row = new unsigned short[m_width];
	for (int y = 0; y < m_height; y++) {
		for (int x = 0; x < m_width; x++) {
			row[x] = CalculateOnePixel(x, y).GetValue();
		}
		m_display.draw_raster(0, y, row, m_width);
	}
	delete [] row;
	return err;
}

Error ColourRamp::SetAndCheckDimensions()
{
	m_display.get_size(m_width, m_height);
	if (m_width <= 1 || m_height <= 1) {
		return Error(displaySize);
	}
	return Error(ok);
}


// Inspirated by https://stackoverflow.com/questions/2977196/4-colors-gradient-logic-needed
unsigned short ColourRamp::CalculateOneColorComponent(
	unsigned short topLeft, unsigned short topRight, 
	unsigned short downLeft, unsigned short downRight,
	double relativeX, double relativeY)
{
	return 
		((unsigned short)(topLeft * (1 - relativeX) * (1 - relativeY) +
		topRight * relativeX * (1 - relativeY) + 
		downLeft * (1 - relativeX) * relativeY + 
		downRight *relativeX*relativeY));
}

// Inspirated by https://stackoverflow.com/questions/2977196/4-colors-gradient-logic-needed
ColourRGB565 ColourRamp::CalculateOnePixel(int x, int y) {
	double relativeX = ((double) x) / (m_width -1);
	double relativeY = ((double) y) / (m_height -1);
	
	return ColourRGB565(
		CalculateOneColorComponent(m_topLeft.m_red, m_topRight.m_red, m_downLeft.m_red, m_downRight.m_red, relativeX, relativeY),
		CalculateOneColorComponent(m_topLeft.m_green, m_topRight.m_green, m_downLeft.m_green, m_downRight.m_green, relativeX, relativeY),
		CalculateOneColorComponent(m_topLeft.m_blue, m_topRight.m_blue, m_downLeft.m_blue, m_downRight.m_blue, relativeX, relativeY)
		);
}
