#ifndef CLASA_PIESA_H_INCLUDED
#define CLASA_PIESA_H_INCLUDED

#include <cstring>
#include <iostream>

using namespace std;
class Piesa
    {
        int linie, coloana, culoare, tip;
    public:
        Piesa(){}
        Piesa(const Piesa &X){}
        void setare_coordonate(int i, int j);
        void setare_culoare(int i);
        void setare_tip(int i);
        int get_linie();
        int get_coloana();
        int get_culoare();
        int get_tip();
        virtual char* validare_mutare(int linie, int coloana, int player, char motiv[100])
            {
                /// verificam daca se afla in tabla
                if(linie > 8 || coloana > 8 || linie == 0 || coloana == 0)
                    {
                        strcpy(motiv,"in afara tablei");
                        return motiv;
                    }

                return NULL;
            }
        virtual void reset_nr_mutari(){}
        virtual void set_nr_mutari(){}
        virtual int get_nr_mutari(){}
        virtual void set_sah(int sah_ok, int piesa, int linie, int coloana){}
        virtual int get_sah(){}
        virtual int get_piesa_sah(){}
        virtual int get_linie_sah(){}
        virtual int get_coloana_sah(){}

    };

void Piesa::setare_coordonate(int i, int j)
    {
        linie = i;
        coloana = j;
    }
void Piesa::setare_culoare(int i)
    {
        culoare = i;
    }
void Piesa::setare_tip(int i)
    {
        tip = i;
    }
int Piesa::get_linie()
    {
        return linie;
    }
int Piesa::get_coloana()
    {
        return coloana;
    }
int Piesa::get_culoare()
    {
        return culoare;
    }
int Piesa::get_tip()
    {
        return tip;
    }

#endif // CLASA_PIESA_H_INCLUDED
