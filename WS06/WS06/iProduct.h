#ifndef _I_PRODUCT_H_
#define _I_PRODUCT_H_

// Workshop 6 - STL Containers
// iProduct.h

#include<iostream>
#include<fstream>
#include<string>
#include<utility>

namespace w6 {
    typedef std::pair<std::string, double> my_pair;

    class iProduct {
    public:
        virtual double getCharge() const = 0;
        virtual void display(std::ostream& os) const = 0;
    };

    std::ostream& operator<<(std::ostream&, const iProduct&);
    iProduct* readProduct(std::ifstream&);



    class Product : public iProduct {
    private:
        std::string m_productID;
        double m_cost;
    public:
        Product(std::string productID, double cost);
        virtual double getCharge() const;
        virtual void display(std::ostream& os) const;
    };
    class TaxableProduct : public Product {
    private:
        //I don't understand why use array here, sorry
        std::pair <w6::my_pair, w6::my_pair> m_taxStatus {{ "HST", 0.13 }, { "PST", 0.08 }};
        std::string m_status;
    public:
        TaxableProduct(std::string name, double cost, std::string status);
        virtual double getCharge() const;
        virtual void display(std::ostream& os) const;
    };

}
#endif