#ifndef DISPLAY_H
#define DISPLAY_H

#include "IDisplay.h"

class Display : public IDisplay{
public:
	Display();
	~Display();
	virtual bool connect(const char *display_name);
	virtual void get_size(int &width, int &height);
	virtual void draw_raster(int x, int y, const unsigned short *pixels, int width);
};

#endif // !DISPLAY_H
