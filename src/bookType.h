#ifndef H_bookType
#define H_bookType

#include <string>

using namespace std;

class bookType
{
public:
  const std::string &getUniqueId() const { return uniqueId; }
  const std::string &getISBN() const { return ISBN; }
  const std::string &getTitle() const { return title; }
  const std::string &getAuthor() const { return author; }
  const std::string &getPublicationDate() const { return publicationDate; }
  const std::string &getDescription() const { return description; }
  const std::string &getLanguage() const { return language; }

  void print() const;

  void setBook(const string &uniqueId, const string &ISBN,
               const string &title, const string &author,
               const string &publicationDate, const string &description,
               const string &language);

  friend ostream &operator<<(ostream &, const bookType &other);

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