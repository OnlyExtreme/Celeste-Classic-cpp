#ifndef UTILS_H
#define UTILS_H

float appr(float val, float target, float amount);
int sign(float x);
template<typename T>
T clamp(const T& x, const T& a, const T& b);

#endif