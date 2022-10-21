#include<iostream>
#include<vector>
#include<string>
#include<map>
#include "Header/App.h"

using namespace std;


signed main()
{
	
	App app = App();
	int choice;
	vector<string> message;
	while(true)
	{
		cout << " 1 listSubordinate()" << endl;
		cout << " 2 findPrefix()" << endl;
		cout << " 3 addEmployee()" << endl;
		cout << " 4 addRelation()" << endl;
		cout << " 5 getEmployeeDetails()" << endl;
		cout << " 6 Exit" << endl;
		cout << "Enter Choice" << endl;
		cin >> choice;
		switch(choice)
		{
			case 1: {message =app.listSubordinate(); break; }
			case 2: {message =app.findPrefix(); break; }
			case 3: {message =app.addEmployee(); break; }
			case 4: {message =app.addRelation(); break; }
			case 5: {message =app.getEmployeeDetails(); break; }
			case 6:{cout <<"Exiting" << endl; return 0;}
			default:{cout << "Wrong Choice" << endl;}
		}

		for(auto line:message)
			cout << line << endl;
		message.clear();
	}
	return 0;
}