#include <iostream>
#include "station.h"

int main()
{
    station uno = station(1,"yeet", 10.5);
    //int k = yep.get_id() + 1;
    station due = station(uno.get_id() + 1, "skeet", 45);
    
    {
        using namespace std;
        cout << (uno == due) << "\n";
        due.set_trf(258);
        cout << due.get_trf() << "\n";
    } 
}