
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<utility>
#include "../Header/Post.h"
#include "../Header/Comment.h"
using namespace std;


Post::Post(string id0,string userId0,string description0)
{
	id = id0;
	userId=userId0;
	description=description0;
	comments = map<int, vector<Comment>> {};
}
vector<string> Post::addComment(string userId, string message,int comment)
{
	if(comment==-1)
	{
		Comment c =  Comment(message,userId);
		comment = (int)(comments.size());
		comments[comment].push_back(c); 
		return vector<string>{"Comment is created"};
	}
	else
	{
		if(comment>=(int)(comments.size()))
		{
			return vector<string>{"Invalid comment entry"};
		}
		else 
		{
			Comment c = Comment(message, userId);
			comments[comment].push_back(c); 
			return vector<string>{"Comment is created"};
		}
	}
}
vector<string> Post::editComment(string userId,string message,int comment,int nestedComment)
{
	if(comments.find(comment)==comments.end() ||
		nestedComment <0 ||
		(int)(comments[comment].size()) >= nestedComment)
	{
		return vector<string>{"No such comments"};
	}
	return comments[comment][nestedComment].setMessage(message);
}
vector<string> Post::deleteComment(string userId,int comment,int nestedComment)
{
	if(comments.find(comment)==comments.end() ||
		nestedComment <0 ||
		(int)(comments[comment].size()) >= nestedComment)
	{
		return vector<string>{"No such comments"};
	}

	if(nestedComment==0)
	{
		// free comment
		comments.erase(comment);
	}
	else 
	{
		while((int)(comments[comment].size())>nestedComment)
			comments[comment].pop_back();
	}
	return vector<string>{"Deleted Comment"};

		
}
vector<string> Post::show()
{
	vector<string> result ;
	for(auto &p: comments)
	{

		int parent = p.first;
		vector < Comment> allComments = p.second;
		result.push_back(to_string(parent));
		for(auto &entry:allComments)
			result.push_back(entry.getMessage());
	}
	return result;
}