#include "ep_image.hpp"
#include <iostream>
#include <list>
using namespace std;

ep_image::ep_image() : m_style(HORITOP)
{
}

ep_image::~ep_image()
{
}

bool ep_image::setImages(const vector<string>& images)
{
	bool result = false;
	try {
		vector<string>::const_iterator it = images.begin();
		for(; it != images.end(); ++it) {
			Image img;
			img.read(*it);
			m_images.push_back(img);
		}
		result = true;
	}
	catch (Exception &error_)
	{
		cout<<"[Set Images]Caught exception: "<<error_.what()<<endl;
		m_images.clear();
	}
	return result;
}

bool ep_image::setZoomArea(int x, int y, int width, int height)
{
	bool result = false;
	try {
		if(m_images.size()>0){
			Image firstImg = m_images.at(0);
			m_zoomImage = firstImg;
			m_zoomImage.crop(Geometry(width, height, x, y));
			result = true;
		}
	}
	catch (Exception &error_)
	{
		cout<<"[Set Zoom Area]Caught exception: "<<error_.what()<<endl;
	}
	return result;
}

void ep_image::setAppend(AppendStyle style)
{
	m_style = style;
}

bool ep_image::appendImage(const string& filename)
{
	bool result = false;
	try {
		Image appended;
		Image ndAppended;
		vector<Image> temp;
		if(m_style<VERTLEFT) {
			appendImages(&appended, m_images.begin(), m_images.end());
		}else {
			appendImages(&appended, m_images.begin(), m_images.end(),true);
		}
		Geometry size = appended.size();
		size.aspect(true);
		m_zoomImage.zoom(size);
		switch(m_style)
		{
		case HORITOP:
			temp.push_back(m_zoomImage);
			temp.push_back(appended);
			break;
		case HORIBOTTOM:
			temp.push_back(appended);
			temp.push_back(m_zoomImage);
			break;
		case VERTLEFT:
			temp.push_back(m_zoomImage);
			temp.push_back(appended);
			break;
		case VERTRIGHT:
			temp.push_back(appended);
			temp.push_back(m_zoomImage);
			break;
		}
		if(m_style<VERTLEFT) {
			appendImages(&ndAppended, temp.begin(), temp.end(), true);
		}else {
			appendImages(&ndAppended, temp.begin(), temp.end());
		}
		ndAppended.zoom(size);
		if(annotateImage(ndAppended, "你好，世界")==true)
		{
			ndAppended.write(filename);
			result = true;
		}
	}
	catch(Exception &error_)
	{
		cout<<"[Append Image]Caught exception: "<<error_.what()<<endl;
	}
	return result;
}

bool ep_image::annotateImage(Image& img, const string& text)
{
	bool result = false;
	try {
		list<Drawable> text_draw;
		text_draw.push_back(DrawableFont("/usr/share/fonts/truetype/arphic/gkai00mp.ttf"));
		text_draw.push_back(DrawableText(0, 0, text));
		text_draw.push_back(DrawableStrokeColor(Color("red")));
		text_draw.push_back(DrawableFillColor(Color(255, 0, 0, MaxRGB)));
		text_draw.push_back(DrawablePointSize(172.0));
		img.annotate(text, Magick::NorthWestGravity);
		img.draw(text_draw);
		result = true;
	}
	catch(Exception &error_)
	{
		cout<<"[Annotate Image]Caught exception: "<<error_.what()<<endl;
	}
	return result;
}
