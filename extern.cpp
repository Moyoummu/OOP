#include<cstring>
#include "extern.h"

const int& station::get_id() const { return id; }
const std::string& station::get_name() const { return name; }
const double& station::get_trf() const { return cur_traffic; }
void station::set_trf(double trf_) { this->cur_traffic = trf_; }

station::station(int id_, std::string name_, double trf_) : id(id_), name(name_), cur_traffic(trf_){}
station::station(int id_, std::string name_) : id(id_), name(name_){ cur_traffic = 0; }
station::~station(){}

bool station::operator <(const station &rhs) const{ return this->get_id() < rhs.get_id(); }
bool station::operator ==(const station &rhs) const{ return this->get_id() == rhs.get_id(); }

extern "C"{
    station *create_station(int id_, char* name_, double trf_){
        return new station(id_, name_, trf_);
    }

    void destroy_station(station *p){
        delete p;
    }

    int get_id(station *p){
        return p->get_id();
    }

    void get_name(station *p, char* name, int name_length){
        strncpy(name, p->get_name().c_str(), name_length);

    }

    double get_traffic(station *p){
        return p->get_trf();
    }


    void set_traffic(station *p, double traffic){
        p->set_trf(traffic);
    }

}