#pragma once
#include<iostream>
#include<vector>
#include<map>
#include<string>

using namespace std;
class Jumper
{
private:
	bool Type;
	int head;
	int tail;
public:
	Jumper();
	Jumper(bool Type0,vector<bool> &availables);
	int getHead();
	int getTail();

};