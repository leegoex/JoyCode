#include "DBConnectionPool.hpp"
#include <iostream>
using namespace std;

DBConnectionPool& DBConnectionPool::GetInstance()
{
	static DBConnectionPool dbPool;
	return dbPool;
}

DBConnectionPool::DBConnectionPool()
{
}

void DBConnectionPool::DoSomething()
{
	cout<<"Do something\n";
}
