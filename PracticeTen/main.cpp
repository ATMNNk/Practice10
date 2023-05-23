// Τΰιλ: main.cpp
#include "phonebook.h"
#include <iostream>

int getMenuChoice() {
    int choice;
    std::cout << "===== MENU =====" << std::endl;
    std::cout << "1. Add entry" << std::endl;
    std::cout << "2. Remove entry" << std::endl;
    std::cout << "3. Display entries" << std::endl;
    std::cout << "4. Search by name" << std::endl;
    std::cout << "5. Edit entry" << std::endl;
    std::cout << "6. Sort by name" << std::endl;
    std::cout << "7. Sort by address" << std::endl;
    std::cout << "8. Sort by phone number" << std::endl;
    std::cout << "9. Exit" << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    std::cout << std::endl;
    return choice;
}

int main() {
    Phonebook phonebook;
    int choice;

    do {
        choice = getMenuChoice();

        switch (choice) {
        case 1: {
            std::string name, address, phoneNumber;
            std::cout << "Enter name: ";
            std::cin >> name;
            std::cout << "Enter address: ";
            std::cin >> address;
            std::cout << "Enter phone number: ";
            std::cin >> phoneNumber;

            PhonebookEntry entry(name, address, phoneNumber);
            phonebook.addEntry(entry);

            std::cout << "Entry added successfully!" << std::endl;
            std::cout << std::endl;
            break;
        }
        case 2: {
            std::string name;
            std::cout << "Enter name to remove: ";
            std::cin >> name;

            phonebook.removeEntry(name);

            std::cout << "Entry removed successfully!" << std::endl;
            std::cout << std::endl;
            break;
        }
        case 3: {
            phonebook.displayEntries();
            break;
        }
        case 4: {
            std::string name;
            std::cout << "Enter name to search: ";
            std::cin >> name;

            PhonebookEntry entry = phonebook.searchByName(name);

            if (!entry.getName().empty()) {
                std::cout << "Entry found:" << std::endl;
                std::cout << "Name: " << entry.getName() << std::endl;
                std::cout << "Address: " << entry.getAddress() << std::endl;
                std::cout << "Phone number: " << entry.getPhoneNumber() << std::endl;
            }
            else {
                std::cout << "Entry not found!" << std::endl;
            }
            std::cout << std::endl;
            break;
        }
        case 5: {
            std::string name, newName, newAddress, newPhoneNumber;
            std::cout << "Enter name to edit: ";
            std::cin >> name;
            std::cout << "Enter new name: ";
            std::cin >> newName;
            std::cout << "Enter new address: ";
            std::cin >> newAddress;
            std::cout << "Enter new phone number: ";
            std::cin >> newPhoneNumber;

            PhonebookEntry newEntry(newName, newAddress, newPhoneNumber);
            phonebook.editEntry(name, newEntry);

            std::cout << "Entry edited successfully!" << std::endl;
            std::cout << std::endl;
            break;
        }
        case 6: {
            phonebook.sortByName();
            std::cout << "Phonebook sorted by name!" << std::endl;
            std::cout << std::endl;
            break;
        }
        case 7: {
            phonebook.sortByAddress();
            std::cout << "Phonebook sorted by address!" << std::endl;
            std::cout << std::endl;
            break;
        }
        case 8: {
            phonebook.sortByPhoneNumber();
            std::cout << "Phonebook sorted by phone number!" << std::endl;
            std::cout << std::endl;
            break;
        }
        case 9: {
            std::cout << "Exiting program..." << std::endl;
            break;
        }
        default: {
            std::cout << "Invalid choice! Please try again." << std::endl;
            std::cout << std::endl;
            break;
        }
        }
    } while (choice != 9);

    return 0;
}
