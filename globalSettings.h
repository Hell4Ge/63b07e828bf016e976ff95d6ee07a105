#ifndef GLOBAL_H
#define GLOBAL_H
#include "resultsheet.h"
// dunno what ima doing
// Map points
const int gs_map_points=7;  // do not change
const int gs_ants = 13;     // Ants on map
const int gs_fers = 3;      // Power of feromons / count per ant

const bool gs_decreaseFeroms = true;
//const float gs_fer_reduction = 1.f;               // 10%, set 1.0f to DO NOT reduce feromons on the way
const float gs_fer_reduction_per_cycle = 4.f;     // Value-based reduction (non-percent)

// Patchfinding changes
const bool gs_return_home = true;       // Lab 2 Mod 1
const bool gs_use_roulette = true;      // A way to chose next point by ant (ruletka() / losowy())
const int gs_pathselect_points = 3;

// cycles & attempts
const unsigned int gs_cycles=10;        // main cycle loop
const unsigned int gs_attempts=10;       // tests = gs_attempts * gs_cycles

// WTF - Write To File
const bool gs_WriteFeroms = true;       // false - write number of ants in G point

// WOS - Write On Screen
const bool gs_WriteOnScreen = true;
const bool gs_WriteBenchmarkTimes = true;   // C++11 ONLY!!!
                                            // By default every line of C11 code is commented (std::chrono + includes)

#endif // GLOBAL_H
