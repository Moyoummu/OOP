#include <string>

struct station{
    const int& get_id() const;
    const std::string& get_name() const;
    const double& get_trf() const;
    void set_trf(double trf_);
    
    station(int id_, std::string name_, double trf_);
    station(int id_, std::string name_);
    ~station();
   
    bool operator <(const station &rhs) const;
    bool operator ==(const station &rhs) const;
    
    private: 
        int id;
        std::string name;
        double cur_traffic;
};