// Workshop 4 - Containers
// w4.cpp

#include <iostream>
#include <fstream>
#include "Message.h"
#include "Notifications.h"

const char REC_DELIMITER = '\n';

w4::Notifications collect(std::ifstream& in, char recDelim) {
    w4::Notifications notifications;
    do {
        w4::Message message(in, recDelim);
        if (!message.empty())
            notifications += std::move(message);
    } while (in);
    return notifications;
}

int main(int argc, char* argv[]) {
    if (argc == 1) {
        std::cerr << argv[0] << ": missing file operand\n";
        return 1;
    }
    else if (argc != 2) {
        std::cerr << argv[0] << ": too many arguments\n";
        return 2;
    }
    std::ifstream file(argv[1]);
    if (!file) {
        std::cerr << argv[0] << "\n: Failed to open " << argv[1] << "\n";
        return 3;
    }

    std::cout << "\nNotifications\n=============\n\n";
    w4::Notifications notifications = collect(file, REC_DELIMITER);

    notifications.display(std::cout);

    std::cout << "Press any key to continue ... ";
    std::cin.get();
}