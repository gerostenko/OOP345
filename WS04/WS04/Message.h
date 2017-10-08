///OOP345 Workshop 4: Containers 
// File: Message.h
// Version: 1.0
// Date: 2017/10/01
// Author: Galina Erostenko
// Description: Message Class Header File
///////////////////////////////////////////////////

#ifndef W4_MESSAGE_H__
#define W4_MESSAGE_H__

namespace w4 {
    class Message {
        std::string username;
        std::string reply;
        std::string tweet;
        void setEmpty();
        void setStrings(std::string str);

    public:
        Message(); //default constructor
        Message(std::ifstream& in, char c); //constructor to read from file
        bool empty() const; //returns true if strings are empty
        void display(std::ostream& os) const; //display Message object
    };
}
#endif