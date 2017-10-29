// Workshop 5 - Lambda Expression
// w5.cpp

#include <iostream>
#include "Grades.h"
#include<cmath>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << argv[0] <<
            ": incorrect number of arguments\n";
        std::cerr << "Usage: " << argv[0] << " file_name\n";
        return 1;
    }
    // define the lambda expression for letter
    auto letter = [](double studGrade) -> std::string {
        std::string gradeLetter;
        int grade = round(studGrade);

        if ((grade >= 90) && (grade <= 100))
            gradeLetter = "A+";
        else if ((grade >= 80) && (grade <= 89))
            gradeLetter = "A";
        else if ((grade >= 75) && (grade <= 79))
            gradeLetter = "B+";
        else if ((grade >= 70) && (grade <= 74))
            gradeLetter = "B";
        else if ((grade >= 65) && (grade <= 69))
            gradeLetter = "C+";
        else if ((grade >= 60) && (grade <= 64))
            gradeLetter = "C";
        else if ((grade >= 55) && (grade <= 59))
            gradeLetter = "D+";
        else if ((grade >= 50) && (grade <= 54))
            gradeLetter = "D";
        else
            gradeLetter = "F";

        return gradeLetter;
    };

    try {
        w5::Grades grades(argv[1]);

    grades.displayGrades(std::cout, letter);
    }
    catch (const char* msg) {
        std::cout << msg << std::endl;
    }

    std::cout << "Press any key to continue ... ";
    std::cin.get();
}