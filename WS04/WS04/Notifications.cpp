///OOP345 Workshop 4: Containers 
// File: Notifications.cpp
// Version: 1.0
// Date: 2017/10/01
// Author: Galina Erostenko
// Description: Notifications Class Inmplementation File
///////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Notifications.h"

namespace w4 {
    Notifications::Notifications(){
        m_numOfMessages = 0;
        m_messages = new Message[MAXMESS];
    }
    Notifications::Notifications(const Notifications& src)
    {
        *this = src;
    }
    Notifications& Notifications::operator=(const Notifications& src)
    {
        if (this != &src) {
            delete[] m_messages;
                m_messages = new Message[MAXMESS];
                for (int i = 0; i < src.m_numOfMessages; i++)
                {
                    m_messages[i] = src.m_messages[i];
                }
                m_numOfMessages - src.m_numOfMessages;
        }
        return *this;
    }
    Notifications::Notifications(Notifications&& src) {
        m_messages = src.m_messages;
        m_numOfMessages = src.m_numOfMessages;
        src.m_numOfMessages = 0;
        src.m_messages = nullptr;
    }
    Notifications&& Notifications::operator=(Notifications&& src) {
        if (this != &src)
        {
            delete[] m_messages;
            m_messages = src.m_messages;
            m_numOfMessages = src.m_numOfMessages;
            src.m_messages = nullptr;
            src.m_numOfMessages = 0;
        }
        return std::move(*this);
    }
    Notifications::~Notifications() {
        delete[] m_messages;
        m_messages = nullptr;
    }
    void Notifications::operator+=(const Message& msg) {
        if (m_numOfMessages < 10)
        {
            m_messages[m_numOfMessages] = msg;
            m_numOfMessages++;
        }
    }
    void Notifications::display(std::ostream& os) const {


        for (int i = 0; i < m_numOfMessages; i++) {
            m_messages[i].display(os);
        }
        std::cout << std::endl;
    }

}