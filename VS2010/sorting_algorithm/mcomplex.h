#ifndef _MCOMPLEX_H_
#define _MCOMPLEX_H_

#include <ostream>
using namespace std;

class mcomplex
{
public:
	//构造函数
	mcomplex();
	mcomplex(int r);
	mcomplex(int r, int i);
	//拷贝构造函数
	mcomplex(const mcomplex& rhs);
	//赋值函数
	mcomplex& operator=(const mcomplex& rhs);

	bool operator>(const mcomplex& rhs);
	bool operator>=(const mcomplex& rhs);
	bool operator<(const mcomplex& rhs);
	bool operator<=(const mcomplex& rhs);
	bool operator==(const mcomplex& rhs);
	bool operator!=(const mcomplex& rhs);

	friend ostream& operator<<(ostream& os, const mcomplex& rhs);

private:
	int m_r;
	int m_i;
};

#endif