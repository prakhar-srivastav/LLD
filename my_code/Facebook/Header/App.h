#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include "Post.h"
#include "User.h"
using namespace std;

class App
{
private:
	map<string,Post> posts;
	map<string,User> users;
public:
App();
vector<string> createPost();
vector<string> createUser();
vector<string> addCommentToPost();
vector<string> replyComment();
vector<string> editComment();
vector<string> deleteComment();	
vector<string> showPost();


};


