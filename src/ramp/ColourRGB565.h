#ifndef COLOUR_RGB565_H
#define COLOUR_RGB565_H

struct ColourRGB565
{
	ColourRGB565();
public:
	ColourRGB565(unsigned short color);
	ColourRGB565(unsigned short red, unsigned short green, unsigned short blue) :
		m_red(red), m_green(green), m_blue(blue) {}
	void Initialize(unsigned short color);
	bool IsEmpty() const { return m_empty; }
	void Clear() { m_empty = true; }
	unsigned short GetValue();
	unsigned short m_red;
	unsigned short m_green;
	unsigned short m_blue;
	ColourRGB565& operator=(const ColourRGB565& other);

private:
	const unsigned short m_redBitMask = 0xF800;
	const unsigned short m_greenBitMask = 0x07E0;
	const unsigned short m_blueBitMask = 0x001F;
	bool m_empty;
};

#endif // !COLOUR_RGB565_H
