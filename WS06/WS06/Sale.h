#ifndef SALE_H_
#define SALE_H_

// Workshop 6 - STL Containers
// Sale.h

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