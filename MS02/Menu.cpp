/////////////////////////////////////////////////////////
// Milestone  :  2
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZAA
// Date       :  July 20
/////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"

#include <cstring>
#include <iostream>

using namespace std;
namespace sdds {
void MenuItem::setEmpty() {
    m_content = nullptr;
}
MenuItem::MenuItem() {
    setEmpty();
}
MenuItem::MenuItem(const char* content) {
    setContent(content);
}
MenuItem& MenuItem::setContent(const char* content) {
    setEmpty();
    if (content && content[0]) {
        m_content = new char[strlen(content) + 1];
        strcpy(m_content, content);
    } else {
        setEmpty();
    }
    return *this;
}
MenuItem::~MenuItem() {
    delete[] m_content;
}
MenuItem::operator bool() const {
    return m_content != nullptr;
}

//  Menu class

void Menu::setEmpty() {
    m_title = nullptr;
    m_size = 0;
}
Menu::Menu() {
    setEmpty();
}
Menu::Menu(const char* title) {
    setTitle(title);
}
Menu& Menu::setTitle(const char* title) {
    delete[] m_title;
    if (title && title[0]) {
        m_title = new char[strlen(title) + 1];
        strcpy(m_title, title);
    } else {
        setEmpty();
    }
    return *this;
}
Menu::~Menu() {
    delete[] m_title;
    for (int i{0}; i < m_size; i++) {
        delete m_item[i];
    }
}
Menu::operator bool() const {
    return m_title != nullptr;
}
Menu& Menu::operator<<(const char* menuitemConent) {
    if (!m_item[m_size] && m_size < MAX_MENU_ITEMS) {
        m_item[m_size] = new MenuItem(menuitemConent);
    }
    ++m_size;
    return *this;
}
Menu::operator unsigned int() const {
    return m_size;
}
std::ostream& Menu::displayTitle(std::ostream& os) const {
    if (m_title != nullptr) {
        os << m_title;
    }
    return os;
}
std::ostream& Menu::display(std::ostream& os) const {
    if (m_title != nullptr) {
        os << m_title << '\n';
    }
    for (int i{0}; i < m_size; i++) {
        os << " " << i + 1 << "- " << m_item[i]->m_content << '\n';
    }
    os << " 0- Exit\n"
       << "> ";
    return os;
}
int Menu::run() const {
    display();
    while (true) {
        int num{};
        cin >> num;
        if (cin && num >= 0 && num <= m_size) {
            return num;
        } else {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid Selection, try again: ";
        }
    }
}
char* Menu::operator[](int index) const {
    return m_item[index]->m_content;
}
int Menu::operator~() const {
    display();
    while (true) {
        int num{};
        cin >> num;
        if (cin && num >= 0 && num <= m_size) {
            return num;
        } else {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid Selection, try again: ";
        }
    }
}
std::ostream& operator<<(std::ostream& os, const Menu& menu) {
    return menu.displayTitle(os);
}

}  // namespace sdds