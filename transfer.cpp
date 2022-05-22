#include "transfer.h"

transfer::transfer(int id_, std::string name_):station(id_, name_){ trans_names.clear(); }
transfer::transfer(int id_, std::string name_, double trf_, std::vector<std::string> trfs_): station(id_, name_, trf_), trans_names(trfs_){}
transfer::~transfer(){}

const std::vector<std::string>& transfer::get_trans() const{ return trans_names; }
void transfer::add_trans(std::string names_){ trans_names.push_back(names_); }