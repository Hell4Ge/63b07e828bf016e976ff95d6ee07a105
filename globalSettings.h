#ifndef GLOBALSETTINGS_H
#define GLOBALSETTINGS_H

// Map points
const int gs_map_points = 7;    // do not change that
const int gs_ants = 13;         // Ants on map
const int gs_fers = 5;          // Power of feromons

// GENERAL SETTINGS
const bool gs_printOnScreen         = true;
const bool gs_printBenchmarkTimes   = false;         // C++11 ONLY!!!

const bool  gs_decreaseFeroms = true;
const float gs_fer_reduction_per_cycle = 4.f;       // Value-based reduction (non-percent)

// Patchfinding changes
const bool gs_return_home = true;                   // Force ant to return to home after finding a snack
const bool gs_use_roulette = true;                  // A way to chose next point by ant (ruletka() / losowy())
const int  gs_pathselect_points = 3;

// Runtime
const unsigned int gs_cycles    = 10;                   // main cycle loop
const unsigned int gs_attempts  = 1;                    // tests = gs_attempts * gs_cycles

// Global Data (GD) class settings : WRITE
const bool gd_gs_UseGDWrites        = false;
const bool gs_gd_WriteAnts          = false;
const bool gs_gd_WriteAntsSummed    = false;
const bool gs_gd_WriteFeroms        = false;

// Global Data (GD) class settings : PRINT
const bool gs_gd_UseGDPrints        = false;
const bool gs_gd_WriteCycles        = false;
const bool gs_gd_PrintAnts          = false;
const bool gs_gd_PrintAntsSummed    = false;
const bool gs_gd_PrintFeroms        = false;


// Eating
const int gs_anthillPoints = 3;
const int gs_orderSize = 3;
const char gs_foodOrder[gs_orderSize] = {'g', 'e', 'f'};

#endif // GLOBALSETTINGS_H
