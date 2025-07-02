#include "utils.h"

using namespace std;

int main()
{
  libraryCatalogType libraryCatalog = initializeLibrary("libraryCatalog.ndjson");

  while (true)
  {
    clearScreen();
    libraryCatalog.print(); // debugging purposes
    cout << endl;
    showMainMenu(libraryCatalog);
  }

  return 0;
}
