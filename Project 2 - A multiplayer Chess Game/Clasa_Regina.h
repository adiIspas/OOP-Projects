#ifndef CLASA_REGINA_H_INCLUDED
#define CLASA_REGINA_H_INCLUDED

#include <cstring>

class Regina : public Piesa
    {
    public:
        Regina(int linie, int coloana, int culoare)
            {
                setare_coordonate(linie,coloana);
                setare_culoare(culoare);
                setare_tip(2);
            }
        char* validare_mutare(int linie, int coloana, int player, char motiv[100]);
    };

char* Regina::validare_mutare(int linie, int coloana, int player, char motiv[100])
    {
        /// verificam daca se afla in tabla
        if(linie > 8 || coloana > 8 || linie == 0 || coloana == 0)
            {
                strcpy(motiv,"in afara tablei");
                return motiv;
            }

        if(linie == get_linie() || coloana == get_coloana())
            return NULL;

        if(abs(linie - get_linie()) == abs(coloana - get_coloana()))
            return NULL;

        strcpy(motiv,"regina poate muta doar in linie dreapta sau diagonala");
        return motiv;
    }

#endif // CLASA_REGINA_H_INCLUDED
