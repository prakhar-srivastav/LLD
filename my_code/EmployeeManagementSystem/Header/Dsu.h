#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;




class Dsu
{
private:
	int _n;
	vector<int> rank0;
	vector<int> par;
	map<string, int> index;
	bool join(int x, int y);
	int parent(int x);
public:
	Dsu();
	void addNode(string str);
	bool addRelation(string a, string b);
};