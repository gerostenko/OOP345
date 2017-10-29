// Workshop 6 - STL Containers
// w6.cpp

#include <iostream>
#include <string>
#include "Sale.h"

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << argv[0] << ": incorrect number of arguments\n";
        std::cerr << "Usage: " << argv[0] << " file_name\n";
        return 1;
    }

    try {
        w6::Sale sale(argv[1]);
        sale.display(std::cout);
    }
    catch (const char* msg) {
        std::cout << msg << std::endl;
    }
    
    std::cout << "\nPress any key to continue ... ";
    std::cin.get();
}