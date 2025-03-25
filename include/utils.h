#ifndef UTILS_H
#define UTILS_H

#include <SFML/Graphics.hpp>

float appr(float val, float target, float amount);
int sign(float x);
template<typename T>
T clamp(const T& x, const T& a, const T& b);
bool maybe();
bool solidAt(int x, int y, int w, int h);
bool iceAt(int x, int y, int w, int h);
bool spikesAt(int x, int y, int w, int h, sf::Vector2f velocity);

#endif