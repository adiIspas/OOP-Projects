#ifndef CLASA_REGE_H_INCLUDED
#define CLASA_REGE_H_INCLUDED

#include <cstring>
#include <cmath>

class Rege : public Piesa
    {
        int sah, tip_piesa, linie_sah, coloana_sah, nr_mutari;

    public:
        Rege(int linie, int coloana, int culoare)
            {
                setare_coordonate(linie,coloana);
                setare_culoare(culoare);
                setare_tip(1);
                nr_mutari = 0;
            }
        char* validare_mutare(int linie, int coloana, int player, char motiv[100]);
        void set_sah(int sah_ok, int piesa, int linie, int coloana);
        int get_sah();
        int get_piesa_sah();
        int get_linie_sah();
        int get_coloana_sah();
        void set_nr_mutari();
        int get_nr_mutari();
    };

char* Rege::validare_mutare(int linie, int coloana, int player, char motiv[100])
    {
        /// verificam daca se afla in tabla
        if(linie > 8 || coloana > 8 || linie == 0 || coloana == 0)
            {
                strcpy(motiv,"in afara tablei");
                return motiv;
            }

        /// verificam daca muta o singura pozitie
//        if(abs(linie - get_linie()) == 1 || abs(coloana - get_coloana()) == 1)
//            return NULL;

//        if(linie == get_linie() && abs(coloana - get_coloana()) == 1)
//            return NULL;
//
//        if(coloana == get_coloana() && abs(linie - get_linie()) == 1)
//            return NULL;

        if(abs(linie - get_linie()) <= 1 && abs(coloana - get_coloana()) <= 1)
            return NULL;

        strcpy(motiv,"regele poate muta exact o singura pozitie");
        return motiv;
    }
void Rege::set_sah(int sah_ok, int piesa, int linie, int coloana)
    {
        sah = sah_ok;
        tip_piesa = piesa;
        linie_sah = linie;
        coloana_sah = coloana;
    }
int Rege::get_sah()
    {
        return sah;
    }
int Rege::get_piesa_sah()
    {
        return tip_piesa;
    }
int Rege::get_linie_sah()
    {
        return linie_sah;
    }
int Rege::get_coloana_sah()
    {
        return coloana_sah;
    }
void Rege::set_nr_mutari()
    {
        nr_mutari = 1;
    }
int Rege::get_nr_mutari()
    {
        return nr_mutari;
    }

#endif // CLASA_REGE_H_INCLUDED
