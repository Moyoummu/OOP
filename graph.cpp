#include "graph.h"
#include <iostream>

train::train(int id_, double mass_):id(id_), mass(mass_), direction(0), current_station(nullptr), timeout(-1){}
train::~train(){}

t_table::t_table():hour(0){ trains.clear(); courses.clear(); }
t_table::~t_table(){}

void t_table::add_train(train* cho, line course_, station* curr_station){
    cho->current_station = curr_station;
    cho->course = course_;
    this->trains.push_back(cho);
}

void t_table::showcase(){
    using namespace std;
    for (std::vector<train*>::iterator it = this->trains.begin(); it != this->trains.end(); ++it){
        cout << "Train: " << (*it)->id << " | Station: " << (*it)->current_station->get_name() << (*it)->current_station->get_trf() << " | Time: " << this->hour << endl;
        cout << endl;     
    }
}

void t_table::move_train_left(train* cho){
    std::list<station*>::iterator next = cho->course.Line.begin();
    advance(next,cho->current_station->get_id() - 1);
    cho->current_station = *next;
}

void t_table::move_train_right(train* cho){
    std::list<station*>::iterator next = cho->course.Line.begin();
    advance(next,cho->current_station->get_id() + 1);
    cho->current_station = *next;
}