#include <iostream>
#include <string>
#include<vector>
#include<stack>
#include "../Header/App.h"
using namespace std;


bool App::badInput(int l,int r)
{

	if(l<0 or r>=buffer.size() or l>r)
		return false;
	return true;
}


App::App()
{
	buffer = vector<string>{};
	content = vector<string>{};
	undoStack = stack<vector<string>>{};
	redoStack = stack<vector<string>>{};
}
vector<string> App::display(int n,int m)
{
	n--;
	m--;
	
	if(badInput(n,m))
		return vector<string>{"The range is invalid"};

	vector<string> message;
	for(int i=n;i<=m;i++)
		message.push_back(content[i]);
	return message;	
}

vector<string> App::display()
{
	return display(1,(int)(content.size()));
}

vector<string> App::insert(string text,int line)
{
	line-- ;
	int size = (int)(content.size());
	content.resize(size+1);
	if(badInput(line,line))
		return vector<string>{"The line is invalid"};
	
	undoStack.push(content);

	for(int l = size ; l > line ; l++)
	{
		content[l] = content[l-1];
	}
	content[line] = text; 
	return vector<string>{"Insertion Successful"};

}
vector<string> App::delete0(int l)
{

	return delete0(l,l);
}
vector<string> App::delete0(int l,int r)
{
	
	l--,r--;
	if(badInput(l,r))
		return vector<string>{"The range is Invalid"};
	
	undoStack.push(content);


	int size = (int)(content.size());
	for(int itr = r+1;itr<size;itr++)
	{
		content[itr-(r-l+1)]=content[itr];
	}
	content.resize(size - (r-l+1));
	return vector<string>{"Deletion Successful"};
}
vector<string> App::copy(int l,int r)
{
	l--,r--;
	if(badInput(l,r))
		return vector<string>{"The range is Invalid"};
	


	int size = (int)(content.size());
	buffer.clear();
	for(int i=l;i<=r;i++)
		buffer.push_back(content[i]);
	return vector<string>{"Copy Successful"};
}
vector<string> App::paste(int l)
{

	if(badInput(l,l))
		return vector<string>{"The line is invalid"};
	
	undoStack.push(content);

	while(!buffer.empty())
	{
		insert(buffer.back(),l);
		buffer.pop_back();
	}

	return vector<string>{"Pasted"};

}
vector<string> App::undo()
{
  if(undoStack.empty())
  	return vector<string>{"Nothing to Undo"};

  content = undoStack.top();
  undoStack.pop();

  redoStack.push(content);
  return vector<string>{"Undo operation done!"};
}
vector<string> App::redo()
{
if(redoStack.empty())
  	return vector<string>{"Nothing to Redo"};

  content = redoStack.top();
  redoStack.pop();

  undoStack.push(content);
  return vector<string>{"Redo operation done!"};
}