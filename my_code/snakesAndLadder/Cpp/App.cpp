#include<iostream>
#include<vector>
#include<map>
#include<string>
#include "../Header/App.h"
using namespace std;

App::App()
{
	users = vector<User>{};
	board = Board();
	Winner = "";
	userId = map<string,bool>{};

}
void App::createBoard()
{
	int snakeCnt,ladderCnt;
	
	while (true)
	{
		cin >> snakeCnt >> ladderCnt;

		if (snakeCnt >= 5 || ladderCnt >= 5)
			cout << "The count value <= 4 is expected for a reasonable game. Try again" << endl;
		else break;
	}
	board.generate(snakeCnt,ladderCnt);
}
void App::createUser()
{
	int userCnt;
	cin >> userCnt;
	
	while(userCnt--)
	{
		string userName;
		cin >> userName;
		if(userId.find(userName)!=userId.end())
			cout << "UserName already exist. Enter a differnt one" << endl;
		else 
		{
			User newUser = User(userName);
			users.push_back(newUser);
			userId[userName]=true;
			cout <<"User created"<< endl;
			break;
		}
	}
}

void App::play()
{

	while(true)
	{
		for(auto user : users)
		{
			int steps = user.roll();
			int newPosition = board.newPosition(steps + user.getPos());
			if(newPosition == 100)
			{
				Winner = user.getName();
				break;
			}
			else 
			{
				user.setPos(newPosition);
			}
		}
		if(Winner !="")
			break;	
	}

	cout << Winner << " has won the game" << endl;

	for(auto user:users)
	{
		cout << user.getName() <<  ": " << user.getPos() << endl;
	}
	return ;
}
