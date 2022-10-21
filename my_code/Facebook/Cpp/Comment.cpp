
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include "../Header/Comment.h"
using namespace std;


Comment::Comment(string message0,string userId0)
{
	message = message0;
	userId = userId0;
}
string Comment::getMessage()
{
	return message;
}
vector<string> Comment::getUserId()
{
	return vector<string>{userId};
}
vector<string> Comment::setMessage(string newMessage)
{

	message = newMessage;
	return vector<string>{"Message Edited"};
}