#define _CRT_SECURE_NO_WARNINGS
#include "Publication.h"

#include <cstring>
#include <iostream>

#include "Date.h"
using namespace std;

namespace sdds {
Publication::Publication() {
    m_title = nullptr;
    m_shelfId[0] = '\0';
    m_membership = 0;
    m_libRef = -1;
    m_date.resetToToday();
}
Publication::Publication(const Publication& pb) {
    operator=(pb);
}
Publication& Publication::operator=(const Publication& pb) {
    if (this != &pb) {
        set(pb.m_membership);
        setRef(pb.m_libRef);
        resetDate();
        setTitle(pb.m_title);
        setShelfId(pb.m_shelfId);
    }
    return *this;
}
Publication::~Publication() {
    delete[] m_title;
}
// Modifiers
void Publication::set(int member_id) {
    // if (member_id) {
    m_membership = member_id;
    // } else {
    //     m_membership = 0;
    // }
}
void Publication::setRef(int value) {
    m_libRef = value;
}
void Publication::resetDate() {
    return m_date.resetToToday();
}
// New added //
void Publication::setTitle(const char* title) {
    delete[] m_title;
    m_title = new char[strlen(title) + 1];
    strcpy(m_title, title);
}
void Publication::setShelfId(const char shelfId[]) {
    // if (shelfId) {
    strncpy(m_shelfId, shelfId, SDDS_SHELF_ID_LEN);
    // }
    // if (strlen(shelfId) >= SDDS_SHELF_ID_LEN) {
    //     m_shelfId[SDDS_SHELF_ID_LEN] = '\0';
    // }
}
// Queries
char Publication::type() const {
    return 'P';
}
bool Publication::onLoan() const {
    return m_membership;
}
Date Publication::checkoutDate() const {
    return m_date;
}
bool Publication::operator==(const char* title) const {
    return strstr(title, "Star");  //
}
Publication::operator const char*() const {
    return m_title;
}
int Publication::getRef() const {
    return m_libRef;
}
// New added
const char* Publication::getTitle() const {
    return m_title;
}
const char* Publication::getSheifId() const {
    return m_shelfId;
}
int Publication::getMembership() const {
    return m_membership;
}
}  // namespace sdds