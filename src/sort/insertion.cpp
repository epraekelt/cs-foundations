/*
Insertion Sort

An iterative sorting algorithm that incrementally places each element in its correct location.

Pseudocode:

i ← 1
while i < length(A)
    j ← i
    while j > 0 and A[j-1] > A[j]
        swap A[j] and A[j-1]
        j ← j - 1
    end while
    i ← i + 1
end while
*/

#include "sort/insertion.h"


void printInfo() {
  std::ifstream file("docs/sort/insertion.md");

  if (file.is_open()) {
    std::cout << file.rdbuf() << std::endl;
    file.close();
  }
}

std::vector<int> insertionSort(std::vector<int> arr) {
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

  return arr;
}

