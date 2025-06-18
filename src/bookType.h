#ifndef H_bookType
#define H_bookType

#include <string>

using namespace std;

class bookType
{
public:
  void print() const;

  void setBook(const string &uniqueId, const string &ISBN,
               const string &title, const string &author,
               const string &publicationDate, const string &description,
               const string &language);

  string getAddressString() const;

  friend ostream &operator<<(ostream &, const bookType &other);
  bookType getAddress() const;
  string getAddress1() const;
  string getAddress2() const;
  string getCity() const;
  string getState() const;
  string getZip() const;

  bookType();

  bookType(const string &uniqueId, const string &ISBN,
           const string &title, const string &author,
           const string &publicationDate, const string &description,
           const string &language);

private:
  string uniqueId;
  string ISBN;
  string title;
  string author;
  string publicationDate;
  string description;
  string language;
};

#endif