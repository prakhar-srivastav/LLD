
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "../Header/Category.h"

using namespace std;


Category::Category()
{
 books = set<pair<pair<int,string>,Book*>>{};
 name = "";

}
Category::Category(string categoryName)
{
	books = set<pair<pair<int,string>,Book*>>;
	name = categroyName;
}
vector<string> Category::getSold(int limit)
{
	vector<string> message;
	if(limit == -1) limit = (int)(books.size())+10;
	for(auto itr : books)
	{
		auto &book = (*itr.second);
		message.push_back(book.getName());
		limit--;
		if(limit == 0 )
			break;
	}
	return message;
}

void Category::addBook(Book *book)
{
	string name = (*book).getName();
	int cnt = (*book).getCount();
	books.insert({{-cnt,name},book});
}
