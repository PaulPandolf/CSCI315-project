#include <iostream>
#include <string>
#include "bookType.h"

using namespace std;

void bookType::print() const
{
  // cout << uniqueId << " " << ISBN << " " << title << " " << author << " " << publicationDate << " " << description << " " << language;

  cout << title;
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
