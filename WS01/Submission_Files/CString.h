///OOP345 Workshop 1: From One Translation Unit to Another 
// File: CString.cpp
// Version: 1.0
// Date: 2017/09/09
// Author: Galina Erostenko
// Description: CString class Header
///////////////////////////////////////////////////

#ifndef W1_CSTRING_H__
#define W1_CSTRING_H__
#define MAX 3

namespace w1 {
    
    class CString
    {
    private:
        char m_CString[MAX+1];

    public:
        CString(const char* array);
        void display(std::ostream& os) const;
    };
    std::ostream& operator<<(std::ostream& os, const CString& obj);
};
#endif