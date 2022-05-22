#include "station.h"

const int& station::get_id() const { return id; }
const std::string& station::get_name() const { return name; }
const double& station::get_trf() const { return cur_traffic; }
void station::set_trf(double trf_) { this->cur_traffic = trf_; }

station::station(int id_, std::string name_, double trf_) : id(id_), name(name_), cur_traffic(trf_){}
station::station(int id_, std::string name_) : id(id_), name(name_){ cur_traffic = 0; }
station::~station(){}

bool station::operator <(const station &rhs) const{ return this->get_id() < rhs.get_id(); }
bool station::operator ==(const station &rhs) const{ return this->get_id() == rhs.get_id(); }