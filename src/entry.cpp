
#include <cstdlib>
#include <iostream>

#include "utils.h"
#include "Sort.h"

#define MENU_INSERTION 1
#define MENU_EXIT 9

std::vector<int> readFileIntoArray(std::string filename) {
  std::vector<int> arr;

  return arr;
}

void printMenu() {
  std::cout
    << "- - - - - - - - - - - - - - - - - - - - - - - - -" << std::endl
    << "Choose an option:" << std::endl
    << "  " << MENU_INSERTION   << ") Insertion Sort" << std::endl
    << "  " << MENU_EXIT             << ") Exit" << std::endl;
}

int main(int argc, char* argv[]) {
  Sort *_Sort = new Sort();

  std::vector<int> smallSample = readFileIntoArray("");
  std::vector<int> mediumSample = readFileIntoArray("");
  std::vector<int> largeSample = readFileIntoArray("");

  std::cout << "Welcome to Foundations." << std::endl;

  int choice = 0;
  bool hideMenu = false;

  do {
    if (!hideMenu) printMenu();

    std::cin >> choice;
    switch(choice) {
      case MENU_INSERTION:
        std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - -" << std::endl;
        _Sort->insertion(smallSample);
        break;
      case MENU_EXIT:
        std::cout << "Exiting..." << std::endl;
        break;
      default:
        hideMenu = true;
        std::cout << "Invalid option. Please try again." << std::endl;
        break;
    }
  }
  while(choice != 9);

  return 0;


  // return 0;
}
