#include <string>
#include "doublyLinkedList.h"
#include "bookType.h"
#include "json.hpp"
using json = nlohmann::json;

using namespace std;

class libraryCatalogType : public doublyLinkedList<bookType>
{
public:
  void insert(const bookType &book);
  void uploadBooks(ifstream &infile, libraryCatalogType &libraryCatalog);
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

  return bookType();
}

void libraryCatalogType::print()
{
  nodeType<bookType> *current; // pointer to traverse the list

  current = first; // set current to point to the first node

  while (current != NULL)
  {
    current->info.print(); // output info
    cout << " \n";

    current = current->next;
  } // end while
} // end print

void libraryCatalogType::insert(const bookType &insertItem)
{
  nodeType<bookType> *current;      // pointer to traverse the list
  nodeType<bookType> *trailCurrent; // pointer just before current
  nodeType<bookType> *newNode;      // pointer to create a node
  bool found;

  newNode = new nodeType<bookType>; // create the node
  newNode->info = insertItem;       // store the new item in the node
  newNode->next = NULL;
  newNode->back = NULL;

  if (first == NULL) // if the list is empty, newNode is
                     // the only node
  {
    first = newNode;
    last = newNode;
    count++;
  }
  else
  {
    found = false;
    current = first;

    while (current != NULL && !found) // search the list
    {
      std::string a = insertItem.getTitle();
      std::string b = current->info.getTitle();

      // Convert both to lowercase
      std::transform(a.begin(), a.end(), a.begin(), ::tolower);
      std::transform(b.begin(), b.end(), b.begin(), ::tolower);

      if (a < b)
      {
        found = true;
      }

      if (a == b)
      {
        found = true;
      }

      if (found == false)
      {
        trailCurrent = current;
        current = current->next;
      }
    }

    if (current == first) // insert newNode before first
    {
      first->back = newNode;
      newNode->next = first;
      first = newNode;
      count++;
    }
    else
    {
      // insert newNode between trailCurrent and current
      if (current != NULL)
      {
        trailCurrent->next = newNode;
        newNode->back = trailCurrent;
        newNode->next = current;
        current->back = newNode;
      }
      else
      {
        trailCurrent->next = newNode;
        newNode->back = trailCurrent;
        last = newNode;
      }

      count++;
    } // end else
  } // end else
} // end insert

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
