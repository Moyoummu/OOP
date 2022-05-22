#include <assert.h>
#include <iostream>

#include "line.h"

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
    line_test();
    stretch_test();
    transfer_test();
    return 0;
}