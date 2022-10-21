#include <iostream>
#include <string>
#include<stack>
#include<vector>
#include "Header/App.h"
using namespace std;






signed main()
{

	App app = App();
	vector<string> message;
	while(true)
	{

		cout << "Enter Choice" << endl;

		cout << "0 display()" << endl;
		cout << "1 display(int n,int m)" << endl;
		cout << "2 insert(string text,int line)" << endl;
		cout << "3 delete0(int l)" << endl;
		cout << "4 delete0(int l,int r)" << endl;
		cout << "5 copy(int l,int r)" << endl;
		cout << "6 paste(int l)" << endl;
		cout << "7 undo()" << endl;
		cout << "8 redo()" << endl;



		int c;
		cin >> c;
		switch(c)
		{


			case 0:{message = app.display(); break;}

			case 1:{
				int n,m;
				cin >> n >> m ;
				message = app.display( n, m); break;}

			case 2:{

				string text;
				int line;
				cin >> text >> line;
				message = app.insert( text, line); break;
			}
			case 3:{

				int l;
				cin >> l ;
				message = app.delete0( l); break;}

			case 4:{

				int l,r;
				cin >> l >> r;
				message = app.delete0( l, r); break;}
			case 5:{

					int l,r;
					cin >> l >> r;
				message = app.copy( l, r); break;
			}
			case 6:{
				int l;
				cin >> l ;
				message = app.paste( l); break;}
			case 7:{message = app.undo(); break;}
			case 8:{message = app.redo(); break;}
			default:{message = vector<string>{"Invalid Choice"}; }
		}


		for(auto line:message)
			cout << line << endl;
		message.clear();
	}

	return 0;
}