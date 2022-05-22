#include <string>

struct station{
    int get_id() const;
    std::string get_name() const;
    double get_trf() const;
    void set_trf(double trf_);
    
    station(int id_, std::string name_, double trf_);
    ~station();
   
    bool operator <(const station &rhs) const;
    bool operator ==(const station &rhs) const;
    private: 
        int id;
        std::string name;
        double cur_traffic;
};