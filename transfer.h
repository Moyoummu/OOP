#include "station.h"
#include <vector>

struct transfer: station{
    const std::vector<std::string>& get_trans() const;
    void add_trans(std::string names_);
    
    transfer(int id_, std::string name_);
    transfer(int id_, std::string name_, double trf_, std::vector<std::string> trans_);
    ~transfer();
    
    private:
        std::vector<std::string> trans_names;
};