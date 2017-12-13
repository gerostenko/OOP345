///OOP345 Workshop 6: STL Containers
// File: Sale.cpp
// Version: 1.0
// Date: 2017/10/17
// Author: Galina Erostenko
// Description: Sale Class Implementation
///////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include "Sale.h"

namespace w6 {
    Sale::Sale(const char *fileName) 
    {
        iProduct* temp = nullptr;
        std::ifstream file(fileName);
        if (file.is_open()) {
            while (file.good())
            {
                temp = readProduct(file);
                if (temp != nullptr) {
                    m_saleProducts.push_back(temp);
                }
                else {
                    throw "File Corrupted!";
                }
            }
        }
        else {
            throw "Can't open the file";
        }
        file.close();
    }
    void Sale::display(std::ostream& os) const
    {
        double total = 0;
        os << "Product No      Cost Taxable" << std::endl;
        for (int i = 0; i < m_saleProducts.size(); i++)
        {
            os << *m_saleProducts[i] << std::endl;
            total += m_saleProducts[i]->getCharge();
        }
        os.setf(std::ios::fixed);
        os.setf(std::ios::right);
        os.width(10);
        os << "Total";
        os.width(10);
        os << total << std::endl;
    }
}