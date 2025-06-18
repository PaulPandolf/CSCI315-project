#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "libraryCatalogType.h"
#include "doublyLinkedList.h"

void showMainMenu();
void clearScreen();
void searchBook();
void escapeText();

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
    showMainMenu();
  }

  doublyLinkedList<int> list;

  list.insert(1);
  list.insert(2);
  list.insert(3);
  list.insert(4);
  list.insert(5);
  list.insert(6);

  list.print();

  return 0;
}

// source: https://medium.com/@ryan_forrester_/c-screen-clearing-how-to-guide-cff5bf764ccd
void clearScreen()
{
#ifdef _WIN32
  system("CLS");
#else
  system("clear");
#endif
}

void searchBook()
{
  clearScreen();
  escapeText();
  cout << "Search Catalog\n\n";
  while (true)
  {
  }
}

void uploadBooks()
{
  clearScreen();
  escapeText();
  cout << "Upload Books\n\n";
  while (true)
  {
  }
}

void clearLastLine() // https://www.reddit.com/r/cpp_questions/comments/14ypjb6/how_do_i_replace_already_printed_text_in_the/
{
  for (int i = 0; i < 100; ++i)
  {
    std::cout << " " << '\r';
  }
}

void escapeText()
{
  cout << "Press ESC at any time to return to the main menu\n\n";
}

void showMainMenu()
{
  cout << "Welcome to the CSCI315 Library! What action would you like to perform?" << endl;
  escapeText();
  cout << "1. List catalog" << endl;
  cout << "2. Search catalog" << endl;
  cout << "3. Add a book" << endl;
  cout << "4. Upload books from file" << endl;
  bool valid = false;
  int selection;
  double result;

  string errorStr = "Invalid selection\n";

  // loop over this until valid input and no errors recieved.
  while (valid == false)
  {
    cin >> selection;

    switch (selection)
    {
    case 1:
      /* code */
      break;
    case 2:
      searchBook();
      /* code */
      break;
    case 3:
      /* code */
      break;
    case 4:
      uploadBooks();
      /* code */
      break;

    default:
      valid == false;
      break;
    }
  }
}
