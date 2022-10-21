#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;



class Comment
{
private:
string message,userId;

public:
Comment(string message0,string userId0);
string getMessage();
vector<string> getUserId();
vector<string> setMessage(string newMessage);
};