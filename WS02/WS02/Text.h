///OOP345 Workshop 2: Move and Copy Semantics 
// File: Text.h
// Version: 1.0
// Date: 2017/09/16
// Author: Galina Erostenko
// Description: Text class Header
///////////////////////////////////////////////////

#ifndef W2_TEXT_H__
#define W2_TEXT_H__
#include <string>

namespace w2 {
    class Text
    {
        std::string* arrayOfStr;
        size_t arraySize;
        void init(const Text& obj);

    public:
        Text(size_t arraySize = 0);
        Text(const std::string& fileName);
        Text(const Text& obj);
        Text& operator=(const Text& obj);
        Text(Text&& obj);
        Text&& operator=(Text&& obj);
        ~Text();
        size_t size() const;
    };
}
#endif