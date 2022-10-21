#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<string>
#include "../Header/Jumper.h"

Jumper::Jumper()
{
	Type =false;
	head =0 ;
	tail =0 ;  
}

Jumper::Jumper(bool Type0,vector<bool> &availables)
{
	Type = Type0;
	int A,B;
	vector<int> vals;

	for(int i=0;i<(int)(availables.size());i++)
		if(!availables[i])
			vals.push_back(i);
	// cout << availables.size() << endl;
	while(true)
	{
		A = (int(rand()))%(int(vals.size()));
		B = (int(rand()))%(int(vals.size()));
		if(A!=B)
			break; 
	}
	
	A = vals[A];
	B = vals[B];
	if(A>B)
		swap(A,B);
	head = A;
	tail = B;

	if(!Type)
		swap(head,tail);

	
	// cout << head << " " << tail << endl;
}
	
int Jumper::getHead()
{
	return head;
}
int Jumper::getTail()
{
	return tail;
}
