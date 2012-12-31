#ifndef _DBCONNECTIONPOOL_H_
#define _DBCONNECTIONPOOL_H_

class DBConnectionPool
{
public:
	static DBConnectionPool& GetInstance();

	void DoSomething();

private:
	DBConnectionPool();
	DBConnectionPool(const DBConnectionPool& rhs); //Not implement

	DBConnectionPool& operator=(const DBConnectionPool& rhs); //Not implement

};

#endif
