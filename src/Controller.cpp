
#include "Controller.h"


Controller::Controller(bool verbose) { this->verbose = verbose; }
Controller::~Controller() {}

void Controller::printInfo(std::string filename) {
  std::string path = std::string("docs/") + filename;
  std::ifstream file(path.c_str());

  if (file.is_open()) {
    std::cout << file.rdbuf() << std::endl;
    file.close();
  }
  else {
    std::cout << "Error: File not found." << std::endl;
  }
}

void Controller::printSample(std::vector<int> arr) {
	for (unsigned int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }

  std::cout << std::endl;
}

void Controller::runAlgorithm(std::string docfile, void (*algorithm)(std::vector<int>), std::vector<int> smallSample, std::vector<int> mediumSample, std::vector<int> largeSample) {
  std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - -" << std::endl;
  std::clock_t start;
  double smallRuntime, mediumRuntime, largeRuntime;
  this->printInfo(docfile);

  start = std::clock();
  if (this->verbose) this->printSample(smallSample);
  algorithm(smallSample);
  if (this->verbose) this->printSample(smallSample);
  smallRuntime = (std::clock() - start) / (double)CLOCKS_PER_SEC;

  start = std::clock();
  if (this->verbose) this->printSample(mediumSample);
  algorithm(mediumSample);
  if (this->verbose) this->printSample(mediumSample);
  mediumRuntime = (std::clock() - start) / (double)CLOCKS_PER_SEC;

  start = std::clock();
  if (this->verbose) this->printSample(largeSample);
  algorithm(largeSample);
  if (this->verbose) this->printSample(largeSample);
  largeRuntime = (std::clock() - start) / (double)CLOCKS_PER_SEC;

  double total = smallRuntime + mediumRuntime + largeRuntime;

  std::cout << std::fixed;
  std::cout << "Small Sample Runtime (30):   " << std::setprecision(8) << smallRuntime  << "s (" << std::setprecision(2) << ((smallRuntime/total)*100)  << "%)" << std::endl;
  std::cout << "Medium Sample Runtime (100): " << std::setprecision(8) << mediumRuntime << "s (" << std::setprecision(2) << ((mediumRuntime/total)*100) << "%)" << std::endl;
  std::cout << "Large Sample Runtime (1000): " << std::setprecision(8) << largeRuntime  << "s (" << std::setprecision(2) << ((largeRuntime/total)*100)  << "%)" << std::endl;
}
