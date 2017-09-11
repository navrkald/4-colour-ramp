#include "ColourRGB565.h"


ColourRGB565::ColourRGB565() : m_red(0), m_green(0), m_blue(0), m_empty(true) {}

ColourRGB565::ColourRGB565(unsigned short color)
{
	Initialize(color);
}

void ColourRGB565::Initialize(unsigned short color)
{
	m_red = (color & m_redBitMask) >> 11;
	m_green = (color & m_greenBitMask) >> 5;
	m_blue = color & m_blueBitMask;
	m_empty = false;
}

unsigned short ColourRGB565::GetValue()
{
	return (m_red << 11) | (m_green << 5) | m_blue;
}

ColourRGB565& ColourRGB565::operator=(const ColourRGB565 & other)
{
	m_red = other.m_red;
	m_green = other.m_green;
	m_blue = other.m_blue;
	m_empty = other.IsEmpty();
	return *this;

}
