#ifndef _EP_IMAGE_HPP_
#define _EP_IMAGE_HPP_

#include <vector>
#include <string>
#include <Magick++.h>
using namespace std;
using namespace Magick;

class ep_image
{
public:
	ep_image();
	~ep_image();

	enum AppendStyle { HORITOP=0, HORIBOTTOM=1, VERTLEFT=2, VERTRIGHT=3 };

	bool setImages(const vector<string>& images);
	bool setZoomArea(int x, int y, int width, int height);
	void setAppend(AppendStyle style);
	bool appendImage(const string& filename);

private:
	bool annotateImage(Image& img, const string& text);
	vector<Image> m_images;
	Image m_zoomImage;
	AppendStyle m_style;
};

#endif
