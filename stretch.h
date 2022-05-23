#pragma once
#include "transfer.h"

struct stretch{
    const station& get_left() const;
    const station& get_right() const;
    const int& get_min_t() const;
    const int& get_max_t() const;

    stretch(station left_, station right_, int t_min_, int t_max_);
    ~stretch();
    
    private:
        int t_min;
        int t_max;
        station left;
        station right;
};