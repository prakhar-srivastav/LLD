#include<iostream>
#include<vector>
#include<map>
#include<string>
#include "Header/App.h"

using namespace std;


signed main()
{
	App app = App();
	vector<string> message;
	int choice;

	while(true)
	{
		cout <<"Enter Choice" << endl;
		cout << "1 createUser()" << endl;
		cout << "2 createGroup()" << endl;
		cout << "3 createExpense()" << endl;
		cout << "4 addUserToGroup()" << endl;
		cout << "5 printTotalSum()" << endl;
		cout << "6 p2pDetails()" << endl;
		cout << "7 Exit" << endl;
		cin >> choice;

		switch(choice)
		{
			case 1: {message = app.createUser();  break;}
			case 2: {message = app.createGroup();  break;}
			case 3: {message = app.createExpense();  break;}
			case 4: {message = app.addUserToGroup();  break;}
			case 5: {message = app.printTotalSum();  break;}
			case 6: {message = app.p2pDetails();  break;}
			case 7: {cout << "exiting" << endl; return 0;}
			default: {cout << "wrong choice" << endl;}
		}

		for(auto line:message)
			cout << line << endl;
		message.clear();
	}

	return 0;

}