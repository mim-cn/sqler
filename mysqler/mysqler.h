#ifndef __MYBD_H__  
#define __MYBD_H__  

#ifdef WIN32
  #include <windows.h>
  #include <winsock.h>
#endif
#ifndef WIN32
  #include <unistd.h>
#endif

#include <stdio.h>
#include <my_global.h>
#include <mysql.h>
 
class mysqler  
{

typedef unsigned int uint;
typedef unsigned int ulong;

public:
	mysqler();
	mysqler(const char* host, const char* user,
            const char* password, const char* database = NULL,
            uint  port = 0, const char* unixSocket = NULL, ulong clientFlags = 0);
	~mysqler();
public:
	bool connected() const;
	void connect(const char* charset = "utf8");
	void usedb(const char* db);
	int  execsql(const char* statement);
	inline MYSQL_RES* result() const { return _result;}
	void show_result();
	void free_result();
public:
	inline bool autocommit() const { return _autocommit;}
	void autocommit(bool chose);
	void startTransaction();
	void commit();
	void rollback();
public:
	void initLibrary(bool embedded);
	void finaLibrary();
	void initThread();
	void finaThread();
private:
	void finish_with_error(const char *desc);
private:  
	MYSQL     * _con;
	MYSQL_RES * _result;
	const char* _host;
	const char* _user;
	const char* _password;
	const char* _database;
	const char* _initcmd;
	const char* _usocket;
	uint        _port;
	ulong       _cliflag;
	bool        _isConnected;
	bool        _autocommit;
	static bool _embedded;
};

#endif  
