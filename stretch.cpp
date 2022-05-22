#include "stretch.h"

const station& stretch::get_left() const { return left; }
const station& stretch::get_right() const { return right; }
const int& stretch::get_min_t() const { return t_min; }
const int& stretch::get_max_t() const { return t_max; }

stretch::stretch(station left_, station right_, int t_min_, int t_max_):left(left_), right(right_), t_min(t_min_), t_max(t_max_){};
stretch::~stretch(){}