#include<iostream>  
#include "mysqler.h"  
  
int main()  
{  
    mysqler db;  
    db._init("127.0.0.1", "test", "test", "testdb");  
    db._exec("select * from Cars");  
    return 0;  
} 
