#include "mysqler.h"  

mysqler::mysqler():_con(NULL)
{
	_con = mysql_init(NULL);
	if (_con == NULL) 
	{
		fprintf(stderr, "%s\n", mysql_error(_con));
		exit(1);
	}  	
}  

mysqler::~mysqler()  
{  
	if(_con != NULL)
	{  
		mysql_close(_con);
		_con = NULL;
	}  
}

bool mysqler::createdb(const char* db_name)
{

}
bool mysqler::createtb(const char* tb_name)
{

}
bool mysqler::insert(const char* sql)
{

}
bool mysqler::drop(const char* sql)
{

}
bool mysqler::update(const char* sql)
{

}
bool mysqler::query(const char* sql)
{

}

bool mysqler::_init(const char* host, const char* user, const char* pwd, const char* db_name)
{  
	if(mysql_real_connect(_con, host, user, pwd, db_name, 0, NULL, 0) == NULL)
	{  
		finish_with_error();
		return false;
	}  
	return true;  
}  

bool mysqler::_exec(const char* sql)
{  
	if(mysql_query(_con, sql))
	{  
		finish_with_error();
		return false;
	}
	else
	{  
		_result = mysql_store_result(_con);
		if (_result == NULL) 
		{
			finish_with_error();
		}
		int num_fields = mysql_num_fields(_result);
		MYSQL_ROW row;
		while ((row = mysql_fetch_row(_result))) 
		{ 
			for(int i = 0; i < num_fields; i++) 
			{ 
				printf("%s ", row[i] ? row[i] : "NULL"); 
			} 
			printf("\n"); 
		}
		mysql_free_result(_result);
	}  
	return true;  
}

void mysqler::finish_with_error()
{
	fprintf(stderr, "[%d]%s\n", mysql_errno(_con), mysql_error(_con));
	if(_con){
		mysql_close(_con);
		_con = NULL;
	}
}
