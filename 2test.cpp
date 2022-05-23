#include <assert.h>
#include <iostream>
#include <stdlib.h>

#include "graph.h"

void moving_trains(t_table* table){
    for(table->hour; table->hour < 24; ++table->hour)
    {
        table->showcase();
        
        for(std::vector<train*>::iterator it = table->trains.begin(); it != table->trains.end(); ++it){
            if ((*it)->direction == 1){
                if ((*it)->current_station->get_id() == (*it)->course.get_number_st() - 1){ std::cout << "Already at the end of the line\n\n"; return; }
                 // двигаемся вправо
                if ((*it)->key){ // случай максимального времени перегонки
                    if ((*it)->timeout == -1){ // поезд только отправился со станции
                        std::list<station*>::iterator next = (*it)->course.Line.begin();
                        advance(next,(*it)->current_station->get_id() + 1);
                        int max = (*it)->course.calc_max((*it)->current_station->get_name(), (*next)->get_name());
                        (*it)->timeout = max;
                    }
                    --(*it)->timeout;
                    if ((*it)->timeout == 0){
                        table->move_train_right(*it);
                        (*it)->timeout = -1;
                        (*it)->key = rand() % 2; //сдвинулись на одну станцию и вновь зарандомили время прогонки
                    }
                }
                else{        //случай минимального времени перегонки
                    if ((*it)->timeout == -1){
                        std::list<station*>::iterator next = (*it)->course.Line.begin();
                        advance(next,(*it)->current_station->get_id() + 1);
                        int min = (*it)->course.calc_min((*it)->current_station->get_name(), (*next)->get_name());
                        (*it)->timeout = min;
                    }
                    --(*it)->timeout;
                    if ((*it)->timeout == 0){
                        table->move_train_right(*it);
                        (*it)->timeout = -1;
                        (*it)->key = rand() % 2;
                    }
                }
            }
            else{
                if ((*it)->current_station->get_id() == 0){ std::cout << "Already at the end of the line\n\n"; return; }
                    //двигаемся влево
                if ((*it)->key){ // случай максимального времени перегонки
                    if ((*it)->timeout == -1){ 
                        std::list<station*>::iterator next = (*it)->course.Line.begin();
                        advance(next,(*it)->current_station->get_id() - 1);
                        int max = (*it)->course.calc_max((*it)->current_station->get_name(), (*next)->get_name());
                        (*it)->timeout = max;
                    }
                    --(*it)->timeout;
                    if ((*it)->timeout == 0){
                        table->move_train_left(*it);
                        (*it)->timeout = -1;
                        (*it)->key = rand() % 2; 
                    }
                }
                else{        //случай минимального времени перегонки
                    if ((*it)->timeout == -1){
                        std::list<station*>::iterator next = (*it)->course.Line.begin();
                        advance(next,(*it)->current_station->get_id() - 1);
                        int min = (*it)->course.calc_min((*it)->current_station->get_name(), (*next)->get_name());
                        (*it)->timeout = min;
                    }
                    --(*it)->timeout;
                    if ((*it)->timeout == 0){
                        table->move_train_left(*it);
                        (*it)->timeout = -1;
                        (*it)->key = rand() % 2;
                    }
                }
            }
        }
    }
}

void graph_test(){
    using namespace std;
    
    t_table table = t_table();
    line pervaya = line();
    table.courses.push_back(pervaya);
    
    station* uno = new station(0, "yeet");
    station* due = new station(uno->get_id() + 1, "skeet");
    pervaya.add_first_station(uno);
    pervaya.add_station_stretch(due, 1, 2);
    
    train* chich1 = new train(1, 58.9);
    chich1->direction = rand() % 2;
    chich1->key = rand() % 2; //первое время прогонки (max/int)
    table.add_train(chich1, pervaya, *(pervaya.Line.begin()));
    
    table.showcase();
    //std::list<station*>::iterator next = chich1->course.Line.begin();
    //advance(next, 1);
    //cout << (*next)->get_name();
    t_table *dyn_table = &table;
    //cout << pervaya.get_number_st();
    moving_trains(dyn_table);
}

void line_test(){
    using namespace std;
    station* uno = new station(0, "yeet", 10.5);
    station* due = new station(uno->get_id() + 1, "skeet", 45);
    line pervaya = line();
    pervaya.add_first_station(uno);
    list<station*>::iterator it = pervaya.Line.begin(); 
    pervaya.add_station_stretch(due, 1, 2);
    for (it; it != pervaya.Line.end(); ++it){
        cout << (*it)->get_name() << endl;
    }
    list<stretch*>::iterator it_2 = pervaya.stretches.begin();
    cout << (*it_2)->get_left().get_name() << endl;
    assert((*it_2)->get_left().get_name() == "yeet");
    cout << pervaya.calc_min("skeet", "skeet") << endl;
    assert(pervaya.calc_min("yeet", "skeet") == 1);
    cout << endl;
}

void transfer_test(){
    using namespace std;
    transfer uno = transfer(0, "pep");
    uno.add_trans("Kievskaya");
    cout << uno.get_trans()[0] << endl;
    uno.add_trans("Strogino");
    for (int i = 0; uno.get_trans()[i] <= uno.get_trans().back(); ++i)
        cout << i << "   " << uno.get_trans()[i] << endl;
    assert(uno.get_trans()[1] == "Strogino");
}

void stretch_test(){
    using namespace std;
    station uno = station(1,"yeet", 10.5);
    station due = station(uno.get_id() + 1, "skeet", 45);
    stretch k_s = stretch(uno, due, 1, 2);
    cout << k_s.get_min_t() << endl;
    assert(k_s.get_max_t() == 2);
    cout << endl;
}

int main()
{
    graph_test();
    line_test();
    stretch_test();
    transfer_test();


    return 0;
}

