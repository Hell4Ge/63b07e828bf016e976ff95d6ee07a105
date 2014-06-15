// Klasyczny algorytm mrówkowy v.1.1.0
// ostatnia aktualizacja 2011-04-25
// CopyLeft Feliks Kurp 2011
#include <cstdlib>
#include <iostream>
#include "world.h"
#include "mrowisko.h"

// #include <fstream>

#include "globalSettings.h"
#include "globaldata.h"

// ========= BENCHMARK FILES =========
#include <ctime>
// ========== C++11 SECTION ==========
// ===================================
#include <ratio>    // C++11 Feature - remove if neccessary
#include <chrono>   // C++11 Feature - remove if neccessary
// ===================================
// ===================================

using namespace std;

// inicjacja œwiata
const int lp=7;    // liczba punktów œwiata
int tabela[3][lp]={'a','b','c','d','e','f','g',
                    6, 13,  4,  4,  8,  6,  10,
                    1,  1,  3,  5,  5,  8,  8}; 
void inicjuj(World swiat); // inicjuje konkretny œwiat

int main(int argc, char *argv[])
{
        globalData GD;  // Global Data class, container for data & i/o operations
        World swiat(gs_map_points,'a',gs_foodOrder[0],gs_pathselect_points);
        // parametry œwiata: liczba punktów, home, food,
        //                   liczba punktów wyboru dla mrówek

        for(unsigned int at=0; at<gs_attempts; at++)
        {
            // ========== C++11 SECTION ==========
            // ===================================
            auto c1 = std::chrono::high_resolution_clock::now();
            // ===================================
            // ===================================

            inicjuj(swiat); // inicjacja œwiata wartoœciami
            Mrowisko m(&swiat,gs_ants,gs_fers); // parametry mrowiska: nazwa œwiata,
            // liczba mrówek, iloœæ pozostawianego feromonu przez mrówkê

            if(gs_printOnScreen) cout << "---------- stan poczatkowy\n";

            m.pokaz();                // mrowisko - stan pocz¹tkowy
            swiat.pokaz();

            if(gs_printOnScreen) cout<<endl;// œwiat    - stan pocz¹tkowy

            for(unsigned int i=1;i<=gs_cycles;i++){
                if(gs_printOnScreen) cout<<"---------- "<<i<<" cykl ----------\n";

                m.move(); m.pokaz();
                swiat.pokaz();

                if(gs_printOnScreen) cout<<endl;
                if(gs_decreaseFeroms) swiat.decreaseFeroms();
            }

            // ========== C++11 SECTION ==========
            // ====== remove if neccessary =======
            auto c2 = std::chrono::high_resolution_clock::now();
            float elapsedSeconds = std::chrono::duration_cast<std::chrono::milliseconds>(c2 - c1).count();
            // ===================================
            // ===================================

            if(gs_printBenchmarkTimes)
                cout << "Time: " << elapsedSeconds << " milliseconds" << endl;

            if(gs_gd_PrintAnts)
                GD.print('a', gs_gd_WriteCycles);

            if(gs_gd_PrintAntsSummed)
                GD.print('s', gs_gd_WriteCycles);

            if(gs_gd_PrintFeroms)
                GD.print('f', gs_gd_WriteCycles);

            if(gs_gd_WriteAnts)
                GD.write('a');

            if(gs_gd_WriteAntsSummed)
                GD.write('s');

            if(gs_gd_WriteFeroms)
                GD.write('f');

            m.reset();
            swiat.reset();
        }



        getchar();
        return 0;
}

void inicjuj(World swiat){
     for(int i=0;i<lp;i++)
         {swiat.punkty[i].name =tabela[0][i];
          swiat.punkty[i].x    =tabela[1][i];
          swiat.punkty[i].y    =tabela[2][i];
         } 
}

