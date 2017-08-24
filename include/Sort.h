#ifndef __CSFOUNDATIONS_SORT_H
#define __CSFOUNDATIONS_SORT_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

namespace csfoundation {
    namespace sort {
        template <class T> void insertion(std::vector<T> arr) {
            for (size_t i = 1; i < arr.size(); ++i) {
                size_t j = i;

                while (j > 0 && arr[j] < arr[j-1]) {
                    T temp = arr[j];
                    arr[j] = arr[j-1];
                    arr[j-1] = temp;
                    --j;
                }
            }
        }
    }
}

#endif
