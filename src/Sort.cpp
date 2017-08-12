
#include "Sort.h"


Sort::Sort() {}
Sort::~Sort() {}

void Sort::insertion(std::vector<int> arr) {
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
}

