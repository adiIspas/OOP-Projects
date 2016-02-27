#ifndef CLASA_NEBUN_H_INCLUDED
#define CLASA_NEBUN_H_INCLUDED

#include <cmath>
#include <cstring>

class Nebun : public Piesa
    {
    public:
        Nebun(int linie, int coloana, int culoare)
            {
                setare_coordonate(linie,coloana);
                setare_culoare(culoare);
                setare_tip(4);
            }
        char* validare_mutare(int linie, int coloana, int player, char motiv[100]);
    };

char* Nebun::validare_mutare(int linie, int coloana, int player, char motiv[100])
    {
        /// verificam daca se afla in tabla
        if(linie > 8 || coloana > 8 || linie == 0 || coloana == 0)
            {
                strcpy(motiv,"in afara tablei");
                return motiv;
            }

        /// verificam daca muta pe diagonala
        if(abs(linie - get_linie()) == abs(coloana - get_coloana()))
            return NULL;

        strcpy(motiv,"nebunul poate muta doar pe diagonala");
        return motiv;
    }

#endif // CLASA_NEBUN_H_INCLUDED
