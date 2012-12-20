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

	bool getImages(const string& imgDir);
	void moveImages();

	bool setImages();
	bool setZoomArea(int x, int y, int width, int height);
	bool appendImage(const string& filename);

private:
	bool annotateImage(Image& img, const string& text);
	vector<string> m_imgFiles;
	vector<Image> m_imgTop;
	vector<Image> m_imgBottom;
};

#endif
