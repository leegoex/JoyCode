#include <iostream>
#include "rdirect.h"

rdirect::rdirect(const char* fileName):m_ofs(0),m_oldBuf(0)
{
	m_ofs = new ofstream(fileName, ios::app);
	m_oldBuf = cout.rdbuf(m_ofs->rdbuf());	
}

rdirect::~rdirect()
{
	cout.rdbuf(m_oldBuf);
	delete m_ofs;
}