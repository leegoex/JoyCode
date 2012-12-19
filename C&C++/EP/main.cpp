#include <iostream> 
#include <string>
#include "ep_image.hpp"
using namespace std; 
int main(int argc,char **argv) 
{ 
  InitializeMagick(*argv);

  ep_image epImg;
  vector<string> images;
  images.push_back("192.168.0.10_1108071759143412C000_110807175914_110807175915_110807175913.jpg");
  images.push_back("192.168.0.10_1108071759143412A000_110807175914_110807175915_110807175913.jpg");
  images.push_back("192.168.0.10_1108071759143412B000_110807175914_110807175915_110807175913.jpg");
  if(epImg.setImages(images)==true) 
  {
	  if(epImg.setZoomArea(1370, 700, 1000, 1408)==true)
	  {
	  	epImg.setAppend(ep_image::HORITOP);
		if(epImg.appendImage("demo.jpg")==true)
		{
			cout<<"Demo succeed\n";
		}
		else
		{
			cout<<"Append Image failed\n";
		}
	  }
	  else
	  {
		  cout<<"Set Image Zoom Area failed\n";
	  }
  }
  else
  {
	  cout<<"Set Images failed\n";
  }

  return 0; 
}
