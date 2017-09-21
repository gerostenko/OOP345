///OOP345 Workshop 1: From One Translation Unit to Another 
// File: main.cpp
// Version: 1.0
// Date: 2017/09/09
// Author: Galina Erostenko
// Description: Main function
///////////////////////////////////////////////////
#include<iostream>
#include"process.h"
extern const int m_numOfChars;

int main(int argc, char *argv[])
{
    int returnVal = 0;
    std::cout << "Command Line : ";
    for (int i = 0; i < argc; i++)
        std::cout << argv[i] << " ";
    std::cout << std::endl;

    
    if (argc == 1)
    {
        std::cout << "Insufficient number of arguments (min 1)" << std::endl;
        returnVal = 1;
    }
    else
    {
        std::cout << "Maximum number of characters stored : " << m_numOfChars << std::endl;
        for (int i = 1; i < argc; i++)
        {
            process(argv[i]);
        }
    }
    return returnVal;
}