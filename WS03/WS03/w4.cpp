// Workshop 3 - Templates
// w4.cpp

#include <iostream>
#include <iomanip>
#include <string>
#include "KVList.h"

namespace w3 {
    template <typename K, typename V, int N>
    void display(const std::string& msg, const KVList<K, V, N>& list, int w) {
        std::cout << msg;
        for (size_t i = 0; i < list.size(); i++)
            std::cout << std::setw(w) << list.key(i)
            << " : " << list.value(i) << std::endl;
    }
}

int main(int argc, char** argv) {
    if (argc != 1) {
        std::cerr << argv[0] << ": too many arguments\n";
        return 1;
    }

    bool keepreading;
    std::cout << std::fixed << std::setprecision(2);

    std::cout << "\nInventory\n=========\n";
    w3::KVList <std::string, double, 5> inventory;
    std::string str;
    double price;

    keepreading = true;
    do {
        std::cout << "Product : ";
        getline(std::cin, str);
        if (str.compare("quit") == 0) {
            keepreading = false;
        }
        else {
            std::cout << "Price : ";
            std::cin >> price;
            std::cin.ignore();
            inventory.add(str, price);
        }
    } while (keepreading);
    display("\nPrice List\n----------\n", inventory, 13);

    std::cout << "\nCorrections\n-----------\n";
    keepreading = true;
    do {
        std::cout << "Product : ";
        getline(std::cin, str);
        if (str.compare("quit") == 0) {
            keepreading = false;
        }
        else {
            int i = inventory.find(str);
            if (i != -1) {
                std::cout << "Price : ";
                std::cin >> price;
                std::cin.ignore();
                inventory.replace(i, str, price);
            }
        }
    } while (keepreading);
    display("\nPrice List\n----------\n", inventory, 13);

    std::cout << "\nGlossary\n========\n";
    w3::KVList <std::string, std::string, 5> glossary;
    std::string key, definition;

    keepreading = true;
    do {
        std::cout << "Key : ";
        getline(std::cin, key);
        if (key.compare("quit") == 0) {
            keepreading = false;
        }
        else {
            std::cout << "Definition : ";
            getline(std::cin, definition);
            glossary.add(key, definition);
        }
    } while (keepreading);
    display("\nEntries\n-------\n", glossary, 5);
    return 0;
}