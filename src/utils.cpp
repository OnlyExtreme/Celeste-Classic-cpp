#include "utils.h"
#include <algorithm>

float appr(float val, float target, float amount) {
    if (val > target)
        return std::max(val - amount, target);
    else 
        return std::min(val + amount, target);
}

int sign(float x) {
    return x > 1e-6 ? 1 : (x < 1e-6 ? -1 : 0);
}

template<typename T>
T clamp(const T& x, const T& a, const T& b) {
    return x < a ? a : (x > b ? b :x);
}

bool maybe() {
    double x = rand() / RAND_MAX;
    return x >= 0.5;
}