#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include "iProduct.h"

namespace w6 {
    std::ostream& operator<<(std::ostream& os, const iProduct& obj) {
        obj.display(os);
        return os;
    }
    iProduct* readProduct(std::ifstream& fileStream)
    {
        iProduct* general = nullptr;
            std::string productID, status, str;
            double cost;

            std::getline(fileStream, str);

            std::string costString;
            size_t foundSpace = -1;
            size_t n = std::count(str.begin(), str.end(), ' ');

            if (n >= 1 && n <= 2)
            {
                foundSpace = str.find(' ');
                if (n == 1)
                {
                    productID = str.substr(0, foundSpace);
                    costString = str.substr(foundSpace, str.length() - 1);
                    general = new Product(productID, atof(costString.c_str()));
                }
                else
                {
                    if (str.at(str.length() - 1) == 'H' || str.at(str.length() - 1) == 'P')
                    {
                        productID = str.substr(0, foundSpace);
                        std::string left = str.substr(foundSpace + 1, str.length());
                        foundSpace = left.find(' ');
                        costString = left.substr(0, foundSpace);
                        status = left.at(left.length() - 1);
                        general = new TaxableProduct(productID, atof(costString.c_str()), status);
                    }
                }
            }
        
            return general;
    }
    Product::Product(std::string productID, double cost) {
        m_productID = productID;
        m_cost = cost;
    }
    double Product::getCharge() const {
        return m_cost;
    }
    void Product::display(std::ostream& os) const {
        os.width(10);
        os.setf(std::ios::fixed);
        os.precision(2);
        os << m_productID << " ";
        os.width(10);
        os.setf(std::ios::right);
        os << m_cost;
        os.unsetf(std::ios::fixed);
    }

    TaxableProduct::TaxableProduct(std::string name, double cost, std::string status) : Product(name, cost) {
        if (status == "H")
        {
            m_status = m_taxStatus.first.first;
        }
        else 
        {
            m_status = m_taxStatus.second.first;
        }

    }
    double TaxableProduct::getCharge() const {
        double tempCost = Product::getCharge();
        if (m_status == "HST")
        {
            tempCost = tempCost + (tempCost*m_taxStatus.first.second);
        }
        else
        {
            tempCost = tempCost + (tempCost*m_taxStatus.second.second);
        }
        return tempCost;
    }

    void TaxableProduct::display(std::ostream& os) const {
        Product::display(os);
        os << " " << m_status;

    }
}