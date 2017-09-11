#include "MocDisplay.h"

inline void MocDisplay::SetSize(int width, int height) {
	m_width = width;
	m_height = height; 
	if (width>0 && height > 0) 
		m_frameBuffer.resize(width*height);
}

bool MocDisplay::connect(const char * display_name)
{
	return m_connect;
}

void MocDisplay::get_size(int & width, int & height)
{
	width = m_width;
	height = m_height;
}

void MocDisplay::draw_raster(int x, int y, const unsigned short * pixels, int width)
{
	// Copy data to vector
	for (int i = 0, frameBufferPos = y*m_width + x; i < width; i++, frameBufferPos++) {
		m_frameBuffer[frameBufferPos] = pixels[i];
	}
}
