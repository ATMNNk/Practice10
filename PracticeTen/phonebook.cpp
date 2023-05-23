// ����: phonebook.cpp
#include "phonebook.h"
#include <iostream>
#include <algorithm>

// ����������� �� �������������
PhonebookEntry::PhonebookEntry() {
}

// ����������� � �����������
PhonebookEntry::PhonebookEntry(const std::string& name, const std::string& address, const std::string& phoneNumber) {
    this->name = name;
    this->address = address;
    this->phoneNumber = phoneNumber;
}

// �������
std::string PhonebookEntry::getName() const {
    return name;
}

std::string PhonebookEntry::getAddress() const {
    return address;
}

std::string PhonebookEntry::getPhoneNumber() const {
    return phoneNumber;
}

// �������
void PhonebookEntry::setName(const std::string& name) {
    this->name = name;
}

void PhonebookEntry::setAddress(const std::string& address) {
    this->address = address;
}

void PhonebookEntry::setPhoneNumber(const std::string& phoneNumber) {
    this->phoneNumber = phoneNumber;
}

// ����������� �� �������������
Phonebook::Phonebook() {
}

// ����������� � �����������
Phonebook::Phonebook(const std::vector<PhonebookEntry>& entries) {
    this->entries = entries;
}

// ��������� ��'����
void Phonebook::addEntry(const PhonebookEntry& entry) {
    entries.push_back(entry);
}

// ��������� ��'���� �� ������
void Phonebook::removeEntry(const std::string& name) {
    entries.erase(std::remove_if(entries.begin(), entries.end(), [&](const PhonebookEntry& entry) {
        return entry.getName() == name;
        }), entries.end());
}

// ��������� ���������� �� �����
void Phonebook::displayEntries() const {
    for (const PhonebookEntry& entry : entries) {
        std::cout << "Name: " << entry.getName() << std::endl;
        std::cout << "Address: " << entry.getAddress() << std::endl;
        std::cout << "Phone number: " << entry.getPhoneNumber() << std::endl;
        std::cout << std::endl;
    }
}

// ����� �� ������
PhonebookEntry Phonebook::searchByName(const std::string& name) const {
    for (const PhonebookEntry& entry : entries) {
        if (entry.getName() == name) {
            return entry;
        }
    }
    return PhonebookEntry();  // ��������� ������� ��'���, ���� �� ��������
}

// ����������� ������ �� ������
void Phonebook::editEntry(const std::string& name, const PhonebookEntry& newEntry) {
    for (PhonebookEntry& entry : entries) {
        if (entry.getName() == name) {
            entry = newEntry;
            return;
        }
    }
}

// ���������� �� ������
void Phonebook::sortByName() {
    std::sort(entries.begin(), entries.end(), [](const PhonebookEntry& a, const PhonebookEntry& b) {
        return a.getName() < b.getName();
        });
}

// ���������� �� �������
void Phonebook::sortByAddress() {
    std::sort(entries.begin(), entries.end(), [](const PhonebookEntry& a, const PhonebookEntry& b) {
        return a.getAddress() < b.getAddress();
        });
}

// ���������� �� ������� ��������
void Phonebook::sortByPhoneNumber() {
    std::sort(entries.begin(), entries.end(), [](const PhonebookEntry& a, const PhonebookEntry& b) {
        return a.getPhoneNumber() < b.getPhoneNumber();
        });
}
