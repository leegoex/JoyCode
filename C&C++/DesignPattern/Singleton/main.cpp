#include <iostream>
#include "DBConnectionPool.hpp"
using namespace std;

int main(int argc, char *argv[])
{
	DBConnectionPool::GetInstance().DoSomething();

	return 0;
}
