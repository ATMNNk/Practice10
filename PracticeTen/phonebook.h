// Файл: phonebook.h
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

    // Геттери
    std::string getName() const;
    std::string getAddress() const;
    std::string getPhoneNumber() const;

    // Сеттери
    void setName(const std::string& name);
    void setAddress(const std::string& address);
    void setPhoneNumber(const std::string& phoneNumber);
};

class Phonebook {
private:
    std::vector<PhonebookEntry> entries;

public:
    // Конструктори
    Phonebook();
    Phonebook(const std::vector<PhonebookEntry>& entries);

    // Додавання об'єктів
    void addEntry(const PhonebookEntry& entry);

    // Видалення об'єктів
    void removeEntry(const std::string& name);

    // Виведення інформації на екран
    void displayEntries() const;

    // Пошук за іменем
    PhonebookEntry searchByName(const std::string& name) const;

    // Редагування записів
    void editEntry(const std::string& name, const PhonebookEntry& newEntry);

    // Сортування за різними полями
    void sortByName();
    void sortByAddress();
    void sortByPhoneNumber();
};

#endif  // PHONEBOOK_H
