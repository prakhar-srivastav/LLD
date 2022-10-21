
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<utility>
#include "Header/Post.h"
#include "Header/App.h"
#include "Header/Comment.h"
#include "Header/User.h"
using namespace std;


signed main()
{

    App app = App();
    vector<string> message;
	while(true)
	{
		cout << "Enter" << endl;;
		cout <<  "0 createPost()" << endl;;
		cout <<  "1 createUser()" << endl;;
		cout <<  "2 addCommentToPost()" << endl;;
		cout <<  "3 replyComment()" << endl;;
		cout <<  "4 editComment()" << endl;;
		cout <<  "5 deleteComment()" << endl;;	
		cout <<  "6 showPost()" << endl;;
		cout <<  "7 Exit" << endl;
		int c;
		cin >> c;
		
		switch (c)
		{
		case 0:
		{
			message = app.createPost();
			break;
		}
		case 1:
		{
			message = app.createUser();
			break;
		}
		case 2:
		{
			message = app.addCommentToPost();
			break;
		}
		case 3:
		{
			message = app.replyComment();
			break;
		}
		case 4:
		{
			message = app.editComment();
			break;
		}
		case 5:
		{
			message = app.deleteComment();
			break;
		}
		case 6:
		{
			message = app.showPost();
			break;
		}
		case 7:
		{
			cout << "Closing" << endl;
			return 0;
		}
		default:
		{
			cout << "Wrong Choice" << endl;
			break;
		}
		}
		for(auto line : message)
			cout << line << endl;
			message.clear(); 
	}


	return 0;
}