#ifndef WORLD_H
#define WORLD_H

struct Punkt{ char name; int x; int y; float ferom;};
struct Aux{char name; float ratio;}; // struktura pomocnicza
        
class World{
      private:
      public:
        int lp;        // liczba punkt�w �wiata
        Punkt *punkty; // tablica punkt�w �wiata
        Aux *aux;      // tablica pomocnicza do oblicze�
        char home;     // nazwa punktu mrowiska
        char food;     // nazwa punktu zawieraj�cego pokarm
        int lpw;       // liczba punkt�w wyboru dla mr�wek        
        World(int _lp, char _home, char _food, int _lpw);
        void reset( );
        // zeruje ilo�� foremonu we wszystkich punktach �wiata
        void pokaz( ); //
        void decreaseFeroms();
};

#endif // WORLD_H
