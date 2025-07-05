#include "utils.h"

using namespace std;

int main()
{
  libraryCatalogType libraryCatalog = initializeLibrary();

  while (true)
  {
    clearScreen();
    cout << endl;
    showMainMenu(libraryCatalog);
  }

  return 0;
}
