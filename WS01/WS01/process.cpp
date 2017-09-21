///OOP345 Workshop 1: From One Translation Unit to Another 
// File: process.cpp
// Version: 1.0
// Date: 2017/09/09
// Author: Galina Erostenko
// Description: Implementation of process function
///////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "CString.h"
#include"process.h"

void process(const char* string)
{
    w1::CString object(string);
    std::cout << object << std::endl;
}