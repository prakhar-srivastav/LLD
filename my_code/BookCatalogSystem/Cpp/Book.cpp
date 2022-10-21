#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "../Header/Book.h"

using namespace std;


Book::Book()
{
	name = "";
	publisher ="";
	publishYear ="";
	// author = NULL;
	// category = NULL;
	price =0;
	count =0;
}
Book::Book(string name0,string publisher0,string publishYear0,int price0,int cnt0)
{
	name = name0;
	publisher =publisher0;
	publishYear = publishYear0;
	price = price0;
	count = cnt0;
}
// void Book::assign(Author *author0,Category *category0)
// {
// 	author = author0;
// 	category = category0;
// }
bool Book::isPrefix(string name0)
{
	if(name0.size() > name.size())
		return false;

	if(name.substr(0,(int)(name.size())) == name)
		return true;
	return false;
}
string Book::getName()
{
	return name;
}
int Book::getCount()
{
	return count;
}