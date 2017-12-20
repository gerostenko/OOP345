///OOP345 Workshop 10 - Multi-Threading
// File: SecureData.cpp
// Version: 1.0
// Date: 2017/12/16
// Author: Galina Erostenko
// Description: SecureData Class Implementation
///////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include<thread>
#include "SecureData.h"

namespace w10 {

    void converter(char* t, char key, int n, const Cryptor& c) {
        for (int i = 0; i < n; i++)
            t[i] = c(t[i], key);
    }

    SecureData::SecureData(const char* file, char key) {
        // open text file
        std::fstream input(file, std::ios::in);
        if (!input)
            throw std::string("\n***Failed to open file ") +
            std::string(file) + std::string(" ***\n");

        // copy from file into memory
        nbytes = 0;
        input >> std::noskipws;
        while (input.good()) {
            char c;
            input >> c;
            nbytes++;
        }
        nbytes--;
        input.clear();
        input.seekg(0, std::ios::beg);
        text = new char[nbytes + 1];

        int i = 0;
        while (input.good())
            input >> text[i++];
        text[--i] = '\0';
        std::cout << "\n" << nbytes << " bytes copied from text "
            << file << " into memory (null byte added)\n";
        encoded = false;

        // encode using key
        code(key);
        std::cout << "Data encrypted in memory\n";
    }

    SecureData::~SecureData() {
        delete[] text;
    }

    void SecureData::display(std::ostream& os) const {
        if (text && !encoded)
            os << text << std::endl;
        else if (encoded)
            throw std::string("\n***Data is encoded***\n");
        else
            throw std::string("\n***No data stored***\n");
    }

    void SecureData::code(char key) {
        int threshold = nbytes / 2;
        
        std::thread t1(converter, text, key, threshold, Cryptor());
        std::thread t2(converter, text+threshold, key, threshold, Cryptor());

        t1.join();
        t2.join();
        
        encoded = !encoded;
    }

    void SecureData::backup(const char* file) {
        if (!text)
            throw std::string("\n***No data stored***\n");
        else if (!encoded)
            throw std::string("\n***Data is not encoded***\n");
        else {
            // open binary file
            std::fstream input(file, std::ios::out | std::ios::binary);
            if (!input)
                throw std::string("\n***Failed to open file ") +
                std::string(file) + std::string(" ***\n");
            // write binary file here
            input.write(text, nbytes);
            
        }
    }

    void SecureData::restore(const char* file, char key) {
        // open binary file
        std::fstream input(file, std::ios::in);
        if (!input)
            throw std::string("\n***Failed to open file ") +
            std::string(file) + std::string(" ***\n");
        //read the file size
        nbytes = 0;
        input >> std::noskipws;
        while (input.good()) {
            char c;
            input >> c;
            nbytes++;
        }
        nbytes--;
        input.clear();
        input.seekg(0, std::ios::beg);
       
        // allocate memory here
        delete[] text;
        text = new char[nbytes + 1];

        // read binary file here
        int i = 0;
        while (input.good())
            input >> text[i++];
        text[--i] = '\0';

        std::cout << "\n" << nbytes + 1 << " bytes copied from binary file "
            << file << " into memory (null byte included)\n";
        encoded = true;

        // decode using key
        code(key);
        std::cout << "Data decrypted in memory\n\n";
    }

    std::ostream& operator<<(std::ostream& os, const SecureData& sd) {
        sd.display(os);
        return os;
    }

}