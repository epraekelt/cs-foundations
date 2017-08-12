
#include <cstdlib>    // atoi
#include <iostream>

#include "Controller.h"
#include "Sort.h"


#define MENU_INSERTION 1
#define MENU_EXIT 9


std::vector<int> readFileIntoArray(std::string filename) {
  std::vector<int> arr;

  std::string path = std::string("bin/") + filename;
  std::ifstream file(path.c_str());

  std::string line;

  while (getline(file, line)) {
    int value = std::atoi(line.c_str());
    arr.push_back(value);
  }

  return arr;
}

void test(std::vector<int>) {
  std::cout << "WHAT" << std::endl;
}


int main(int argc, char* argv[]) {
  int choice = 0;
  bool hideMenu = false;
  bool verbose = false;

  Controller _Controller = Controller(verbose);
  Sort _Sort = Sort();

  std::vector<int> smallSample = readFileIntoArray("small-sample.txt");
  std::vector<int> mediumSample = readFileIntoArray("medium-sample.txt");
  std::vector<int> largeSample = readFileIntoArray("large-sample.txt");

  std::cout << "Welcome to Foundations." << std::endl;

  while(choice != 9) {
    if (!hideMenu) {
      std::cout
        << "- - - - - - - - - - - - - - - - - - - - - - - - -" << std::endl
        << "Choose an option:" << std::endl
        << "  " << MENU_INSERTION   << ") Insertion Sort" << std::endl
        << "  " << MENU_EXIT             << ") Exit" << std::endl;
    }

    std::cin >> choice;
    switch(choice) {
      case MENU_INSERTION:
        _Controller.runAlgorithm("insertion-sort.md", Sort::insertion, smallSample, mediumSample, largeSample);
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

  return 0;
}
