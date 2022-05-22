#include <iostream>
#include <assert.h>

#include "station.h"

void test_station()
{
    station uno = station(1,"yeet", 10.5);
    station due = station(uno.get_id() + 1, "skeet", 45);
    station tre = station(3, "meat");
    
    {
        using namespace std;
        assert((uno == due) == 0);
        cout << (uno == due) << "\n";
        
        due.set_trf(258);
        assert(due.get_trf() == 258);
        cout << due.get_trf() << "\n";

        assert(tre.get_trf() == 0);
        cout << tre.get_trf() << "\n";
    }
}

int main()
{
    test_station();        
}