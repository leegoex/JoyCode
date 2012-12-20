#include <iostream> 
#include <string>
#include <pthread.h>
#include <unistd.h>
#include "ep_image.hpp"
using namespace std; 

void* thread_start(void *arg)
{
	string sDir = (const char*)arg;
	while(1)
	{
		ep_image epImg;
		if(epImg.getImages(sDir) == true)
		{
			epImg.setImages();
			epImg.setZoomArea(1370,700,1000,1408);
			epImg.appendImage("demo.jpg");
			epImg.moveImages();
		}
		usleep(1000*1000);
	}
	return (void*)0;
}

int main(int argc,char **argv) 
{ 
  InitializeMagick(*argv);

  string sDir = "/home/imagemagicdemo";
  pthread_t th;
  int result = pthread_create(&th, NULL, thread_start, (void*)sDir.c_str());
  if(result != 0)
  {
	  cout<<"create thread failed\n";
	  return -1;
  }else {

	  int i = 0;
	  cin>>i;
  }

  return 0; 
}
