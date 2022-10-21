#pragma once
#include <iostream>
#include <string>
#include<stack>
using namespace std;



class App
{
private:
	vector<string> buffer;
	vector<string> content;
	stack<vector<string>> undoStack;
	stack<vector<string>> redoStack;
	bool badInput(int n,int m);
public:
	App();
	vector<string> display();
	vector<string> display(int n,int m);
	vector<string> insert(string text,int line);
	vector<string> delete0(int l);
	vector<string> delete0(int l,int r);
	vector<string> copy(int l,int r);
	vector<string> paste(int l);
	vector<string> undo();
	vector<string> redo();

};