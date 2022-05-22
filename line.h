#include "stretch.h"
#include <list> 


struct line{
    std::list<station*> Line;
    std::list<stretch*> stretches; 
    void add_station_stretch(station* node, int t_min_, int t_max_);
    void add_first_station(station* node);
    int calc_min(std::string lft, std::string rght);
    int calc_max(std::string lft, std::string rght);
    const int& get_number_st() const;
    line();
    ~line();
    private:
        int number_stat;
};


