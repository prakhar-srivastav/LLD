#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "Category.h"
#include "Book.h"
#include "Author.h"

using namespace std;
class App
{
private:
  map<string,Book> books;
  map<string,Category> categories;
  map<string,Author> authors;
public:
App();
vector<string> addBook();
vector<string> searchByName();
vector<string> searchByAuthor();
vector<string> TopSoldByAuthor();
vector<string> TopSoldByCategory();
};