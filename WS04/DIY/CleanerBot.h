/////////////////////////////////////////////////////////
// WorkSho#4  :  Part 2
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZAA
// Date       :  Jun 12
/////////////////////////////////////////////////////////

#ifndef SDDS_CLEANERBOT_H
#define SDDS_CLEANERBOT_H

namespace sdds {
class CleanerBot {
   private:
    char* m_location{};
    double m_battery{};
    int m_brush{};
    bool m_active{};

   public:
    CleanerBot();
    CleanerBot(const char* location,
               const double battery = 0,
               const int brush = 0,
               const bool active = false);
    ~CleanerBot();

    // helper functions
    void setEmpty();
    void deallocate();

    // setterfunctions
    CleanerBot& set(const char* location,
                    double battery,
                    int brush,
                    bool active);
    CleanerBot& setLocation(const char* location);
    CleanerBot& setActive(const bool active);

    // getter functions
    const char* getLocation() const;
    double getBattery() const;
    int getBrush() const;
    bool isActive() const;

    // helper functions
    bool isValid() const;
    void display() const;
};

// Global (stand-alone) functions
void displayInfo(const CleanerBot bot[], const short num_bots);
int noOfLowBattery(const CleanerBot bot[], const short num_bots);
void sort(CleanerBot* bot, const short num_bots);
int report(CleanerBot* bot, const short num_bots);
}  // namespace sdds

#endif