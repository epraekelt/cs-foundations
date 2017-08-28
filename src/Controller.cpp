#include "Controller.h"

csfoundation::Controller::Controller(bool verbose) {
    this->verbose = verbose;
}

csfoundation::Controller::~Controller() {
    // Nothing to do
}

void csfoundation::Controller::printInfo(std::string filename) {
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
