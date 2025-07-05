#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include "utils.h"
#include "doublyLinkedList.h" // for nodeType
#include "bookType.h"         // if needed directly

void showMainMenu(libraryCatalogType &catalog)
{
  cout << "Welcome to the CSCI315 Library! What action would you like to perform?\n";
  escapeText();
  cout << "1. List catalog\n";
  cout << "2. Search catalog\n";
  cout << "3. Upload books from file\n";
  cout << "4. Add a book\n";
  cout << "5. Delete a book\n";
  cout << "\nEnter your choice: ";

  int selection;
  cin >> selection;

  switch (selection)
  {
  case 1:
    clearScreen();
    catalog.print();
    pause();
    break;
  case 2:
    searchBook(catalog);
    break;
  case 3:
    uploadBooks(catalog);
    break;
  case 4:
    addBook(catalog);
    break;
  case 5:
    deleteBook(catalog);
    break;
  default:
    cout << "Invalid selection.\n";
    pause();
    break;
  }
}

void pause()
{
  cout << "\nPress Enter to continue...";
  cin.ignore();
  cin.get();
}

void clearScreen()
{
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}

void escapeText()
{
  cout << "\033[0m"; // reset formatting (for Unix terminals)
}

void searchBook(libraryCatalogType &catalog)
{
  clearScreen();
  escapeText();
  cout << "Search Book\n\n";

  cin.ignore(); // flush newline character

  string sTitle;
  cout << "Enter a title to search: ";
  getline(cin, sTitle);

  transform(sTitle.begin(), sTitle.end(), sTitle.begin(), ::tolower);

  nodeType<bookType> *current = catalog.getFirst();
  bool found = false;

  while (current != nullptr)
  {
    string currentTitle = current->info.getTitle();
    string originalTitle = currentTitle;

    transform(currentTitle.begin(), currentTitle.end(), currentTitle.begin(), ::tolower);

    if (currentTitle == sTitle)
    {
      cout << "\nBook titled '" << originalTitle << "' found!\n\n";
      current->info.print();
      found = true;
      break;
    }

    current = current->next;
  }

  if (!found)
  {
    cout << "\nBook titled '" << sTitle << "' not found.\n\n";
  }

  pause();
}

void uploadBooks(libraryCatalogType &catalog)
{
  clearScreen();
  escapeText();
  cout << "Upload Books\n\n";

  cout << "Enter file name to upload: ";

  string fileName;
  ifstream infile;

  while (true)
  {
    cout << "Enter the filename: ";
    getline(cin, fileName);

    infile.open(fileName);

    if (infile.is_open())
    {
      catalog.uploadBooks(infile, catalog);
      cout << "File uploaded successfully.\n";
      break;
    }
    else
    {
      cerr << "File not found or failed to open. Please try again.\n";
    }
  }

  getline(cin, fileName);

  syncFileAndLinkedList(catalog);
  pause();
}

void addBook(libraryCatalogType &catalog)
{
  clearScreen();
  escapeText();
  cout << "Add New Book\n\n";

  cin.ignore(); // Flush newline character

  string uniqueId, ISBN, title, author, publicationDate, description, language;

  cout << "Enter Unique ID: ";
  getline(cin, uniqueId);
  cout << "Enter ISBN: ";
  getline(cin, ISBN);
  cout << "Enter Title: ";
  getline(cin, title);
  cout << "Enter Author: ";
  getline(cin, author);
  cout << "Enter Publication Date (yyyy-mm-dd): ";
  getline(cin, publicationDate);
  cout << "Enter Description: ";
  getline(cin, description);
  cout << "Enter Language: ";
  getline(cin, language);

  bookType newBook(uniqueId, ISBN, title, author, publicationDate, description, language);
  catalog.insert(newBook);

  syncFileAndLinkedList(catalog);

  cout << "\nBook added successfully!\n";

  pause();
}

void deleteBook(libraryCatalogType &catalog)
{
  clearScreen();
  escapeText();
  cout << "Delete Book\n\n";

  cin.ignore(); // flush newline character

  string titleToDelete;
  cout << "Enter the title of the book to delete: ";
  getline(cin, titleToDelete);

  transform(titleToDelete.begin(), titleToDelete.end(), titleToDelete.begin(), ::tolower);

  nodeType<bookType> *current = catalog.getFirst();
  bool found = false;

  while (current != nullptr)
  {
    string currentTitle = current->info.getTitle();
    string originalTitle = currentTitle;
    transform(currentTitle.begin(), currentTitle.end(), currentTitle.begin(), ::tolower);

    if (currentTitle == titleToDelete)
    {
      catalog.deleteNode(current->info);
      cout << "\nBook titled '" << originalTitle << "' deleted successfully.\n";
      found = true;
      break;
    }

    current = current->next;
  }

  if (!found)
  {
    cout << "\nBook titled '" << titleToDelete << "' not found.\n";
  }

  syncFileAndLinkedList(catalog);
  pause();
}

void syncFileAndLinkedList(libraryCatalogType &catalog)
{
  ofstream outfile("libraryCatalog.ndjson");

  if (!outfile)
  {
    clearScreen();
    cerr << "The library database file does not exist. Try again." << endl;
    return;
  }
  else
  {
    // upload book database to the linked list
    if (catalog.isEmptyList())
      cout << "List is empty";

    linkedListIterator<bookType> iterator(catalog.getFirst());

    while (iterator != linkedListIterator<bookType>(nullptr))
    {
      bookType book = *iterator;

      json myJson = {
          {"uniqueId", book.getUniqueId()},
          {"ISBN", book.getISBN()},
          {"title", book.getTitle()},
          {"author", book.getAuthor()},
          {"publicationDate", book.getPublicationDate()},
          {"description", book.getDescription()},
          {"language", book.getLanguage()}};

      outfile << myJson.dump() << endl;

      ++iterator;
    }

    outfile.close();
  }
  return;
}

libraryCatalogType initializeLibrary()
{
  libraryCatalogType libraryCatalog;
  std::ifstream infile("libraryCatalog.ndjson");

  if (!infile)
  {
    std::ofstream outfile("libraryCatalog.ndjson");
    outfile.close();
    infile.open("libraryCatalog.ndjson");
  }

  libraryCatalog.uploadBooks(infile, libraryCatalog);
  return libraryCatalog;
}
