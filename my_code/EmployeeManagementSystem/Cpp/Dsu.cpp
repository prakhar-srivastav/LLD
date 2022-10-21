
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include "../Header/Dsu.h"



using namespace std;

int Dsu::parent(int x)
{
	if(par[x]==x)
		return x;
	return par[x] = parent(par[x]);
}

bool Dsu::join(int x,int y)
{
	x = parent(x);
	y = parent(y);
	if(x==y) return false;

	if(rank0[x]>rank0[y])
	{
		par[y] = x;
	}
	else if(rank0[x]<rank0[y])
	{
		par[x] = y;
	}
	else
	{
		par[x]=y;
		rank0[y]++;
	}

	return true;
}

Dsu::Dsu()
{
	_n=0;
	rank0 = vector<int>{};
	par= vector<int>{};
}
void Dsu::addNode(string str)
{
	int id = _n;
	_n++;
	rank0.push_back(1);
	par.push_back(id);
	index[str]=id;
}
bool Dsu::addRelation(string a,string b)
{
	int i = index[a];
	int j = index[a];
	return join(i,j);
}