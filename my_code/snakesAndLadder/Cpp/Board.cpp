#include<iostream>
#include<vector>
#include<map>
#include<utility>
#include<queue>
#include<string>
#include "../Header/Board.h"

using namespace std;

vector<bool> Board::bfs(vector<vector<int>>&g,int s)
{
	vector<bool> vis(101);
	queue<int> q;
	q.push(s);
	while(!q.empty())
	{
		auto u = q.front();
		q.pop();
		if(vis[u]) continue;
		vis[u]=true;
		for(auto v:g[u])
		{
			q.push(v);
		}
	}
	return vis;
}

bool Board::check()
{
	vector<vector<int>> g(101),tg(101);

	for(int i=0;i<=100;i++)
	{
		for(int j=1;j<=6;j++)
		{
			if(j+i<=100)
			{
				g[i].push_back(array[i+j]);
				tg[array[i+j]].push_back(i);
			}
		}
	}

	vector<bool> vis0 = bfs(g,0);
	

	return vis0[100];

}
Board::Board()
{
	array=vector<int>(101,-1);
	for(int i=0;i<=100;i++)
		array[i]=i;
	availables=vector<bool>(101,false);
	snakes=vector<Jumper>{};
	ladders=vector<Jumper>{};
}

void Board::generate(int snake,int ladder)
{


	while(true)
	{
		snakes.clear();
		ladders.clear();
		availables=vector<bool>(101,false);
		array=vector<int>(101,-1);
		for(int i=0;i<=100;i++)
			array[i]=i;
		for(int i=0;i<snake;i++)
		{
			Jumper s = Jumper(0,availables);
			snakes.push_back(s);
			array[s.getHead()]=s.getTail();
			availables[s.getHead()]=true;
			availables[s.getTail()]=true;
		}
		
		for(int i=0;i<ladder;i++)
		{
			Jumper l = Jumper(1,availables);
			ladders.push_back(l);
			array[l.getHead()]=l.getTail();
			availables[l.getHead()]=true;
			availables[l.getTail()]=true;
		}
		
		bool success = check();

		if(success) break;

	}

	vector<string> message;
	message.push_back("Board Created");
	for(auto snake : snakes)
	{
		message.push_back("Snake: Head =" + to_string(snake.getHead()) + ", Tail = " + to_string(snake.getTail()));
	}
	for(auto ladder : ladders)
	{
		message.push_back("Ladder: Head =" + to_string(ladder.getHead()) +", Tail = " + to_string(ladder.getTail()));
	}
	for (auto line : message)
	{
		cout << line << endl;
	}
}
int Board::newPosition(int position)
{
	if(position>100) 
		return position;
	return array[position];
}