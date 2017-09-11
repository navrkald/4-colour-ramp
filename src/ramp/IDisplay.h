#ifndef IDISPLAY_H
#define IDISPLAY_H

class IDisplay {
public:
	virtual bool connect(const char *display_name) = 0;
	virtual void get_size(int &width, int &height) = 0;
	virtual void draw_raster(int x, int y, const unsigned short *pixels, int width) = 0;
};

#endif // !IDISPLAY_H