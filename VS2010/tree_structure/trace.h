#ifndef _TRACE_H_
#define _TRACE_H_

#include <time.h>
#include <iostream>
using namespace std;

class PrintInfo
{
public:
	PrintInfo(const char *f = 0, int l = 0);
	void Print(const char *fmt, ...);
	const char *m_file;
	const int m_line;
};

#define PRINT(X)\
	do {\
	PrintInfo __Log(__FILE__, __LINE__);\
	__Log.Print X;\
	} while(0);


class Timepiece
{
public:
	Timepiece() {
		m_t = clock();
	}
	~Timepiece(){
		cout<<"Time elapsed:"<<clock()-m_t<<endl;
	}
private:
	clock_t m_t;
};

#endif