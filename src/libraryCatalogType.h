#ifndef LIBRARY_CATALOG_TYPE_H
#define LIBRARY_CATALOG_TYPE_H

#include <string>
#include <fstream>
#include "doublyLinkedList.h"
#include "bookType.h"
#include "json.hpp"

using json = nlohmann::json;

class libraryCatalogType : public doublyLinkedList<bookType>
{
public:
  void insert(const bookType &book);
  void uploadBooks(std::ifstream &infile, libraryCatalogType &libraryCatalog);
  bookType findByLastname(std::string lastname);
  void print();
  void printRange(std::string lname1, std::string lname2);
  void printRelations(std::string relation);
  nodeType<bookType> *getFirst();
};

#endif // LIBRARY_CATALOG_TYPE_H
