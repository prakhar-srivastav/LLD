
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "Header/App.h"

using namespace std;


signed main()
{

	vector<string> message;
	int choice;
	App app = App();

	while(true)
	{
		cout << "1 addBook()" << endl;
		cout << "2 searchByName()" << endl;
		cout << "3 searchByAuthor()" << endl;
		cout << "4 TopSoldByAuthor()" << endl;
		cout << "5 TopSoldByCategory()" << endl;
		cout << "6 Exit" << endl;
		cout << "Enter Choice" << endl;

		cin >> choice;

		switch(choice)
		{
			case 1 : { message = app.addBook(); break; }
			case 2 : { message = app.searchByName(); break; }
			case 3 : { message = app.searchByAuthor(); break; }
			case 4 : { message = app.TopSoldByAuthor(); break; }
			case 5 : { message = app.TopSoldByCategory(); break; }
			case 6 : {cout <<"Exiting" << endl; return 0;}
			default:{cout <<"Bad Choice" << endl; break;}
		}


		for(auto line : message)
			cout << line << endl;

		message.clear();

	}


	return 0;
}