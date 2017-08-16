#include<iostream>  
#include "mysqler.h"  

int main()  
{  
	mysqler db;  
	if(db._init("127.0.0.1", "test", "test", "testdb"))
	{
		db._exec("show create table student");
		//db._exec("CREATE TABLE student(Id INT, Name TEXT)");      
		//db._exec("show tables");
	}
	return 0;  
} 
