// libraryCatalogType.cpp
#include "libraryCatalogType.h"
#include <iostream>
#include <algorithm>

using namespace std;

bookType libraryCatalogType::findByLastname(string lastname)
{
  cout << "Person with last name " << lastname << " was not found." << endl;
  return bookType();
}

nodeType<bookType> *libraryCatalogType::getFirst()
{
  return first;
}

void libraryCatalogType::print()
{
  nodeType<bookType> *current = first;
  while (current != nullptr)
  {
    current->info.print();
    cout << " \n";
    current = current->next;
  }
}

void libraryCatalogType::insert(const bookType &insertItem)
{
  nodeType<bookType> *current;
  nodeType<bookType> *trailCurrent;
  nodeType<bookType> *newNode;
  bool found = false;

  newNode = new nodeType<bookType>;
  newNode->info = insertItem;
  newNode->next = NULL;
  newNode->back = NULL;

  if (first == NULL)
  {
    first = last = newNode;
  }
  else
  {
    current = first;
    while (current != NULL && !found)
    {
      std::string a = insertItem.getTitle();
      std::string b = current->info.getTitle();
      std::transform(a.begin(), a.end(), a.begin(), ::tolower);
      std::transform(b.begin(), b.end(), b.begin(), ::tolower);

      if (a <= b)
        found = true;
      if (!found)
      {
        trailCurrent = current;
        current = current->next;
      }
    }

    if (current == first)
    {
      first->back = newNode;
      newNode->next = first;
      first = newNode;
    }
    else
    {
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
    }
  }
  count++;
}

void libraryCatalogType::printRelations(string relation)
{
  // Not implemented
}

void libraryCatalogType::uploadBooks(ifstream &infile, libraryCatalogType &libraryCatalog)
{
  string line;
  while (getline(infile, line))
  {
    if (line.empty())
      continue;
    json bookJson = json::parse(line);

    bookType book(
        bookJson["uniqueId"],
        bookJson["ISBN"],
        bookJson["title"],
        bookJson["author"],
        bookJson["publicationDate"],
        bookJson["description"],
        bookJson["language"]);

    libraryCatalog.insert(book);
  }
}
