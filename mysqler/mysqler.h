#ifndef __MYBD_H__  
#define __MYBD_H__  

#include <iostream>  
#include <my_global.h>
#include <mysql.h>
 
class mysqler  
{  
public:  
    mysqler();
    //mysqler(const char* host, const char* user, const char* pwd); 
    ~mysqler();
public:
	bool createdb(const char* db_name);
	bool createtb(const char* tb_name);
	bool insert(const char* sql);
	bool drop(const char* sql);
	bool update(const char* sql);
	bool query(const char* sql);
public:
	//const char * charset();
	//bool charset(const char* sql);
//private:
public:
    bool _init(const char* host, const char* user, const char* pwd, const char* db_name);  
    bool _exec(const char* sql);
private:  
    MYSQL     * _con;  
    MYSQL_RES * _result;  
};

#endif  
