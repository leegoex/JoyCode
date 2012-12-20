#include "ep_image.hpp"
#include <iostream>
#include <dirent.h>
#include <list>
using namespace std;

ep_image::ep_image()
{
}

ep_image::~ep_image()
{
}

bool ep_image::getImages(const string& imgDir)
{
	bool result = false;
	m_imgFiles.clear();

	DIR* dirp;
	struct dirent* direntp;
	dirp = opendir(imgDir.c_str());
	if( dirp != NULL )
	{
		for(;;)
		{
			direntp = readdir( dirp );
			if( direntp == NULL ) break;
			if(direntp->d_type == DT_DIR) continue;
			string temp = imgDir;
			temp += "/";
			temp += direntp->d_name;
			m_imgFiles.push_back(temp);
			if(m_imgFiles.size()==3)
			{
				result = true;
				break;
			}
		}
		if(m_imgFiles.size()<3) {
			m_imgFiles.clear();
			cout<<"[Get Images]No images\n";
		}
		closedir( dirp );
	}
	return result;
}

void ep_image::moveImages()
{
	vector<string>::const_iterator it = m_imgFiles.begin();
	for(; it != m_imgFiles.end(); ++it)
	{
		string cmd = "mv ";
		cmd += *it;
		cmd += " /home";
		system(cmd.c_str());
	}

	m_imgFiles.clear();
}

bool ep_image::setImages()
{
	bool result = false;
	if(m_imgFiles.size()!=3) {
		return result;
	}
	try {
		vector<string>::const_iterator it = m_imgFiles.begin();
		for(; it != m_imgFiles.end(); ++it) {
			Image img;
			img.read(*it);
			if(m_imgTop.size()<2)
				m_imgTop.push_back(img);
			else
				m_imgBottom.push_back(img);
		}
		result = true;
	}
	catch (Exception &error_)
	{
		cout<<"[Set Images]Caught exception: "<<error_.what()<<endl;
		m_imgTop.clear();
		m_imgBottom.clear();
	}
	return result;
}

bool ep_image::setZoomArea(int x, int y, int width, int height)
{
	bool result = false;
	try {
		if(m_imgTop.size()>0){
			Image firstImg = m_imgTop.at(0);
			Geometry size = firstImg.size();
			size.aspect(true);
			firstImg.crop(Geometry(width, height, x, y));
			firstImg.zoom(size);
			m_imgBottom.push_back(firstImg);
			result = true;
		}
	}
	catch (Exception &error_)
	{
		cout<<"[Set Zoom Area]Caught exception: "<<error_.what()<<endl;
	}
	return result;
}

bool ep_image::appendImage(const string& filename)
{
	bool result = false;
	try {
		Image appendedTop;
		Image appendedBottom;
		vector<Image> temp;
		Image appendedFinal;
		appendImages(&appendedTop, m_imgTop.begin(), m_imgTop.end());
		appendImages(&appendedBottom, m_imgBottom.begin(), m_imgBottom.end());
		temp.push_back(appendedTop);
		temp.push_back(appendedBottom);
		appendImages(&appendedFinal, temp.begin(), temp.end(), true);
		Geometry size = appendedFinal.size();

		//画出分割线
		list<Drawable> line_draw;
		line_draw.push_back(DrawableLine(0,size.height()/2,size.width(),size.height()/2));
		line_draw.push_back(DrawableLine(size.width()/2,0,size.width()/2,size.height()));
		line_draw.push_back(DrawableStrokeColor(Color("red")));
		appendedFinal.draw(line_draw);

		appendedFinal.write(filename);
		result = true;
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
		Geometry size = img.size();
		list<Drawable> text_draw;
		text_draw.push_back(DrawableFont("/usr/share/fonts/truetype/arphic/gkai00mp.ttf"));
		text_draw.push_back(DrawableText(0, 0, text));
		text_draw.push_back(DrawableStrokeColor(Color("red")));
		text_draw.push_back(DrawableFillColor(Color(255, 0, 0, MaxRGB)));
		text_draw.push_back(DrawablePointSize(100.0));
		img.annotate(text,size,Magick::NorthWestGravity);
		img.draw(text_draw);
		result = true;
	}
	catch(Exception &error_)
	{
		cout<<"[Annotate Image]Caught exception: "<<error_.what()<<endl;
	}
	return result;
}
