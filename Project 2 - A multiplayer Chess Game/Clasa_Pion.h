#ifndef CLASA_PION_H_INCLUDED
#define CLASA_PION_H_INCLUDED

#include <cmath>
#include <cstring>

class Pion : public Piesa
    {
        int nr_mutari;
    public:
        Pion(int linie, int coloana, int culoare)
            {
                setare_coordonate(linie,coloana);
                setare_culoare(culoare);
                setare_tip(6);
                nr_mutari = 0;
            }
        char* validare_mutare(int linie, int coloana, int player, char motiv[100]);
        void reset_nr_mutari();
    };

char* Pion::validare_mutare(int linie, int coloana, int player, char motiv[100])
    {
        /// verificam daca se afla in tabla
        if(linie > 8 || coloana > 8 || linie == 0 || coloana == 0)
            {
                strcpy(motiv,"in afara tablei");
                return motiv;
            }

        /// verificam pionul alb daca muta 2 pozitii inainte atunci cand se afla la prima mutare sau 1 inainte in rest
        if(player == 1)
            {
                if(get_linie() + 2 == linie)
                    {
                        if(nr_mutari != 0 || get_coloana() != coloana)
                            {
                                strcpy(motiv,"pionul poate muta 2 pozitii inainte doar daca se afla la prima mutare");
                                return motiv;
                            }
                    }
                else
                    if(get_linie() + 1 != linie)
                        {
                            strcpy(motiv,"pionul poate muta doar o pozitie inainte");
                            return motiv;
                        }
                    else
                        if(abs(get_coloana() - coloana) > 1)
                            {
                                strcpy(motiv,"pionul poate muta doar o pozitie inainte");
                                return motiv;
                            }
            }
        /// verificam pionul negru daca muta 2 pozitii inainte atunci cand se afla la prima mutare sau 1 inainte in rest
        if(player == 2)
            {
                if(get_linie() - 2 == linie)
                    {
                        if(nr_mutari != 0 || get_coloana() != coloana)
                            {
                                strcpy(motiv,"pionul poate muta 2 pozitii inainte doar daca se afla la prima mutare");
                                return motiv;
                            }
                    }
                else
                    if(get_linie() - 1 != linie)
                        {
                            strcpy(motiv,"pionul poate muta doar o pozitie inainte");
                            return motiv;
                        }
                    else
                        if(abs(get_coloana() - coloana) > 1)
                            {
                                strcpy(motiv,"pionul poate muta doar o pozitie inainte");
                                return motiv;
                            }
            }

        nr_mutari = 1;
        return NULL;
    }

void Pion::reset_nr_mutari()
    {
        nr_mutari = 0;
    }
#endif // CLASA_PION_H_INCLUDED
