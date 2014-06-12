#ifndef GLOBALSETTINGS_H
#define GLOBALSETTINGS_H

// Map points
const int gs_map_points = 7;    // do not change
const int gs_ants = 13;         // Ants on map
const int gs_fers = 3;          // Power of feromons / count per ant

// GENERAL SETTINGS
const bool gs_printOnScreen         = false;
const bool gs_printBenchmarkTimes   = true;         // C++11 ONLY!!!

const bool  gs_decreaseFeroms = false;
const float gs_fer_reduction_per_cycle = 4.f;       // Value-based reduction (non-percent)

// Patchfinding changes
const bool gs_return_home = true;                  // Force ant to return to home after finding a snack
const bool gs_use_roulette = true;                  // A way to chose next point by ant (ruletka() / losowy())
const int  gs_pathselect_points = 3;

// Runtime
const unsigned int gs_cycles    = 10;                // main cycle loop
const unsigned int gs_attempts  = 10;                 // tests = gs_attempts * gs_cycles

// Global Data (GD) class settings : WRITE
const bool gd_gs_UseGDWrites        = true;
const bool gs_gd_WriteAnts          = false;
const bool gs_gd_WriteAntsSummed    = true;
const bool gs_gd_WriteFeroms        = false;

// Global Data (GD) class settings : PRINT
const bool gs_gd_UseGDPrints        = false;
const bool gs_gd_WriteCycles        = true;
const bool gs_gd_PrintAnts          = true;
const bool gs_gd_PrintAntsSummed    = true;
const bool gs_gd_PrintFeroms        = true;

#endif // GLOBALSETTINGS_H
