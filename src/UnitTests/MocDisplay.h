#ifndef MOC_DISPLAY_H
#define MOC_DISPLAY_H

#include "../ramp/IDisplay.h"
#include <vector>

class MocDisplay : public IDisplay
{
public:
	MocDisplay(int width, int height, bool connect) : m_width(width), m_height(height), m_connect(connect) { if(width>0 && height > 0) m_frameBuffer.resize(width*height); }

	void SetSize(int width, int height);;

	// Inherited via IDisplay
	virtual bool connect(const char * display_name) override;
	virtual void get_size(int & width, int & height) override;
	virtual void draw_raster(int x, int y, const unsigned short * pixels, int width) override;
	std::vector<unsigned short> m_frameBuffer;

private:
	int m_width;
	int m_height;
	bool m_connect;
};

#endif // !MOC_DISPLAY_H
