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
public:  
    mysqler();
    ~mysqler();
public:
	bool createdb(const char* db_name);
	bool createtb(const char* tb_name);
	bool insert(const char* sql);
	bool drop(const char* sql);
	bool update(const char* sql);
	bool query(const char* sql);
//private:
public:
    bool _init(const char* host, const char* user, const char* pwd, const char* db_name);  
    bool _exec(const char* sql);
private:
	void finish_with_error();
private:  
    MYSQL     * _con;  
    MYSQL_RES * _result;  
};

#endif  
