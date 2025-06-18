#include <iostream>
#include <string>
#include "bookType.h"

using namespace std;

void bookType::print() const
{
  cout << uniqueId << " " << ISBN << " " << title << " " << author << " " << publicationDate << " " << description << " " << language;
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

// string bookType::getAddressString() const
// {
//   return address1 + " " + address2 + " " + city + " " + state + " " + zip;
// }

// string bookType::getAddress1() const
// {
//   return address1;
// }

// string bookType::getAddress2() const
// {
//   return address2;
// }

// string bookType::getCity() const
// {
//   return city;
// }

// string bookType::getState() const
// {
//   return state;
// }

// string bookType::getZip() const
// {
//   return zip;
// }

// ostream &operator<<(ostream &osObject, const bookType &other)
// {
//   osObject << " " << other.address1 << " " << other.address2 << " " << other.city << " " << other.state << " " << other.zip << " ";

//   return osObject;
// }

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
