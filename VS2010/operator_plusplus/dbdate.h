#ifndef _DBDATE_H_
#define _DBDATE_H_

#include <ostream>
using namespace std;

class DBDate
{
public:
	DBDate();
	DBDate(const DBDate& rhs);
	~DBDate();

	DBDate& operator++(); //prefix ++
	DBDate operator++(int); //postfix ++

	DBDate& operator=(const DBDate& rhs);

	friend ostream& operator<<(ostream& os, const DBDate& rhs);

private:
	bool isLoop(int year);
	int m_year;
	int m_mon;
	int m_day;
};

#endif