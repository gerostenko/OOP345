///OOP345 Workshop 4: Containers 
// File: Message.cpp
// Version: 1.0
// Date: 2017/10/01
// Author: Galina Erostenko
// Description: Message Class Implementation File
///////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Message.h"
#include<fstream>
#include <string>

namespace w4 {
    Message::Message() {
        setEmpty();
    }
    Message::Message(std::ifstream& in, char c)
    {
       std::string line;
       std::getline(in, line, c);
       setStrings(line);
    }
    bool Message::empty() const {
        return (username.empty());
    }
    void Message::display(std::ostream& os) const
    {
        if (!empty()) {
            std::cout << "Message" << std::endl;
            os << "   User  : " << username << std::endl;
            if (!reply.empty()) {
                os << "   Reply : " << reply << std::endl;
            }
            os << "   Tweet : " << tweet << std::endl;
            std::cout << std::endl;

        }
    }

    //Private Function to set strings to empty state
    void Message::setEmpty()
    {
        username = "";
        reply = "";
        tweet = "";
    }
    //Private Function to set the strings
    void Message::setStrings(std::string str)
    {
        int foundReply = -1;
        int foundSpace = -1;
        foundSpace = str.find(' ');

        if ((foundSpace != 0) && (foundSpace != str.length() - 1) && (foundSpace != -1)) 
        {
            username = str.substr(0, foundSpace);
            str.erase(0, foundSpace + 1);

            foundSpace = -1;
            foundSpace = str.find(' ');
            foundReply = str.find('@');
            if ((foundSpace>0) && (foundReply<0)) {
                tweet = str.substr(0, str.length());
            }
            else if ((foundReply == 0) && (foundSpace < 0)) {
                setEmpty();
            }
            else if ((foundReply == 0) && (foundSpace > 0)) {
                reply = str.substr(1, foundSpace);
                tweet = str.substr(foundSpace + 1, str.length());
            }
        }
        else
        {
            setEmpty();
        }

    }
}