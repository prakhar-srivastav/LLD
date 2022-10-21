#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <map>
// #include "Category.h"
// #include "Author.h"
using namespace std;
class Book
{
private:

  Author *author;
  Category *category;
  string name;
  string publisher;
  string publishYear;
  int price;
  int count;
public:
  Book();
  Book(string name0,string publisher0,string publishYear0,int price0,int cnt0);
  // void assign(Author *author0,Category *category0);
  bool isPrefix(string name0);
  string getName();
  int getCount();
};