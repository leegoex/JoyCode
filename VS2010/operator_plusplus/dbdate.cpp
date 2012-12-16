#include "dbdate.h"
#include <iomanip>

DBDate::DBDate() 
	: m_year(1970),
	m_mon(1),
	m_day(1)
{

}

DBDate::~DBDate()
{

}

DBDate::DBDate(const DBDate& rhs)
{
	m_year = rhs.m_year;
	m_mon = rhs.m_mon;
	m_day = rhs.m_day;
}

DBDate& DBDate::operator++()
{
	switch (m_mon)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		if (m_day==31) {
			m_day=1;
			if (m_mon==12) {
				m_mon=1;
				m_year+=1;
			} else {
				m_mon+=1;
			}
		} else {
			m_day+=1;
		}
		break;
	case 2:
		if (m_day<28 || ((m_day==28) && isLoop(m_year))) {
			m_day+=1;
		} else {
			m_day = 1;
			m_mon += 1;
		}
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		if (m_day==30) {
			m_day = 1;
			m_mon += 1;
		} else {
			m_day += 1;
		}
		break;
	}

	return *this;
}

DBDate DBDate::operator++(int)
{
	DBDate dt(*this);
	++(*this);
	return dt;
}

DBDate& DBDate::operator=(const DBDate& rhs)
{
	if (&rhs == this)
		return *this;
	m_year = rhs.m_year;
	m_mon = rhs.m_mon;
	m_day = rhs.m_day;
	return *this;
}

bool DBDate::isLoop(int year)
{
	return ((m_year%4==0) && ((m_year%100!=0)||(m_year%400==0)));
}

ostream& operator<<(ostream& os, const DBDate& rhs)
{
	os<<rhs.m_year<<'-'<<setfill('0')<<setw(2)<<rhs.m_mon<<'-'<<setfill('0')<<setw(2)<<rhs.m_day;
	return os;
}