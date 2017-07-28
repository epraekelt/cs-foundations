
#include "utils.h"
#include "Sort.h"

int main(int argc, char* argv[]) {
  std::cout << "Start here..." << std::endl;

  std::vector<int> arr;

  for (int i = 0; i < 6; i++) {
    arr.push_back(i+50);
  }

  Sort *_Sort = new Sort();
  _Sort->insertion(arr);

  return 0;
}
