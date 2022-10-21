
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include "../Header/App.h"

using namespace std;




App::App()
{
	posts = map<string, Post>{};
	users = map<string, User>{};
		
}
vector<string> App::createPost()
{
	string id,userId,description;
	cin >> id >> userId >> description;

	if(posts.find(id)!=posts.end())
	{
		return vector<string> {"Post ID already exists"};
	}
	else if(users.find(userId)==users.end())
	{
		return vector<string>{"User ID doest not exists"};
	}
	Post p = Post(id,userId,description);
	posts[id] = p;
	return vector<string>{"Post created"};

}
vector<string> App::createUser()
{

	
	string userId , name;
	cin >> userId >> name;

	if(users.find(userId)!=users.end())
	{
		return vector<string>{"User ID already exists"};
	}
	User p = User(userId,name);
	users[userId] = p;
	return vector<string>{"User created"};
}
vector<string> App::addCommentToPost()
{
	string postId,userId,message;
	cin >> postId >> userId>> message;
	if(posts.find(postId)==posts.end())
	{
		return vector<string> {"Post ID doesnot exists"};
	}
	else if(users.find(userId)==users.end())
	{
		return vector<string>{"User ID doesnot exists"};
	}
	return posts[postId].addComment(userId,message,-1);
}
vector<string> App::replyComment()
{
	string postId,userId,message;
	int comment;
	cin >> postId >> userId >> comment  >> message; 
	if(posts.find(postId)==posts.end())
	{
		return vector<string> {"Post ID doesnot exists"};
	}
	else if(users.find(userId)==users.end())
	{
		return vector<string>{"User ID doesnot exists"};
	}
	
	return posts[postId].addComment(userId,message,comment);
}
vector<string> App::editComment()
{
	string postId,userId,message;
	int comment,nestedComment;
	cin >> postId >> userId >> comment  >> nestedComment >> message; 
	if(posts.find(postId)==posts.end())
	{
		return vector<string> {"Post ID doesnot exists"};
	}
	else if(users.find(userId)==users.end())
	{
		return vector<string>{"User ID doesnot exists"};
	}
	return posts[postId].editComment(userId,message,comment,nestedComment);
}
vector<string> App::deleteComment()
{
	string postId, userId;
	int comment,nestedComment;
	cin >> postId >> userId >> comment >> nestedComment; 
	if(posts.find(postId)==posts.end())
	{
		return vector<string> {"Post ID doesnot exists"};
	}
	else if(users.find(userId)==users.end())
	{
		return vector<string>{"User ID doesnot exists"};
	}
	return posts[postId].deleteComment(userId,comment,nestedComment);
}	

vector<string> App::showPost()
{
	string postId;
	cin >> postId; 
	if(posts.find(postId)==posts.end())
	{
		return vector<string> {"Post ID doesnot exists"};
	}
	
	return posts[postId].show();
}	