///OOP345 Workshop 10 - Multi-Threading
// File: SecureData.h
// Version: 1.0
// Date: 2017/12/16
// Author: Galina Erostenko
// Description: SecureData Class Header
///////////////////////////////////////////////////
#ifndef SECUREDATA_H__
#define SECUREDATA_H__
#include <iostream>

namespace w10 {

    class Cryptor {
    public:
        char operator()(char in, char key) const { return in ^ key; }
    };
    void converter(char*, char, int, const Cryptor&);

    class SecureData {
        char* text;
        int nbytes;
        bool encoded;
        void code(char);
    public:
        SecureData(const char*, char);
        SecureData(const SecureData&) = delete;
        SecureData& operator=(const SecureData&) = delete;
        ~SecureData();
        void display(std::ostream&) const;
        void backup(const char*);
        void restore(const char*, char);
    };
    std::ostream& operator<<(std::ostream&, const SecureData&);
}
#endif