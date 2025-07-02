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
    uploadBooks();
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

void uploadBooks()
{
  clearScreen();
  escapeText();
  cout << "Upload Books (Not yet implemented)\n\n";
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

  pause();
}

libraryCatalogType initializeLibrary(string file)
{
  libraryCatalogType libraryCatalog;
  ifstream infile(file);

  while (!infile)
  {
    clearScreen();
    cerr << "The library database file does not exist. Try again." << endl;
  }

  // upload book database to the linked list
  libraryCatalog.uploadBooks(infile, libraryCatalog);

  return libraryCatalog;
}
