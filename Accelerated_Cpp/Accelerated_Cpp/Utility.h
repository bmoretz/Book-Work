#pragma once

#include <algorithm>
#include <vector>
#include <stdexcept>

using std::vector; using std::domain_error;

template<typename T>
T median( vector<T> vals );