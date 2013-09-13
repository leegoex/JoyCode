#include <fstream>
#include <streambuf>
using namespace std;

class rdirect
{
public:
	rdirect(const char* fileName);
	~rdirect();
	
private:
	ofstream *m_ofs;
	streambuf *m_oldBuf;		
};