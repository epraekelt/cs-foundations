
#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <ctime>
#include <iomanip>

#include "utils.h"
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


void runInsertionSort(Sort* _Sort, std::vector<int> smallSample, std::vector<int> mediumSample, std::vector<int> largeSample) {
  std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - -" << std::endl;
  std::clock_t start;
  double smallRuntime, mediumRuntime, largeRuntime;
  _Sort->printInfo("insertion-sort");

  start = std::clock();
  _Sort->insertion(smallSample);
  smallRuntime = (std::clock() - start) / (double)CLOCKS_PER_SEC;

  start = std::clock();
  _Sort->insertion(mediumSample);
  mediumRuntime = (std::clock() - start) / (double)CLOCKS_PER_SEC;

  start = std::clock();
  _Sort->insertion(largeSample);
  largeRuntime = (std::clock() - start) / (double)CLOCKS_PER_SEC;

  double total = smallRuntime + mediumRuntime + largeRuntime;

  std::cout << std::fixed;
  std::cout << "Small Sample Runtime (30):   " << std::setprecision(8) << smallRuntime  << "s (" << std::setprecision(2) << ((smallRuntime/total)*100)  << "%)" << std::endl;
  std::cout << "Medium Sample Runtime (100): " << std::setprecision(8) << mediumRuntime << "s (" << std::setprecision(2) << ((mediumRuntime/total)*100) << "%)" << std::endl;
  std::cout << "Large Sample Runtime (1000): " << std::setprecision(8) << largeRuntime  << "s (" << std::setprecision(2) << ((largeRuntime/total)*100)  << "%)" << std::endl;
}


int main(int argc, char* argv[]) {
  Sort *_Sort = new Sort();
  std::vector<int> smallSample = readFileIntoArray("small-sample.txt");
  std::vector<int> mediumSample = readFileIntoArray("medium-sample.txt");
  std::vector<int> largeSample = readFileIntoArray("large-sample.txt");

  std::cout << "Welcome to Foundations." << std::endl;

  int choice = 0;
  bool hideMenu = false;

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
        runInsertionSort(_Sort, smallSample, mediumSample, largeSample);
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
