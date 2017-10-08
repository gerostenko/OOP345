///OOP345 Workshop 5: Lambda Expression 
// File: Grades.h
// Version: 1.0
// Date: 2017/10/08
// Author: Galina Erostenko
// Description: Grades Class Header File
///////////////////////////////////////////////////

#ifndef W5_GRADES_H__
#define W5_GRADES_H__
#include<string>

namespace w5 {
    class Grades {
        std::string *studentId;
        double *studGrades;
        int numStud;
    public:
        Grades() : studentId(nullptr), studGrades(nullptr), numStud(0) {} 
        Grades(const char *fileName);
        Grades(const Grades&) = delete;
        Grades(const Grades&&) = delete;
        Grades& operator=(const Grades&) = delete;
        Grades&& operator=(const Grades&&) = delete;
        ~Grades();
        template <typename T>
        void displayGrades(std::ostream& os, T func) const {
            for (int i = 0; i < numStud; i++)
            {
                os << studentId[i] << " ";
                os.setf(std::ios::fixed);
                os.precision(2);
                os << studGrades[i] << " ";
                os.unsetf(std::ios::fixed);
                os.precision(6);
                os << func(studGrades[i]) << std::endl;
            }
        }
    };

}
#endif