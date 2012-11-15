#include "mcomplex.h"

mcomplex::mcomplex() : m_r(0), m_i(0)
{

}

mcomplex::mcomplex(int r) : m_r(r), m_i(0)
{

}

mcomplex::mcomplex(int r, int i) : m_r(r), m_i(i)
{

}

mcomplex::mcomplex(const mcomplex& rhs)
{
	m_r = rhs.m_r;
	m_i = rhs.m_i;
}

mcomplex& mcomplex::operator=(const mcomplex& rhs)
{
	if(this == &rhs)
		return *this;
	m_r = rhs.m_r;
	m_i = rhs.m_i;
	return *this;
}

bool mcomplex::operator>(const mcomplex& rhs)
{
	if (m_r > rhs.m_r)
		return true;
	else if(m_r == rhs.m_r && m_i > rhs.m_i)
		return true;
	else 
		return false;
}

bool mcomplex::operator>=(const mcomplex& rhs)
{
	return !operator<(rhs);
}

bool mcomplex::operator<(const mcomplex& rhs)
{
	if(m_r < rhs.m_r)
		return true;
	if(m_r == rhs.m_r && m_i < rhs.m_i)
		return true;
	return false;
}

bool mcomplex::operator<=(const mcomplex& rhs)
{
	return !operator>(rhs);
}

bool mcomplex::operator==(const mcomplex& rhs)
{
	if(m_r == rhs.m_r && m_i == rhs.m_i)
		return true;
	return false;
}

bool mcomplex::operator!=(const mcomplex& rhs)
{
	return !operator==(rhs);
}

ostream& operator<<(ostream& os, const mcomplex& rhs)
{
	if(rhs.m_r == 0 && rhs.m_i == 0)
		os<<0;
	else if(rhs.m_r == 0)
		os<<rhs.m_i<<'i';
	else if(rhs.m_i == 0)
		os<<rhs.m_r;
	else
	{
		if (rhs.m_i > 0)
			os<<rhs.m_r<<'+'<<rhs.m_i<<'i';
		else
			os<<rhs.m_r<<rhs.m_i<<'i';
	}
	return os;
}