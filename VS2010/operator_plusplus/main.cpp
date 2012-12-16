#include <iostream>
#include "dbdate.h"
using namespace std;

int main(int argc, char *argv[])
{
	DBDate dt;
	int index = 0;
	for (index=0; index<1000; ++index, ++dt)
	{
		cout<<dt<<endl;
	}
	system("pause");
	return 0;
}