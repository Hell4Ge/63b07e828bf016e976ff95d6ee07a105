// Klasyczny algorytm mr�wkowy v.1.1.0
// ostatnia aktualizacja 2011-04-25
// CopyLeft Feliks Kurp 2011
#include <cstdlib>
#include <iostream>
#include "world.h"
#include "mrowisko.h"

#include "globalSettings.h"

#include <ctime>
#include <ratio>
#include <chrono>   // C++11 Feature

using namespace std;

// inicjacja �wiata
const int lp=7;    // liczba punkt�w �wiata
int tabela[3][lp]={'a','b','c','d','e','f','g',
                    6, 13,  4,  4,  8,  6,  10,
                    1,  1,  3,  5,  5,  8,  8}; 
void inicjuj(World swiat); // inicjuje konkretny �wiat

int main(int argc, char *argv[])
{
        auto c1 = std::chrono::high_resolution_clock::now();

        World swiat(gs_map_points,'a','g',gs_pathselect_points);
        // parametry �wiata: liczba punkt�w, home, food,
        //                   liczba punkt�w wyboru dla mr�wek

        for(unsigned int at=0; at<gs_attempts; at++)
        {
            inicjuj(swiat); // inicjacja �wiata warto�ciami
            Mrowisko m(&swiat,gs_ants,gs_fers); // parametry mrowiska: nazwa �wiata,
            // liczba mr�wek, ilo�� pozostawianego feromonu przez mr�wk�

            if(gs_WriteOnScreen) cout<<"---------- stan poczatkowy\n";

            m.pokaz(0);                // mrowisko - stan pocz�tkowy
            swiat.pokaz();

            if(gs_WriteOnScreen) cout<<endl;// �wiat    - stan pocz�tkowy

            for(unsigned int i=1;i<=gs_cycles;i++){
                if(gs_WriteOnScreen) cout<<"---------- "<<i<<" cykl ----------\n";

                m.move(); m.pokaz(i);
                swiat.pokaz();

                if(gs_WriteOnScreen) cout<<endl;
                if(gs_decreaseFeroms) swiat.decreaseFeroms();
            }

            m.WNL();

            m.reset();
            swiat.reset();
        }


            auto c2 = std::chrono::high_resolution_clock::now();
            float elapsedSeconds = std::chrono::duration_cast<std::chrono::milliseconds>(c2 - c1).count();

            if(gs_WriteBenchmarkTimes) cout << "Time: " << elapsedSeconds << " miliseconds" << endl;

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

