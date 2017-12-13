///OOP345 Workshop 8: Smart Pointers
// File: w9.cpp
// Version: 1.0
// Date: 2017/12/13
// Author: Galina Erostenko
// Description: Main File
///////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include "Element.h"
#include "List.h"
#include<memory>

const int FWC = 5;
const int FWD = 12;
const int FWP = 8;

w9::List<w9::Product> merge(const w9::List<w9::Description>& desc,
    const w9::List<w9::Price>& price) {
    w9::List<w9::Product> priceList;
    
    // complete this part
    for (int i = 0; i < desc.size(); i++)
    {
        for (int j = 0; j < price.size(); j++)
        {
            if (desc[i].code == price[j].code)
            {
                //old priceList += w9::Product(new w9::Product(desc[i].desc, price[j].price));
                std::unique_ptr <w9::Product> temp = std::unique_ptr<w9::Product>(new w9::Product(desc[i].desc, price[j].price));
                temp->validate();
                priceList += std::move(temp);
            }
        }
    }
    return priceList;
}

int main(int argc, char** argv) {
    std::cout << "\nCommand Line : ";
    for (int i = 0; i < argc; i++) {
        std::cout << argv[i] << ' ';
    }
    std::cout << std::endl;
    if (argc != 3) {
        std::cerr << "\n***Incorrect number of arguments***\n";
        return 1;
    }

    try {
        w9::List<w9::Description> desc(argv[1]);
        std::cout << std::endl;
        std::cout << std::setw(FWC) << "Code" <<
            std::setw(FWD) << "Description" << std::endl;
        std::cout << desc << std::endl;
        w9::List<w9::Price> price(argv[2]);
        std::cout << std::endl;
        std::cout << std::setw(FWC) << "Code" <<
            std::setw(FWP) << "Price" << std::endl;
        std::cout << price << std::endl;
        w9::List<w9::Product> priceList = merge(desc, price);
        std::cout << std::endl;
        std::cout << std::setw(FWD) << "Description" <<
            std::setw(FWP) << "Price" << std::endl;
        std::cout << priceList << std::endl;
    }
    catch (const std::string& msg) {
        std::cerr << msg << std::endl;
    }
    catch (const char* msg) {
        std::cerr << msg << std::endl;
    }

    std::cout << "\nPress any key to continue ... ";
    std::cin.get();
}