#ifndef MROWISKO_H
#define MROWISKO_H
#include <string>
#include "world.h"

using namespace std;



class Mrowka{
      private:
        void policz_odleglosci();
        // liczy odleglo�ci od aktualnego po�o�enia do pozosta�ych
        // punkt�w (opr�cz w�asnego i mrowiska)
        void sortuj_tablice_pomocnicza();
        // zapisuje w tablicy "aux" warto�ci
        // iloraz�w "feromon/odleg�o��" dla punkt�w
        // a nast�pnie sortuje je rosn�co
        bool sprawdz_sciezke(char znak);
        // sprawdza, czy w sciezce wyst�puje podany znak
        int losuj(); // losuje kolejne po�o�enie mr�wki
        int ruletka();
        // wybiera metod� ruletki kolejne po�o�enie mr�wki
      public:
        World *swiat; 
        // wskazanie �wiata, do kt�rego nale�y mr�wka
        char polozenie;
        float feromon; // ilo�� pozostawianego feromonu w punkcie
        bool syta;
        string sciezka;
        int wybierz_punkt(); // zwraca index kolejnego punktu
        void akcja();
        // sprawdza, czy mr�wka osi�gn�a pokarm,
        // je�li NIE - dopisuje osi�gni�ty punkt do jej �cie�ki
        // je�li TAK - dodaje do ka�dego punktu  na �cie�ce feromon,
        //             i "usypia" mr�wk� za pomoc� "syta=true" 
        void polej_sciezke();
        // akcja wykonywana na punktach �wiata nale��cych
        // do �cie�ki tej mr�wki, kt�ra dosz�a do pokarmu
        void pokaz();
};

class Mrowisko{
      private:
        int lmr;            // liczba mr�wek w mrowisku
        Mrowka *ants;       // tablica mr�wek
        string min_sciezka; // �cie�ka minimalna
      public:
        Mrowisko(World *_swiat, int _lmr, float _fer);
        // mrowisko tworzy spo�eczno�� mr�wek w okre�lonym �wiecie
        void reset();
        // ustawia wszystkie mr�wki w po�o�eniu home,
        // zeruje ich �cie�ki i ilo�� foremonu w punktach
        void move();    
        // w ka�dym cyklu przesuwa wszystkie mr�wki do kolejnych punkt�w, 
        // najlepeszych z trzech losowo (lub za pomoc� ruletki) wybranych,
        // po przesuni�ciu wykonuje na ka�dej mr�wce metod� "akcja" 
        // z klasy Mr�wka
        void pokaz(int cykl);
        void WTF(bool ferom);
        void WNL();
        void resetFerom();
};        
        

#endif // MROWISKO_H        
