#include "Key.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
 

void fileTest()
{
	string str;
	ifstream txt("test.txt");
	getline(txt,str); 
	//cout<<str;
	Key *nkey= new Key;
	nkey->sleep(3000);
	nkey->setSleepTime(10);
	nkey->bearStr(str); 
}

	

int main(int argc,char *argv[])
{

	fileTest();
	return 0;
}
