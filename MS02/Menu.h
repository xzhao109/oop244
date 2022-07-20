/////////////////////////////////////////////////////////
// Milestone  :  2
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZAA
// Date       :  July 20
/////////////////////////////////////////////////////////
#ifndef SDDS_MENU_H
#define SDDS_MENU_H
#include <iostream>

namespace sdds {
class Menu;
class MenuItem {
    char* m_content{};
    MenuItem();
    MenuItem(const char* content);
    MenuItem(const MenuItem& content) = delete;
    MenuItem& operator=(const MenuItem& content) = delete;
    ~MenuItem();

    void setEmpty();
    MenuItem& setContent(const char* content);
    operator bool() const;
    friend class Menu;
};

const int MAX_MENU_ITEMS = 20;
class Menu {
    char* m_title{};
    MenuItem* m_item[MAX_MENU_ITEMS]{};
    int m_size{};

   public:
    Menu();
    Menu(const char* title);
    Menu(const Menu& menu) = delete;
    Menu& operator=(const Menu& menu) = delete;
    ~Menu();

    void setEmpty();
    Menu& setTitle(const char* menu);
    std::ostream& displayTitle(std::ostream& os = std::cout) const;
    std::ostream& display(std::ostream& os = std::cout) const;
    int run() const;
    int operator~() const;
    Menu& operator<<(const char* menuitemConent);
    operator bool() const;
    operator unsigned int() const;
    char* operator[](int index) const;
};

std::ostream& operator<<(std::ostream& os, const Menu& menu);

}  // namespace sdds
#endif