#pragma once
#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<string>
#include "Jumper.h"

using namespace std;
class Board
{
private:
	vector<Jumper> snakes,ladders;
	vector<bool> availables;
	vector<int> array;
	vector<bool> bfs(vector<vector<int>>& graph,int source);
	bool check();
public:
	Board();
	void generate(int snake,int ladder);
	int newPosition(int position);
};