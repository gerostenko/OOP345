///OOP345 Workshop 6: STL Containers
// File: Sale.h
// Version: 1.0
// Date: 2017/10/17
// Author: Galina Erostenko
// Description: Sale Class Header File
///////////////////////////////////////////////////

#ifndef SALE_H_
#define SALE_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <typeinfo>
#include "iProduct.h"

namespace w6 {
    class Sale {
    private:
        std::vector<iProduct*> m_saleProducts;
    public:
        Sale(const char *fileName);
        void display(std::ostream& os) const;
    };


}
#endif