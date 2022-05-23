#pragma once
#include "line.h"

struct train{
    double mass;
    int id;
    bool direction;
    station* current_station;
    line course;
    int timeout; // для определения, в пути ли поезд
    int key; //для определения времени прогонки (макс/мин)
    
    train(int id_, double mass_);
    ~train();
};

struct t_table{

    void add_train(train* cho, line course_, station* curr_station);
    void showcase();
    void move_train_left(train* cho);
    void move_train_right(train* cho);
    std::vector<line> courses;
    std::vector<train*> trains;
    int hour;
    t_table();
    ~t_table();
    
};