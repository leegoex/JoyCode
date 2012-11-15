#ifndef _MCOMPLEX_H_
#define _MCOMPLEX_H_

#include <ostream>
using namespace std;

class mcomplex
{
public:
	//���캯��
	mcomplex();
	mcomplex(int r);
	mcomplex(int r, int i);
	//�������캯��
	mcomplex(const mcomplex& rhs);
	//��ֵ����
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