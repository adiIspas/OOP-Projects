#ifndef CLASA_TURN_H_INCLUDED
#define CLASA_TURN_H_INCLUDED

#include <cstring>
/// sare peste piese!!!

class Turn : public Piesa
    {
        int nr_mutari;
    public:
        Turn(int linie, int coloana, int culoare)
            {
                setare_coordonate(linie,coloana);
                setare_culoare(culoare);
                setare_tip(3);
                nr_mutari = 0;
            }
        char* validare_mutare(int linie, int coloana, int player, char motiv[100]);
        void set_nr_mutari();
        int get_nr_mutari();
    };

char* Turn::validare_mutare(int linie, int coloana, int player, char motiv[100])
    {
        /// verificam daca se afla in tabla
        if(linie > 8 || coloana > 8 || linie == 0 || coloana == 0)
            {
                strcpy(motiv,"in afara tablei");
                return motiv;
            }

        /// verificam daca muta pe aceasi linie sau coloana
        if(linie == get_linie() || coloana == get_coloana())
            return NULL;

        strcpy(motiv,"turnul poate muta doar pe aceasi linie sau coloana");
        return motiv;
    }

void Turn::set_nr_mutari()
    {
        nr_mutari = 1;
    }

int Turn::get_nr_mutari()
    {
        return nr_mutari;
    }

#endif // CLASA_TURN_H_INCLUDED
