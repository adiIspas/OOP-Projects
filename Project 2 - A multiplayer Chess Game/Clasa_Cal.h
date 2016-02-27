#ifndef CLASA_CAL_H_INCLUDED
#define CLASA_CAL_H_INCLUDED

#include <cstring>
#include <cmath>

class Cal : public Piesa
    {
    public:
        Cal(int linie, int coloana, int culoare)
            {
                setare_coordonate(linie,coloana);
                setare_culoare(culoare);
                setare_tip(5);
            }
        char* validare_mutare(int linie, int coloana, int player, char motiv[100]);
    };

char* Cal::validare_mutare(int linie, int coloana, int player, char motiv[100])
    {
        /// verificam daca se afla in tabla
        if(linie > 8 || coloana > 8 || linie == 0 || coloana == 0)
            {
                strcpy(motiv,"in afara tablei");
                return motiv;
            }

        /// verificam daca muta in forma de L
        if((abs(linie - get_linie()) == 2 && abs(coloana - get_coloana()) == 1) || (abs(linie - get_linie()) == 1 && abs(coloana - get_coloana()) == 2))
            return NULL;

        strcpy(motiv,"calul poate muta doar in forma de L");
        return motiv;
    }

#endif // CLASA_CAL_H_INCLUDED
