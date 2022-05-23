#include "line.h"
#include <iostream>

void line::add_station_stretch(station* node, int t_min_, int t_max_){
    std::list<station*>::iterator it = this->Line.begin();
    std::advance(it, number_stat - 1);
    stretch* k = new stretch(*(*it), *node, t_min_, t_max_); 
    stretches.push_back(k);

    Line.push_back(node); 
    ++number_stat; 
}
void line::add_first_station(station* node){
    if (number_stat != 0){ std::cout << "use other method!\n"; return;}
    Line.push_back(node);
    ++number_stat;
}
const int& line::get_number_st() const { return number_stat; }

int line::calc_min(std::string lft, std::string rght){
     std::list<station*>::iterator it1 = this->Line.begin();
     std::list<station*>::iterator it2 = it1;
     int min_t = 0;
     int c = 0;
     if (lft == rght)
        return min_t;
     for (it1; it1 != this->Line.end(); ++it1){
         if ((*it1)->get_name() == lft){
            std::advance(it2, 1);
            std::list<stretch*>::iterator i_strch = this->stretches.begin();
            std::advance(i_strch, c);
            for(it2; it2 != this->Line.end(); ++it2)
            {
                min_t += (*i_strch)->get_min_t();
                if ((*it2)->get_name() == rght)
                    return min_t;
                ++i_strch;
            }
         }
         else if ((*it1)->get_name() == rght){
            std::advance(it2, 1);
            std::list<stretch*>::iterator i_strch = this->stretches.begin();
            std::advance(i_strch, c);
            for(it2; it2 != this->Line.end(); ++it2)
            {
                min_t += (*i_strch)->get_min_t();
                if ((*it2)->get_name() == lft)
                    return min_t;
                ++i_strch;
            }
         }

         }
         ++c;
        return 0;
}

int line::calc_max(std::string lft, std::string rght){
     std::list<station*>::iterator it1 = this->Line.begin();
     std::list<station*>::iterator it2 = it1;
     int max_t = 0;
     int c = 0;
     if (lft == rght)
        return max_t;
     for (it1; it1 != this->Line.end(); ++it1){
         if ((*it1)->get_name() == lft){
            std::advance(it2, 1);
            std::list<stretch*>::iterator i_strch = this->stretches.begin();
            std::advance(i_strch, c);
            for(it2; it2 != this->Line.end(); ++it2)
            {
                max_t += (*i_strch)->get_max_t();
                if ((*it2)->get_name() == rght)
                    return max_t;
                ++i_strch;
            }
         }
         else if ((*it1)->get_name() == rght){
            std::advance(it2, 1);
            std::list<stretch*>::iterator i_strch = this->stretches.begin();
            std::advance(i_strch, c);
            for(it2; it2 != this->Line.end(); ++it2)
            {
                max_t += (*i_strch)->get_max_t();
                if ((*it2)->get_name() == lft)
                    return max_t;
                ++i_strch;
            }
         }

         }
         ++c;
        return 0;
}

line::line(){ Line.clear(); number_stat = 0; stretches.clear(); }
line::~line(){}