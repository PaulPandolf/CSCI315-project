// libraryUI.h
#ifndef UTILS
#define UTILS

#include "libraryCatalogType.h"

// Function declarations
libraryCatalogType initializeLibrary(string file);
void showMainMenu(libraryCatalogType &catalog);
void clearScreen();
void pause();
void escapeText();
void searchBook(libraryCatalogType &catalog);
void uploadBooks();
void addBook(libraryCatalogType &catalog);
void deleteBook(libraryCatalogType &catalog);

#endif // UTILS
