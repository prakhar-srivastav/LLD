#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include "Comment.h"
using namespace std;


class Post
{
private:
string id;
string userId;
string description;
map<int,vector<Comment>> comments;

public:
Post();
Post(string id0,string userId0,string description0);
vector<string> addComment(string userId, string message,int comment);
vector<string> editComment(string userId,string message,int comment,int nestedComment);
vector<string> deleteComment(string userId,int comment,int nestedComment);
vector<string> show();
};