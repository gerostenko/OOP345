///OOP345 Workshop 1: From One Translation Unit to Another 
// File: CString.cpp
// Version: 1.0
// Date: 2017/09/09
// Author: Galina Erostenko
// Description: Implementation of CString class
///////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <cstring>
#include"CString.h"
extern const int m_numOfChars = MAX;

namespace w1
{
    CString::CString(const char* array)
    {
        if (array[0] == '\0')
        {
            m_CString[0] = '\0';
        }
        else
        {
            m_CString[0] = '\0';
            strncpy(m_CString, array, m_numOfChars);
            m_CString[m_numOfChars] = '\0';
        }
    }
    void CString::display(std::ostream& os) const
    {
        os << m_CString;
    }

    std::ostream& operator<<(std::ostream& os, const CString& obj)
    {
        static int numerOfCalls = 0;
        os << numerOfCalls++ << ": ";
        obj.display(os);
        return os; 
    }
};