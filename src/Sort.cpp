
#include "Sort.h"


void printSample(std::vector<int> arr) {
	for (unsigned int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }

  std::cout << std::endl;
}



Sort::Sort() {}

Sort::~Sort() {}

void Sort::printInfo(std::string filename) {
  std::string path = std::string("docs/") + filename + std::string(".md");
  std::ifstream file(path.c_str());

  if (file.is_open()) {
    std::cout << file.rdbuf() << std::endl;
    file.close();
  }
}

void Sort::insertion(std::vector<int> arr) {
  // printSample(arr);

  unsigned int j, temp;

	for (unsigned int i = 0; i < arr.size(); i++) {
		j = i;

    // While the element is smaller than the element at a lower index, move the element down the line
		while (j > 0 && arr[j] < arr[j-1]){
      // Swap the elements
      temp = arr[j];
      arr[j] = arr[j-1];
      arr[j-1] = temp;
      j--;
    }
  }

  // printSample(arr);
}

