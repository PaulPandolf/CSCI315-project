#include <string>
#include "doublyLinkedList.h"
#include "bookType.h"
#include "json.hpp"
using json = nlohmann::json;

using namespace std;

class libraryCatalogType : public doublyLinkedList<bookType>
{
public:
  void libraryCatalogType::uploadBooks(ifstream &infile, libraryCatalogType &libraryCatalog);
  bookType findByLastname(string lastname);
  void print();
  void printRange(string lname1, string lname2);
  void printRelations(string relation);
};

bookType libraryCatalogType::findByLastname(string lastname)
{
  // bool found = false; // set found to false
  // linkedListIterator<bookType> current = begin();

  // // in the list
  // while (current != nullptr && !found) // search the list
  // {
  //   bookType currentPerson = *current;

  //   if (currentPerson.checkLastName(lastname)) // the item is found
  //   {
  //     cout << "Person with last name " << lastname << " was found.";
  //     found = true;
  //     return currentPerson;
  //   }
  //   else
  //     current = ++current; // advance current to
  // }
  cout << "Person with last name " << lastname << " was not found." << endl;
}

void libraryCatalogType::printRelations(string relation)
{
  // linkedListIterator<bookType> current = begin();

  // while (current != nullptr)
  // {
  //   bookType person = *current;
  //   if (person.getRelation() == relation)
  //   {
  //     cout << person.getFirstName() << " " << person.getLastName() << "\n";
  //   }
  //   ++current;
  // }
}

void libraryCatalogType::uploadBooks(ifstream &infile, libraryCatalogType &libraryCatalog)
{
  string line;
  while (getline(infile, line))
  {
    if (line.empty())
      continue;

    json bookJson = json::parse(line);

    std::string uniqueId = bookJson["uniqueId"];
    std::string ISBN = bookJson["ISBN"];
    std::string title = bookJson["title"];
    std::string author = bookJson["author"];
    std::string publicationDate = bookJson["publicationDate"];
    std::string description = bookJson["description"];
    std::string language = bookJson["language"];

    bookType book(uniqueId, ISBN, title, author, publicationDate, description, language);
    libraryCatalog.insert(book);
  }
}
