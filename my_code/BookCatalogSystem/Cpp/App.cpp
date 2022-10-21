
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "../Header/App.h"


using namespace std;

App()
{
	books = map<stirng,Book>{};
	categories = map<string,Category>{};
	authors = map<string,Author>{};
}
vector<string> App::addBook()
{
	string bookName,authorName,categoryName,publisher,publishYear;
	int price;
	int count;
	cin >> bookName,authorName,categoryName,publisher,publishYear;
	cin >> price >> count;

	if(books.find(bookName)!=books.end())
		return vector<string>{"Book already exists"};

	if(price<=0)
		return vector<string>{"Price must be >0"};
	if(count<=0)
		return vector<string>{"Count must be >0"};

	books[bookName] = Book(bookName,publisher,publishYear,price,count);
	if(authors.find(authorName)== authors.end())
		authors[authorName] = Author(authorName);

	if(categories.find(categoryName)== categories.end())
		categories[categoryName] = Category(categoryName);

	// books[bookName].assign(&authors[authorName],&categories[categoryName]);


	authors[authorName].addBook(&books[bookName]);
	categories[categoryName].addBook(&books[bookName]);
	return vector<string>{"Book created"};

}
vector<string> App::searchByName()
{
	string pref;
	cin >> pref;
	vector<string> message;
	for(auto &bookPair: books)
	{
		auto &book = bookPair.second;
		auto &name = bookPair.first;
		if(book.isPrefix(pref))
			message.push_back(book.getName());
	}
	return message;
}
vector<string> App::searchByAuthor()
{
	string name;
	cin >> name;
	if(authors.find(name)==authors.end())
		return vector<string>{"Author does not exist"};

	return author[name].getSold(-1);
}
vector<string> App::TopSoldByAuthor()
{
	string name;
	cin >> name;
	int limit;
	cin >> limit;
	if(authors.find(name)==authors.end())
		return vector<string>{"Author does not exist"};

	return author[name].getSold(limit);
}
vector<string> App::TopSoldByCategory()
{
	string name;
	cin >> name;
	int limit;
	cin >> limit;
	if(caregories.find(name)==caregories.end())
		return vector<string>{"category does not exist"};

	return caregories[name].getSold(limit);

	
}