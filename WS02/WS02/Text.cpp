///OOP345 Workshop 2: Move and Copy Semantics 
// File: Text.cpp
// Version: 1.0
// Date: 2017/09/16
// Author: Galina Erostenko
// Description: Text class Implementation
///////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Text.h"
#include <fstream>


namespace w2
{
    void Text::init(const Text& obj)
    {
        if (obj.arraySize > 0)
        {
            arrayOfStr = new (std::nothrow) std::string[obj.arraySize];
            if (arrayOfStr)
            {
                arraySize = obj.arraySize;
                for (int i = 0; i <= arraySize; i++)
                {
                    arrayOfStr[i] = obj.arrayOfStr[i];
                }
            }
        }
        else
        {
            arrayOfStr = nullptr;
            arraySize = 0;
        }
    }
    Text::Text(size_t size) : arraySize(size)
    {
        if (arraySize > 0)
            arrayOfStr = new (std::nothrow) std::string[arraySize];
        else
            arrayOfStr = nullptr;
        
    }
    Text::Text(const std::string& fileName)
    {
        std::string temp;
        size_t lineCounter = 0;
        arraySize = 0;
        std::ifstream file(fileName);
        if (file.is_open())
        {
            while (file.good())
            {
                std::getline(file, temp);
                lineCounter++;
            }
            file.clear();
            file.seekg(0);
            arrayOfStr = new std::string[lineCounter+1];
            while (!file.eof())
            {
                std::getline(file, temp);
                arrayOfStr[arraySize++] = temp;
            }
        }
        else
        {
            arrayOfStr = nullptr;
            arraySize = 0;
        }
    }
    Text::Text(const Text& obj)
    {
        init(obj);
    }
    Text& Text::operator=(const Text& obj)
    {
        if (this != &obj)
        {
            delete[] arrayOfStr;
            init(obj);
        }
        return *this;
    }
    Text::Text(Text&& obj)
    {
        arrayOfStr = obj.arrayOfStr;
        arraySize = obj.arraySize;
        obj.arrayOfStr = nullptr;
        obj.arraySize = 0;
    }
    Text&& Text::operator=(Text&& obj)
    {
        if (this != &obj)
        {
            arrayOfStr = obj.arrayOfStr;
            arraySize = obj.arraySize;
            obj.arrayOfStr = nullptr;
            obj.arraySize = 0;
        }

        return std::move(*this);
    }
    Text::~Text()
    {
        delete[] arrayOfStr;
        arrayOfStr = nullptr;
    }
    size_t Text::size() const
    {
        return arraySize;
    }
}