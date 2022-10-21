#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "Book.h"


using namespace std;
class Author
{
private:
  set<pair<pair<int,string>,Book*>> books;
  string name;

public:
Author();
Author(string authorName);
vector<string> getSold(int limit);
void addBook(Book *book0);
};