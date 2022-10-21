#include<iostream>
#include<vector>
#include<map>
#include<string>
#include "Header/App.h"

using namespace std;


signed main()
{
	vector<string> message;
	int choice;
	App app = App();
	while(true)
	{
		cout << "1 addRider()" << endl;
		cout << "2 addDriver()" << endl;
		cout << "2 createRide()" << endl;
		cout << "3 updateRide()" << endl;
		cout << "4 withdrawRide()" << endl;
		cout << "5 closeRide()" << endl;
		cout << "6 Exiting" << endl;


		cout << "Enter Choice" << endl;

		cin >> choice;

		switch(choice)
		{

			case 1: {message = app.addRider(); break; }
			case 2: {message = app.addDriver(); break; }
			case 3: {message = app.createRide(); break; }
			case 4: {message = app.updateRide(); break; }
			case 5: {message = app.withdrawRide(); break; }
			case 6: {message = app.closeRide(); break; }
			case 7: {cout <<"Exiting" << endl; return 0;}
			default:{cout << "Bad Choice" << endl;}
		}

		for(auto line :message)
			cout << line << endl;
		message.clear();

	}
	return 0;
}