#ifndef SORT_H
#define SORT_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

class Sort {
  public:
    Sort();
    ~Sort();

    void printInfo(std::string filename);
    void insertion(std::vector<int> arr);
};

#endif
