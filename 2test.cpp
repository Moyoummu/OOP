#include <assert.h>
#include <iostream>

#include "stretch.h"

void transfer_test(){
    using namespace std;
    transfer uno = transfer(0, "pep");
    uno.add_trans("Kievskaya");
    cout << uno.get_trans()[0] << endl;
    uno.add_trans("Strogino");
    for (int i = 0; uno.get_trans()[i] <= uno.get_trans().back(); i++)
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
}

int main()
{
    //std::cout << 'a';
    transfer_test();
    //std::cout << 'a';
    stretch_test();
    return 0;
}