#ifndef GLOBAL_H
#define GLOBAL_H
#include "resultsheet.h"
// dunno what ima doing
// Map points
const int gs_map_points=7;  // do not change
const int gs_ants = 15;     // Ants on map
const int gs_fers = 3;      // Power of feromons / count per ant

const bool gs_decreaseFeroms = false;
const float gs_fer_reduction = 1.f;                 // 10%, set 1.0f to DO NOT reduce BASE feromons on the way
const float gs_fer_reduction_per_cycle = 0.f;     // percent reduction of feroms per cycle

// Patchfinding changes
const bool gs_return_home = false;       // Lab 2 Mod 1
const bool gs_use_roulette = true;      // A way to chose next point by ant (ruletka() / losowy())
const int gs_pathselect_points = 3;

// cycles & attempts
const unsigned int gs_cycles=10;
const unsigned int gs_attempts=1;

// WTF - Write To File
const bool gs_WriteFeroms = false;       // false - write number of ants in G point

#endif // GLOBAL_H
