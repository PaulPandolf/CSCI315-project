#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include "libraryCatalogType.h"
#include "doublyLinkedList.h"

using namespace std;

void showMainMenu(libraryCatalogType &catalog);
void clearScreen();
void escapeText();
void searchBook();
void uploadBooks();
void addBook(libraryCatalogType &catalog);    // new
void deleteBook(libraryCatalogType &catalog); // new

int main()
{
  libraryCatalogType libraryCatalog;
  ifstream infile("libraryCatalog.ndjson");

  if (!infile)
  {
    cerr << "The library database file does not exist." << endl;
    return 1;
  }

  libraryCatalog.uploadBooks(infile, libraryCatalog);

  while (true)
  {
    clearScreen();
    libraryCatalog.print();
    cout << endl;
    showMainMenu(libraryCatalog);
  }

  return 0;
}

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
    system("pause");
    break;
  case 2:
    searchBook();
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
    system("pause");
    break;
  }
}

void clearScreen()
{
#ifdef _WIN32
  system("CLS");
#else
  system("clear");
#endif
}

void escapeText()
{
  cout << "Press ESC at any time to return to the main menu\n\n";
}

void searchBook()
{
  clearScreen();
  escapeText();
  cout << "Search Catalog (Not yet implemented)\n\n";
  system("pause");
}

void uploadBooks()
{
  clearScreen();
  escapeText();
  cout << "Upload Books (Not yet implemented)\n\n";
  system("pause");
}

// new- add/updte function

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
  system("pause");
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

  // make lowercase for case insensitive comparison
  transform(titleToDelete.begin(), titleToDelete.end(), titleToDelete.begin(), ::tolower);

  nodeType<bookType> *current = catalog.first;
  bool found = false;

  while (current != nullptr)
  {
    string currentTitle = current->info.getTitle();
    string originalTitle = currentTitle; // to print original case
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

  system("pause");
}