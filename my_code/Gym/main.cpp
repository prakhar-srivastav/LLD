#include<iostream>
#include<vector>
#include<string>
#include<map>
#include "Header/Admin.h"

using namespace std;

bool isNumber(string &str)
{
	for(auto a:str)
	{
		if(a>='0' && a<='9')
			continue;
		return false;
	}
	return true;
}

int toInt(string c)
{

	int res=0;
	for(auto a:c)
	{
		res = res*10+a-'0';
	}
	return res;
}
signed main()
{
	Admin app = Admin();

	string choice;
	vector<string> message;
	while(true)
	{
		cout <<"Choice" << endl;

		cin >> choice;

		if(!isNumber(choice))
		{
			cout <<"Bad Choice" << endl;
			continue;
		}

		switch(toInt(choice))
		{
			case 1:{


				string userName,email,Phone,password;
				cin >> userName >> email >> Phone >> password ;

				message = app.userRegister( userName,  email,  Phone,  password); break ;}
			case 2:{

				string centerName;
				int slotTiming;
				string workOut;
				int capacity;
				cin >> centerName >> slotTiming >> workOut >> capacity;
				message = app.addSlot( centerName, slotTiming,  workOut,capacity); break ;}
			case 3:{
				int day;
				cin >> day;
				message = app.viewWorkout( day); break ;}
			case 4:{

				string userID,centerID;
				int slotTiming,day;
				cin >> userID >> centerID >> slotTiming >> day;
				message = app.bookSlot( userID,  centerID,  slotTiming, day); break ;}
			case 5:{
				string userID;
				int day;
				cin >> userID >> day;
				message = app.userPlan( userID, day); break ;}
			case 6:{
					string centerID;
					int slotTiming,capacity;
					cin >> centerID >> slotTiming >> capacity;
					message = app.uodateSlot(centerID,  slotTiming,capacity); break ;}
			case 7:{
				string centerName;
				cin >> centerName;
				message = app.addCenter(centerName); break ;}
			case 8: {
				cout << "exiting" << endl;
				return 0;
			}
			default: {cout << "Bad choice" << endl; break; }
		}
		

			   for (auto l : message)
				   cout << l << endl;
		message.clear();
	}


	return 0 ;


}
