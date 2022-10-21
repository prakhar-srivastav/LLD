
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "Header/App.h"



signed main()
{
	freopen("input.txt", "r", stdin);
	App app =  App();
	vector<string> message;

	while(true)
	{
		 cout <<"1 createUser()" << endl;
		 cout <<"2 createTask()" << endl;
		 cout <<"3 changeTaskStatus()" << endl;
		 cout <<"4 createSprint()" << endl;
		 cout <<"5 removeTask()" << endl;
		 cout <<"6 delayedTask()" << endl;
		 cout <<"7 sprintDetails()" << endl;
		 cout <<"8 taskAssigned()" << endl;
		 cout <<"9 Exit" << endl;

		int choice;
		cin >> choice;

		switch(choice)
		{
		 case 1:{message = app.createUser(); break;}
		 case 2:{message = app.createTask(); break;}
		 case 3:{message = app.changeTaskStatus(); break;}
		 case 4:{message = app.createSprint(); break;}
		 case 5:{message = app.removeTask(); break;}
		 case 6:{message = app.delayedTask(); break;}
		 case 7:{message = app.sprintDetails(); break;}
		 case 8:{message = app.taskAssigned(); break;}
		 case 9:{ cout << "Exiting" << endl; return 0;}
		 default:{cout << "Bad Choice" << endl;}
		}

		for(auto Line : message)
			cout << Line << endl;
	}
	return 0;
}