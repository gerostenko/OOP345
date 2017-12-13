///OOP345 Workshop 7: STL Algorithms
// File: DataTable.h
// Version: 1.0
// Date: 2017/12/08
// Author: Galina Erostenko
// Description: DataTable template class file
///////////////////////////////////////////////////

#ifndef DATATABLE_H_
#define DATATABLE_H_


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <functional>
#include <cmath>
#include <algorithm>
#include <numeric>

namespace w8 {
    template <class T>
    class DataTable {
        int fieldWidth;
        int precision;
        std::vector <T> x;
        std::vector <T> y;

    public:
        DataTable(std::ifstream& file, int fw, int nd) : fieldWidth(fw), precision(nd)
        {
            T xNum = 0, yNum = 0;
            if (file.is_open())
            {
                while (!file.eof())
                {
                    file >> xNum >> yNum;
                    x.push_back(xNum);
                    y.push_back(yNum);
                }

            }
        }

        T mean() const {
            T result = std::accumulate(y.begin(), y.end(), T(0)) / y.size();

            return result;
        }
        T sigma() const {
            T meanValue = mean();
            T valuesSum = std::accumulate(y.begin(), y.end(), T(0), [&](T x, T y) {return x + (meanValue - y)*(meanValue - y); });
            T result = std::sqrt(valuesSum/(y.size() - 1));

            return result;
        }
        T median() const {
            std::vector<T> sorted = y;
            std::sort(sorted.begin(), sorted.end());
            T result = sorted[sorted.size() / 2];

            return result;
        }
        void regression(T& slope, T& y_intercept) const {
            T sumOfX = accumulate(x.begin(), x.end(), (T)0);
            T sumOfY = accumulate(y.begin(), y.end(), (T)0);
            T sumOfXY = std::inner_product(x.begin(), x.end(), y.begin(), (T)0);
            T sumOfX2 = accumulate(x.begin(), x.end(), (T)0,
                [](T a, T b) {return a + b * b; });

            slope = (x.size()*sumOfXY - sumOfX*sumOfY) / (x.size()*sumOfX2 - sumOfX*sumOfX);
            y_intercept = (sumOfY - slope*sumOfX) / x.size();
        }
        void display(std::ostream& os) const{
            os.setf(std::ios::fixed);
            os << std::setw(fieldWidth) << "x" << std::setw(fieldWidth) << "y" << std::endl;
            os.precision(precision);

            for (int i = 0; i < x.size(); i++)
            {
                os << std::setw(fieldWidth) << x[i] << std::setw(fieldWidth) << y[i] << std::endl;
            }
        }
    };
    template <typename T>
    std::ostream& operator<<(std::ostream& os, const DataTable<T>& obj)
    {
        obj.display(os);
        return os;
    }
}
#endif