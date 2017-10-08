///OOP345 Workshop 5: Lambda Expression 
// File: Grades.cpp
// Version: 1.0
// Date: 2017/10/08
// Author: Galina Erostenko
// Description: Grades Class Implementation
///////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include"Grades.h"
#include<string>

namespace w5 {
    Grades::Grades(const char *fileName)
    {
        std::string temp;
        size_t lineCounter = 0;
        numStud = 0;
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
            studentId = new std::string[lineCounter];
            studGrades = new double[lineCounter];
            while (std::getline(file, temp))
            {
                std::string tempGrade;
                int space = temp.find(' ');
                studentId[numStud] = temp.substr(0, space);
                tempGrade = temp.substr(space+1, temp.length());
                studGrades[numStud++] = atof(tempGrade.c_str());
            }
        }
        else
        {
            throw "Oops! Can't open the file...";
        }
    }
    Grades::~Grades()
    {
        delete[] studentId;
        studentId = nullptr;
        delete[] studGrades;
        studGrades = nullptr;
    }
}