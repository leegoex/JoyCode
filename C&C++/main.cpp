#include <iostream>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
using namespace boost::posix_time;
int main(int argc, char *argv[]) 
{
	ptime now = second_clock::universal_time();
	std::cout << "Current Time is: "<< to_iso_extended_string(now)<< std::endl;
	ptime now_2 = microsec_clock::universal_time();
	std::cout << "Current Time is: "<< to_iso_extended_string(now_2)<< std::endl;

	return 0;
}
