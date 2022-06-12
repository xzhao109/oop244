#ifndef SDDS_CLEANERBOT_H
#define SDDS_CLEANERBOT_H
#define DEBUG

namespace sdds
{
    class CleanerBot
    {
    private:
        char* m_location{};
        double m_battery{};
        int m_brush{};
        bool m_active{};

    public:
        CleanerBot();
        CleanerBot(const char* location,
                   double battery,
                   int brush,
                   bool active);
        ~CleanerBot();

        // helper functions
        void setEmpty();   // diy
        void deallocate(); // diy

        // setterfunctions
        CleanerBot& set(const char* location,
                        double battery,
                        int brush,
                        bool active);
        CleanerBot& setLocation(const char* location);
        CleanerBot& setActive(bool active);

        // getter functions
        const char* getLocation() const;
        double getBattery() const;
        int getBrush() const;
        bool isActive() const;

        // helpe rfunctions
        bool isValid() const;
        void display() const;
    };

    // Global (stand-alone) functions
    int displayChart(CleanerBot* bot, short num_bots); // diy
    void sort(CleanerBot* bot, short num_bots);        // diy
    int report(CleanerBot* bot, short num_bots);
}

#endif