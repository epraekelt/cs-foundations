#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <ctime>
#include <iomanip>

class Controller {
  public:
    Controller(bool verbose);
    ~Controller();

    void printInfo(std::string filename);
    void printSample(std::vector<int> arr);
    void runAlgorithm(std::string docfile, void (*run)(std::vector<int>), std::vector<int> smallSample, std::vector<int> mediumSample, std::vector<int> largeSample);

  private:
    bool verbose;
};

#endif
