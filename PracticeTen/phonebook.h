// ����: phonebook.h
#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <vector>
#include <string>

class PhonebookEntry {
private:
    std::string name;
    std::string address;
    std::string phoneNumber;

public:
    PhonebookEntry();
    PhonebookEntry(const std::string& name, const std::string& address, const std::string& phoneNumber);

    // �������
    std::string getName() const;
    std::string getAddress() const;
    std::string getPhoneNumber() const;

    // �������
    void setName(const std::string& name);
    void setAddress(const std::string& address);
    void setPhoneNumber(const std::string& phoneNumber);
};

class Phonebook {
private:
    std::vector<PhonebookEntry> entries;

public:
    // ������������
    Phonebook();
    Phonebook(const std::vector<PhonebookEntry>& entries);

    // ��������� ��'����
    void addEntry(const PhonebookEntry& entry);

    // ��������� ��'����
    void removeEntry(const std::string& name);

    // ��������� ���������� �� �����
    void displayEntries() const;

    // ����� �� ������
    PhonebookEntry searchByName(const std::string& name) const;

    // ����������� ������
    void editEntry(const std::string& name, const PhonebookEntry& newEntry);

    // ���������� �� ������ ������
    void sortByName();
    void sortByAddress();
    void sortByPhoneNumber();
};

#endif  // PHONEBOOK_H
