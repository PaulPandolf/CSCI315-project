#include <iostream>
#include <string>
#include "bookType.h"

using namespace std;

void bookType::print() const
{
  cout << uniqueId << endl;
  cout << ISBN << endl;
  cout << title << endl;
  cout << author << endl;
  cout << publicationDate << endl;
  cout << description << endl;
  cout << language << endl;
}

void bookType::setBook(const string &uniqueId, const string &ISBN,
                       const string &title, const string &author,
                       const string &publicationDate, const string &description,
                       const string &language)
{
  this->uniqueId = uniqueId;
  this->ISBN = ISBN;
  this->title = title;
  this->author = author;
  this->publicationDate = publicationDate;
  this->description = description;
  this->language = language;
}

bookType::bookType(const string &uniqueId, const string &ISBN,
                   const string &title, const string &author,
                   const string &publicationDate, const string &description,
                   const string &language)
{
  this->uniqueId = uniqueId;
  this->ISBN = ISBN;
  this->title = title;
  this->author = author;
  this->publicationDate = publicationDate;
  this->description = description;
  this->language = language;
}

bookType::bookType()
{
  this->uniqueId = "";
  this->ISBN = "";
  this->title = "";
  this->author = "";
  this->publicationDate = "";
  this->description = "";
  this->language = "";
}

bool bookType::operator==(const bookType &other) const
{
  // You can choose which fields to compare. Usually ISBN is unique:
  return this->title == other.title;
}

bool bookType::operator>=(const bookType &other) const
{
  return this->title >= other.title;
}
