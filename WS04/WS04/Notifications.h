///OOP345 Workshop 4: Containers 
// File: Notifications.h
// Version: 1.0
// Date: 2017/10/01
// Author: Galina Erostenko
// Description: Notifications Class Header File
///////////////////////////////////////////////////

#ifndef W4_NOTIFICATIONS_H__
#define W4_NOTIFICATIONS_H__
#include "Message.h"
#define MAXMESS 10

namespace w4 {
    class Notifications {
        Message *m_messages;
        int m_numOfMessages;
    public:
        Notifications();//default constructor - empty
        Notifications(const Notifications& src); // copy constructor
        Notifications& operator=(const Notifications& src); //copy assignment operator
        Notifications(Notifications&& src); // move constructor
        Notifications&& operator=(Notifications&& src); // move assignment operator
        ~Notifications(); // destructor
        void operator+=(const Message& msg); // adds msg to the set
        void display(std::ostream& os) const; // inserts the Message objects to the os output stream
    };
}
#endif