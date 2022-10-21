#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <string>
#include "Header/App.h"

using namespace std;

signed main()
{

	App app = App();
	int choice;
	vector<string> message;
	while(true)
	{
		cout <<  "1 createRoom()" << endl;
		cout <<  "2 bookMeeting()" << endl;
		cout <<  "3 getMeetingHistory()" << endl;
		cout <<  "4 returnMeetingScheduled()" << endl;
		cout << "5 Exit" << endl;
		cout << "Enter Choice" << endl;
		cin >> choice;
		switch(choice)
		{
			case 1:{ message = app.createRoom(); break; }
			case 2:{ message = app.bookMeeting(); break; }
			case 3:{ message = app.getMeetingHistory(); break; }
			case 4:{ message = app.returnMeetingScheduled(); break; }
			case 5:{  cout << "Exiting" << endl; return 0; }
			default: {cout << "Bad Choice" << endl; }
		}

		for(auto line : message)
			cout << line << endl;
		message.clear();
	}



	return 0;
}