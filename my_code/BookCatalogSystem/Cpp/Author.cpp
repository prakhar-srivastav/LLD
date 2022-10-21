
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "../Header/Author.h"

using namespace std;


Author::Author()
{
 books = set<pair<pair<int,string>,Book*>>{};
 name = "";

}
Author::Author(string authorName)
{
	books = set<pair<pair<int,string>,Book*>>;
	name = authorName;
}
vector<string> Author::getSold(int limit)
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

void Author::addBook(Book *book)
{
	string name = (*book).getName();
	int cnt = (*book).getCount();
	books.insert({{-cnt,name},book});
}
