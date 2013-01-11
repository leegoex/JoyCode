#include <stdio.h>
#include "DBConnection.h"

int main(int argc, char *argv[])
{
	CDBConnection db;
	if (db.Open("/cygdrive/e/Dropbox/Source/Linux/CreateW/Sqlite3Demo/DatabaseDemo.sqlite") == 0) 
	{
		char sql[1000] = {0};
		snprintf(sql, sizeof(sql), "%s", "delete from station");
		db.ExecuteSql(sql);

		snprintf(sql, sizeof(sql)-1, "%s", "insert into station(code,name,pinyin)values(\"1\", \"广州\", \"guangzhou\")");
		db.ExecuteSql(sql);
		snprintf(sql, sizeof(sql)-1, "%s", "insert into station(code,name,pinyin)values(\"2\", \"深圳\", \"shenzhen\")");
		db.ExecuteSql(sql);
		snprintf(sql, sizeof(sql)-1, "%s", "insert into station(code,name,pinyin)values(\"3\", \"东莞\", \"dongguan\")");
		db.ExecuteSql(sql);
		
		snprintf(sql, sizeof(sql)-1, "%s", "select code,name,pinyin from station");

		CDBRecordSet rs(db.QuerySql(sql));
		while (rs.Next()) {
			char szCode[100] = {0};
			char szName[100] = {0};
			char szPinyin[100] = {0};
			rs.GetValue(0, szCode, 100);
			rs.GetValue(1, szName, 100);
			rs.GetValue(2, szPinyin, 100);

			printf("code:%s name:%s pinyin:%s\n", szCode, szName, szPinyin);
		}

		snprintf(sql, sizeof(sql)-1, "%s", "select pinyin,code from station");
		CDBRecordSet rs1(db.QuerySql(sql));
		while (rs1.Next()) {
			char szCode[100] = {0};
			char szPinyin[100] = {0};
			rs1.GetValue(1, szCode, 100);
			rs1.GetValue(0, szPinyin, 100);

			printf("pinyin:%s code:%s\n", szPinyin, szCode);
		}

		db.Close();
	} else {
		printf("Can't open the database file\n");
	}
	return 0;
}
