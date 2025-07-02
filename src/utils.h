// libraryUI.h
#ifndef UTILS
#define UTILS

#include "libraryCatalogType.h"

// Function declarations
libraryCatalogType initializeLibrary(string file);
void showMainMenu(libraryCatalogType &catalog);
void clearScreen();
void escapeText();
void searchBook();
void uploadBooks();
void addBook(libraryCatalogType &catalog);
void deleteBook(libraryCatalogType &catalog);

#endif // UTILS
