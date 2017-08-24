#ifndef __CSFOUNDATIONS_CONTROLLER_H
#define __CSFOUNDATIONS_CONTROLLER_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <ctime>
#include <iomanip>
#include <functional>
namespace csfoundation {
    class Controller {
    public:
        Controller(bool verbose);
        ~Controller();

        void printInfo(std::string filename);
    
        template <class T> void printSample(std::vector<T> arr) {
            for (auto& val : arr) {
                std::cout << val << " ";
            }
            std::cout << std::endl;
        }
    
        template <class T> double runAlgorithm(std::string const docfile, 
            std::function<void(std::vector<T>)> func, 
            std::vector<T> data) {
                std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << std::endl;
            std::clock_t start;
            double runtime;
            this->printInfo(docfile);
        
            start = std::clock();
            if (verbose) {
                this->printSample(data);
            }
            func(data);
            runtime = (std::clock() - start) / (double)CLOCKS_PER_SEC;
            std::cout << std::fixed;
            std::cout << "Sample size (" << data.size() << "): "  << std::setprecision(8)<< runtime 
                << "s" << std::endl;
            return runtime;
        }

    private:
        bool verbose;

    };
}
#endif
