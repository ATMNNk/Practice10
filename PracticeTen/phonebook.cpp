// Файл: phonebook.cpp
#include "phonebook.h"
#include <iostream>
#include <algorithm>

// Конструктор за замовчуванням
PhonebookEntry::PhonebookEntry() {
}

// Конструктор з параметрами
PhonebookEntry::PhonebookEntry(const std::string& name, const std::string& address, const std::string& phoneNumber) {
    this->name = name;
    this->address = address;
    this->phoneNumber = phoneNumber;
}

// Геттери
std::string PhonebookEntry::getName() const {
    return name;
}

std::string PhonebookEntry::getAddress() const {
    return address;
}

std::string PhonebookEntry::getPhoneNumber() const {
    return phoneNumber;
}

// Сеттери
void PhonebookEntry::setName(const std::string& name) {
    this->name = name;
}

void PhonebookEntry::setAddress(const std::string& address) {
    this->address = address;
}

void PhonebookEntry::setPhoneNumber(const std::string& phoneNumber) {
    this->phoneNumber = phoneNumber;
}

// Конструктор за замовчуванням
Phonebook::Phonebook() {
}

// Конструктор з параметрами
Phonebook::Phonebook(const std::vector<PhonebookEntry>& entries) {
    this->entries = entries;
}

// Додавання об'єктів
void Phonebook::addEntry(const PhonebookEntry& entry) {
    entries.push_back(entry);
}

// Видалення об'єктів за іменем
void Phonebook::removeEntry(const std::string& name) {
    entries.erase(std::remove_if(entries.begin(), entries.end(), [&](const PhonebookEntry& entry) {
        return entry.getName() == name;
        }), entries.end());
}

// Виведення інформації на екран
void Phonebook::displayEntries() const {
    for (const PhonebookEntry& entry : entries) {
        std::cout << "Name: " << entry.getName() << std::endl;
        std::cout << "Address: " << entry.getAddress() << std::endl;
        std::cout << "Phone number: " << entry.getPhoneNumber() << std::endl;
        std::cout << std::endl;
    }
}

// Пошук за іменем
PhonebookEntry Phonebook::searchByName(const std::string& name) const {
    for (const PhonebookEntry& entry : entries) {
        if (entry.getName() == name) {
            return entry;
        }
    }
    return PhonebookEntry();  // Повертаємо порожній об'єкт, якщо не знайдено
}

// Редагування запису за іменем
void Phonebook::editEntry(const std::string& name, const PhonebookEntry& newEntry) {
    for (PhonebookEntry& entry : entries) {
        if (entry.getName() == name) {
            entry = newEntry;
            return;
        }
    }
}

// Сортування за іменем
void Phonebook::sortByName() {
    std::sort(entries.begin(), entries.end(), [](const PhonebookEntry& a, const PhonebookEntry& b) {
        return a.getName() < b.getName();
        });
}

// Сортування за адресою
void Phonebook::sortByAddress() {
    std::sort(entries.begin(), entries.end(), [](const PhonebookEntry& a, const PhonebookEntry& b) {
        return a.getAddress() < b.getAddress();
        });
}

// Сортування за номером телефону
void Phonebook::sortByPhoneNumber() {
    std::sort(entries.begin(), entries.end(), [](const PhonebookEntry& a, const PhonebookEntry& b) {
        return a.getPhoneNumber() < b.getPhoneNumber();
        });
}
