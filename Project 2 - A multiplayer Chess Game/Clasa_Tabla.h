#ifndef CLASA_TABLA_H_INCLUDED
#define CLASA_TABLA_H_INCLUDED

#include <iostream>
using namespace std;

class Tabla
    {
        Piesa *matrice[65][65];
        int pozitie_istoric_mutari, istoric_mutari[100][6], linie_rege1, coloana_rege1;
    public:
        Tabla();
        Piesa* get_piesa(int i, int j);
        char* muta(int linie1, int coloana1, int linie2, int coloana2, int player, char motiv[100]);
        void Afisare_Tabla();
        int get_pozitie_istoric_mutari();
        void crestere_pozitie_istoric();
        void setare_mutare(int linie1, int coloana1, int linie2, int coloana2, int player, int tip_piesa);
        void afisare_mutari();
        void set_rege(int linie, int coloana);
        Piesa* get_rege();
        void set_sah_inline(int linie2, int coloana2, int player, int tip_piesa);
        void set_sah_indiagonala(int linie2, int coloana2, int player, int tip_piesa);
        int verific_raman_sah(int linie1, int coloana1, int linie2, int coloana2, int player);
        int verifc_adversar_ramane_sah(int &linie1, int &coloana1, int &linie2, int &coloana2, int player, int &tip);
        int verific_rege_sah(int linie1, int linie2, int linie, int coloana, int player, int &tip);
        int sah_mat(int player,int &l1, int &c1, int &l2, int &c2);
        int pat(int player);
        char* validare_mutare_tabla(int linie1, int coloana1, int linie2, int coloana2, int player, char motiv[100]);
        char* validare_mutare_sah_pat(int linie1, int coloana1, int linie2, int coloana2, int player, char motiv[100]);
        char* validare_iesire_sah(int linie1, int coloana1, int linie2, int coloana2, int &linie_rege, int &coloana_rege, int &linie_piesa, int &coloana_piesa, int &tip_piesa, int player, char motiv[100], int intrare);
        char* muta_sah_mat(int linie1, int coloana1, int linie2, int coloana2, int player, char motiv[100]);
        char* muta_pat(int linie1, int coloana1, int linie2, int coloana2, int player, char motiv[100]);
        friend ostream& operator<<(ostream&, Piesa&);
    };

Tabla::Tabla()
    {
        int i;
        /// setare pozitie de start in istoric mutari
        pozitie_istoric_mutari = 1;

        linie_rege1 = 1;
        coloana_rege1 = 1;

        /// SETARE PIONI
        for(i = 1; i <= 8; i++)
            {
                Piesa *X = new Pion(2,i,1);
                matrice[2][i] = X;

                X = new Pion(7,i,2);
                matrice[7][i] = X;
            }

        /// SETARE TURNURI
        Piesa *X = new Turn(1,1,1);
        matrice[1][1] = X;
        X = new Turn(1,8,1);
        matrice[1][8] = X;

        X = new Turn(8,1,2);
        matrice[8][1] = X;
        X = new Turn(8,8,2);
        matrice[8][8] = X;

        /// SETARE CAI
        X = new Cal(1,2,1);
        matrice[1][2] = X;
        X = new Cal(1,7,1);
        matrice[1][7] = X;

        X = new Cal(8,2,2);
        matrice[8][2] = X;
        X = new Cal(8,7,2);
        matrice[8][7] = X;

        /// SETARE NEBUNI
        X = new Nebun(1,3,1);
        matrice[1][3] = X;
        X = new Nebun(1,6,1);
        matrice[1][6] = X;

        X = new Nebun(8,3,2);
        matrice[8][3] = X;
        X = new Nebun(8,6,2);
        matrice[8][6] = X;

        /// SETARE REGE
        X = new Rege(1,5,1);
        matrice[1][5] = X;

        X = new Rege(8,5,2);
        matrice[8][5] = X;

        /// SETARE REGINA
        X = new Regina(1,4,1);
        matrice[1][4] = X;

        X = new Regina(8,4,2);
        matrice[8][4] = X;

        /// test sah mat
 //       Piesa *X;
//        X = new Cal(3,6,1);
//        matrice[3][6] = X;
//
//        X = new Regina(2,4,1);
//        matrice[2][4] = X;
//
//        X = new Rege(5,8,2);
//        matrice[5][8] = X;

        //matrice[7][5] = NULL;

//        X = new Turn(2,1,1);
//        matrice[2][1] = X;
//
//        X = new Turn(3,2,1);
//        matrice[3][2] = X;
//
//        X = new Rege(1,8,2);
//        matrice[1][8] = X;

        /// test pat
//        X = new Regina(4,7,1);
//        matrice[4][7] = X;
//
//        X = new Rege(1,8,2);
//        matrice[1][8] = X;

    }

Piesa* Tabla::get_piesa(int i, int j)
    {
        return matrice[i][j];
    }

int Tabla::get_pozitie_istoric_mutari()
    {
        return pozitie_istoric_mutari;
    }

void Tabla::crestere_pozitie_istoric()
    {
        pozitie_istoric_mutari++;
    }

void Tabla::set_rege(int linie, int coloana)
    {
        linie_rege1 = linie;
        coloana_rege1 = coloana;
    }

Piesa* Tabla::get_rege()
    {
         if(matrice[linie_rege1][coloana_rege1])
            return matrice[linie_rege1][coloana_rege1];
    }

void Tabla::setare_mutare(int linie1, int coloana1, int linie2, int coloana2, int player, int tip_piesa)
    {
        int i;
        i = get_pozitie_istoric_mutari();
        istoric_mutari[i][0] = linie1;
        istoric_mutari[i][1] = coloana1;
        istoric_mutari[i][2] = linie2;
        istoric_mutari[i][3] = coloana2;
        istoric_mutari[i][4] = player;
        istoric_mutari[i][5] = tip_piesa;
        crestere_pozitie_istoric();
    }

void Tabla::afisare_mutari()
    {
        int i, j, tip;
        j = get_pozitie_istoric_mutari();

        if(get_pozitie_istoric_mutari() != 1)
            cout << "Istoric mutari: \n";

        for(i = 1; i < j; i++)
            {
                tip = istoric_mutari[i][5];
                cout << i << ". " << "Player " << istoric_mutari[i][4] << " muta ";

                switch(tip)
                    {
                        case 1: {cout << "Regele";} break;
                        case 2: {cout << "Regina";} break;
                        case 3: {cout << "Turnul";} break;
                        case 4: {cout << "Nebunnul";} break;
                        case 5: {cout << "Calul";} break;
                        case 6: {cout << "Pionul";} break;
                    }

                cout << " de la pozitia " << istoric_mutari[i][0] << " " << istoric_mutari[i][1] << " la pozitita " << istoric_mutari[i][2] << " " << istoric_mutari[i][3] << endl;
            }

        if(get_pozitie_istoric_mutari() != 1)
            cout << endl;
    }

void Tabla::set_sah_inline(int linie2, int coloana2, int player, int tip_piesa)
    {
        int i;

        for(i = linie2 + 1; i <= 8; i++)
            if(matrice[i][coloana2])
                {
                    if(matrice[i][coloana2] -> get_tip() == 1 && matrice[i][coloana2] -> get_culoare() != player)
                        {
                            matrice[i][coloana2] -> set_sah(1,tip_piesa,linie2,coloana2);
                            set_rege(i,coloana2);
                            break;
                        }
                    else
                        break;
                }
        for(i = linie2 - 1; i >= 1; i--)
            if(matrice[i][coloana2])
                {
                    if(matrice[i][coloana2] -> get_tip() == 1 && matrice[i][coloana2] -> get_culoare() != player)
                        {
                            matrice[i][coloana2] -> set_sah(1,tip_piesa,linie2,coloana2);
                            set_rege(i,coloana2);
                            break;
                        }
                    else
                        break;
                }

        for(i = coloana2 + 1; i <= 8; i++)
            if(matrice[linie2][i])
                {
                    if(matrice[linie2][i] -> get_tip() == 1 && matrice[linie2][i] -> get_culoare() != player)
                        {
                            matrice[linie2][i] -> set_sah(1,tip_piesa,linie2,coloana2);
                            set_rege(linie2,i);
                            break;
                        }
                    else
                        break;
                }

        for(i = coloana2 - 1; i >= 1; i--)
            if(matrice[linie2][i])
                {
                    if(matrice[linie2][i] -> get_tip() == 1 && matrice[linie2][i] -> get_culoare() != player)
                        {
                            matrice[linie2][i] -> set_sah(1,tip_piesa,linie2,coloana2);
                            set_rege(linie2,i);
                            break;
                        }
                    else
                        break;
                }
    }

void Tabla::set_sah_indiagonala(int linie2, int coloana2, int player, int tip_piesa)
    {
        int i, j;

        for(i = linie2 + 1, j = coloana2 + 1; i <= 8 && j <= 8; i++,j++)
            if(matrice[i][j])
                {
                    if(matrice[i][j] -> get_tip() == 1 && matrice[i][j] -> get_culoare() != player)
                        {
                            matrice[i][j] -> set_sah(1,tip_piesa,linie2,coloana2);
                            set_rege(i,j);
                            break;
                        }
                    else
                        break;
                }
        /// aici
        for(i = linie2 - 1, j = coloana2 - 1; i >= 1 && j >= 1; i--,j--)
            if(matrice[i][j])
                {
                    if(matrice[i][j] -> get_tip() == 1 && matrice[i][j] -> get_culoare() != player)
                        {
                            matrice[i][j] -> set_sah(1,tip_piesa,linie2,coloana2);
                            set_rege(i,j);
                            break;
                        }
                    else
                        break;
                }

        for(i = linie2 + 1, j = coloana2 - 1; i <= 8 && j >= 1; i++,j--)
            if(matrice[i][j])
                {
                    if(matrice[i][j] -> get_tip() == 1 && matrice[i][j] -> get_culoare() != player)
                        {
                            matrice[i][j] -> set_sah(1,tip_piesa,linie2,coloana2);
                            set_rege(i,j);
                            break;
                        }
                    else
                        break;
                }

        for(i = linie2 - 1, j = coloana2 + 1; i >= 1 && j <= 8; i--,j++)
            if(matrice[i][j])
                {
                    if(matrice[i][j] -> get_tip() == 1 && matrice[i][j] -> get_culoare() != player)
                        {
                            matrice[i][j] -> set_sah(1,tip_piesa,linie2,coloana2);
                            set_rege(i,j);
                            break;
                        }
                    else
                        break;
                }
    }

int Tabla::verific_raman_sah(int linie1, int coloana1, int linie2, int coloana2, int player)
    {
        int i, j, sw = 0, linie, coloana, inlocuire = 0;
        Piesa *X;
        X = new Pion(linie2,coloana2,player);

        if(matrice[linie2][coloana2] == NULL)
            {
                matrice[linie2][coloana2] = X;
                inlocuire = 1;
            }

        /// verificam daca se afla regele pe directia piesei ce o mutam

        /// pe aceasi linie, coloane
        for(i = linie1 - 1; i >= 1; i--)
            if(matrice[i][coloana1])
                if(matrice[i][coloana1] -> get_tip() == 1 && matrice[i][coloana1] -> get_culoare() == player)
                    {
                        linie = i;
                        coloana = coloana1;
                        sw = 1;
                        break;
                    }
                else
                    break;

        for(i = linie1 + 1; i <= 8; i++)
            if(matrice[i][coloana1])
                if(matrice[i][coloana1] -> get_tip() == 1 && matrice[i][coloana1] -> get_culoare() == player)
                    {
                        linie = i;
                        coloana = coloana1;
                        sw = 1;
                        break;
                    }
                else
                    break;

        for(i = coloana1 - 1; i >= 1; i--)
            if(matrice[linie1][i])
                if(matrice[linie1][i] -> get_tip() == 1 && matrice[linie1][i] -> get_culoare() == player)
                    {
                        linie = linie1;
                        coloana = i;
                        sw = 1;
                        break;
                    }
                else
                    break;

        for(i = coloana1 + 1; i <= 8; i++)
            if(matrice[linie1][i])
                if(matrice[linie1][i] -> get_tip() == 1 && matrice[linie1][i] -> get_culoare() == player)
                    {
                        linie = linie1;
                        coloana = i;
                        sw = 1;
                        break;
                    }
                else
                    break;

        /// pe diagonala
        for(i = linie1 - 1, j = coloana1 + 1; i >= 1 && j <= 8; i--, j++)
            if(matrice[i][j])
                if(matrice[i][j] -> get_tip() == 1 && matrice[i][j] -> get_culoare() == player)
                    {

                        linie = i;
                        coloana = j;
                        sw = 1;
                        break;
                    }
                else
                    break;

        for(i = linie1 + 1, j = coloana1 + 1; i <= 8 && j <= 8; i++, j++)
            if(matrice[i][j])
                if(matrice[i][j] -> get_tip() == 1 && matrice[i][j] -> get_culoare() == player)
                    {

                        linie = i;
                        coloana = j;
                        sw = 1;
                        break;
                    }
                else
                    break;

        for(i = linie1 + 1, j = coloana1 - 1; i <= 8 && j >= 1; i++, j--)
            if(matrice[i][j])
                if(matrice[i][j] -> get_tip() == 1 && matrice[i][j] -> get_culoare() == player)
                    {

                        linie = i;
                        coloana = j;
                        sw = 1;
                        break;
                    }
                else
                    break;

        for(i = linie1 - 1, j = coloana1 - 1; i >= 1 && j >= 1; i--, j--)
            if(matrice[i][j])
                if(matrice[i][j] -> get_tip() == 1 && matrice[i][j] -> get_culoare() == player)
                    {

                        linie = i;
                        coloana = j;
                        sw = 1;
                        break;
                    }
                else
                    break;

        /// verificam daca am gasit regele
        if(sw == 1)
            {
                /// daca avem acesi linie sau coloana
                if(linie == linie1 || coloana == coloana1)
                    {
                        if(linie < linie1 && coloana == coloana1)
                            for(i = linie1 + 1; i <= 8; i++)
                                if(matrice[i][coloana1])
                                    if((matrice[i][coloana1] -> get_tip() == 2 || matrice[i][coloana1] -> get_tip() == 3) && (matrice[i][coloana1] -> get_culoare() != player))
                                        {
                                            if(inlocuire == 1)
                                                matrice[linie2][coloana2] = NULL;
                                            return 1;
                                        }
                                    else
                                        break;

                        if(linie == linie1 && coloana1 < coloana)
                            for(i = coloana1 - 1; i >= 1; i--)
                                if(matrice[linie1][i])
                                    if((matrice[linie1][i] -> get_tip() == 2 || matrice[linie1][i] -> get_tip() == 3) && (matrice[linie1][i] -> get_culoare() != player))
                                        {
                                            if(inlocuire == 1)
                                                matrice[linie2][coloana2] = NULL;
                                            return 1;
                                        }
                                    else
                                        break;

                        if(linie > linie1 && coloana == coloana1)
                            for(i = linie1 - 1; i >= 1; i--)
                                if(matrice[i][coloana1])
                                    if((matrice[i][coloana1] -> get_tip() == 2 || matrice[i][coloana1] -> get_tip() == 3) && (matrice[i][coloana1] -> get_culoare() != player))
                                        {
                                            if(inlocuire == 1)
                                                matrice[linie2][coloana2] = NULL;
                                            return 1;
                                        }
                                    else
                                        break;

                        if(linie == linie1 && coloana1 > coloana)
                            for(i = coloana1 + 1; i <= 8; i++)
                                if(matrice[linie1][i])
                                    if((matrice[linie1][i] -> get_tip() == 2 || matrice[linie1][i] -> get_tip() == 3) && (matrice[linie1][i] -> get_culoare() != player))
                                        {
                                            if(inlocuire == 1)
                                                matrice[linie2][coloana2] = NULL;
                                            return 1;
                                        }
                                    else
                                        break;

                    }

                /// daca regele se afla pe diagonala
                if(linie < linie1 && coloana > coloana1)
                    for(i = linie1 + 1, j = coloana1 - 1; i <= 8 && j >= 1; i++, j--)
                        if(matrice[i][j])
                            if((matrice[i][j] -> get_tip() == 2 || matrice[i][j] -> get_tip() == 4) && (matrice[i][j] -> get_culoare() != player))
                                {
                                    if(inlocuire == 1)
                                        matrice[linie2][coloana2] = NULL;
                                    return 1;
                                }
                            else
                                break;

                if(linie > linie1 && coloana > coloana1)
                    for(i = linie1 - 1, j = coloana1 - 1; i >= 1 && j >= 1; i--, j--)
                        if(matrice[i][j])
                            if((matrice[i][j] -> get_tip() == 2 || matrice[i][j] -> get_tip() == 4) && (matrice[i][j] -> get_culoare() != player))
                                {
                                    if(inlocuire == 1)
                                        matrice[linie2][coloana2] = NULL;
                                    return 1;
                                }
                            else
                                break;

                if(linie > linie1 && coloana < coloana1)
                    for(i = linie1 - 1, j = coloana1 + 1; i >= 1 && j <= 8; i--, j++)
                        if(matrice[i][j])
                            if((matrice[i][j] -> get_tip() == 2 || matrice[i][j] -> get_tip() == 4) && (matrice[i][j] -> get_culoare() != player))
                                {
                                    if(inlocuire == 1)
                                        matrice[linie2][coloana2] = NULL;
                                    return 1;
                                }
                            else
                                break;

                if(linie < linie1 && coloana < coloana1)
                    for(i = linie1 + 1, j = coloana1 + 1; i <= 8 && j <= 8; i++, j++)
                        if(matrice[i][j])
                            if((matrice[i][j] -> get_tip() == 2 || matrice[i][j] -> get_tip() == 4) && (matrice[i][j] -> get_culoare() != player))
                                {
                                    if(inlocuire == 1)
                                        matrice[linie2][coloana2] = NULL;
                                    return 1;
                                }
                            else
                                break;

                if(inlocuire == 1)
                    matrice[linie2][coloana2] = NULL;

                return 0;
            }

        if(inlocuire == 1)
            matrice[linie2][coloana2] = NULL;

        return 0;
    }

int Tabla::verifc_adversar_ramane_sah(int &linie1, int &coloana1, int &linie2, int &coloana2, int player, int &tip)
    {
        int i, j, sw = 0, linie, coloana, inlocuire = 0;
        Piesa *X;

        X = new Pion(linie2,coloana2,player);

        if(matrice[linie2][coloana2] == NULL)
            {
                matrice[linie2][coloana2] = X;
                inlocuire = 1;
            }

        /// verificam daca se afla regele pe directia piesei ce o mutam

        /// pe aceasi linie, coloane
        for(i = linie1 - 1; i >= 1; i--)
            if(matrice[i][coloana1])
                if(matrice[i][coloana1] -> get_tip() == 1 && matrice[i][coloana1] -> get_culoare() != player)
                    {
                        linie = i;
                        coloana = coloana1;
                        sw = 1;
                        break;
                    }
                else
                    break;

        for(i = linie1 + 1; i <= 8; i++)
            if(matrice[i][coloana1])
                if(matrice[i][coloana1] -> get_tip() == 1 && matrice[i][coloana1] -> get_culoare() != player)
                    {
                        linie = i;
                        coloana = coloana1;
                        sw = 1;
                        break;
                    }
                else
                    break;

        for(i = coloana1 - 1; i >= 1; i--)
            if(matrice[linie1][i])
                if(matrice[linie1][i] -> get_tip() == 1 && matrice[linie1][i] -> get_culoare() != player)
                    {
                        linie = linie1;
                        coloana = i;
                        sw = 1;
                        break;
                    }
                else
                    break;

        for(i = coloana1 + 1; i <= 8; i++)
            if(matrice[linie1][i])
                if(matrice[linie1][i] -> get_tip() == 1 && matrice[linie1][i] -> get_culoare() != player)
                    {
                        linie = linie1;
                        coloana = i;
                        sw = 1;
                        break;
                    }
                else
                    break;

        /// pe diagonala
        for(i = linie1 - 1, j = coloana1 + 1; i >= 1 && j <= 8; i--, j++)
            if(matrice[i][j])
                if(matrice[i][j] -> get_tip() == 1 && matrice[i][j] -> get_culoare() != player)
                    {

                        linie = i;
                        coloana = j;
                        sw = 1;
                        break;
                    }
                else
                    break;

        for(i = linie1 + 1, j = coloana1 + 1; i <= 8 && j <= 8; i++, j++)
            if(matrice[i][j])
                if(matrice[i][j] -> get_tip() == 1 && matrice[i][j] -> get_culoare() != player)
                    {

                        linie = i;
                        coloana = j;
                        sw = 1;
                        break;
                    }
                else
                    break;

        for(i = linie1 + 1, j = coloana1 - 1; i <= 8 && j >= 1; i++, j--)
            if(matrice[i][j])
                if(matrice[i][j] -> get_tip() == 1 && matrice[i][j] -> get_culoare() != player)
                    {

                        linie = i;
                        coloana = j;
                        sw = 1;
                        break;
                    }
                else
                    break;

        for(i = linie1 - 1, j = coloana1 - 1; i >= 1 && j >= 1; i--, j--)
            if(matrice[i][j])
                if(matrice[i][j] -> get_tip() == 1 && matrice[i][j] -> get_culoare() != player)
                    {

                        linie = i;
                        coloana = j;
                        sw = 1;
                        break;
                    }
                else
                    break;

        /// verificam daca am gasit regele
        if(sw == 1)
            {
                /// setam pozitia regelui
//                linie1 = linie;
//                coloana1 = coloana;

                /// daca avem acesi linie sau coloana
                if(linie == linie1 || coloana == coloana1)
                    {
                        if(linie < linie1 && coloana == coloana1)
                            for(i = linie1 + 1; i <= 8; i++)
                                if(matrice[i][coloana1])
                                    if((matrice[i][coloana1] -> get_tip() == 2 || matrice[i][coloana1] -> get_tip() == 3) && (matrice[i][coloana1] -> get_culoare() == player))
                                        {
                                            if(inlocuire == 1)
                                                matrice[linie2][coloana2] = NULL;

                                            linie1 = linie;
                                            coloana1 = coloana;
                                            linie2 = i;
                                            coloana2 = coloana1;
                                            tip = matrice[linie2][coloana2] -> get_tip();
                                            return 1;
                                        }
                                    else
                                        break;

                        if(linie == linie1 && coloana1 < coloana)
                            for(i = coloana1 - 1; i >= 1; i--)
                                if(matrice[linie1][i])
                                    if((matrice[linie1][i] -> get_tip() == 2 || matrice[linie1][i] -> get_tip() == 3) && (matrice[linie1][i] -> get_culoare() == player))
                                        {
                                            if(inlocuire == 1)
                                                matrice[linie2][coloana2] = NULL;

                                            linie1 = linie;
                                            coloana1 = coloana;
                                            linie2 = linie1;
                                            coloana2 = i;
                                            tip = matrice[linie2][coloana2] -> get_tip();
                                            return 1;
                                        }
                                    else
                                        break;

                        if(linie > linie1 && coloana == coloana1)
                            for(i = linie1 - 1; i >= 1; i--)
                                if(matrice[i][coloana1])
                                    if((matrice[i][coloana1] -> get_tip() == 2 || matrice[i][coloana1] -> get_tip() == 3) && (matrice[i][coloana1] -> get_culoare() == player))
                                        {
                                            if(inlocuire == 1)
                                                matrice[linie2][coloana2] = NULL;

                                            linie1 = linie;
                                            coloana1 = coloana;
                                            linie2 = i;
                                            coloana2 = coloana1;
                                            tip = matrice[linie2][coloana2] -> get_tip();
                                            return 1;
                                        }
                                    else
                                        break;

                        if(linie == linie1 && coloana1 > coloana)
                            for(i = coloana1 + 1; i <= 8; i++)
                                if(matrice[linie1][i])
                                    if((matrice[linie1][i] -> get_tip() == 2 || matrice[linie1][i] -> get_tip() == 3) && (matrice[linie1][i] -> get_culoare() == player))
                                        {
                                            if(inlocuire == 1)
                                                matrice[linie2][coloana2] = NULL;

                                            linie1 = linie;
                                            coloana1 = coloana;
                                            linie2 = linie1;
                                            coloana2 = i;
                                            tip = matrice[linie2][coloana2] -> get_tip();
                                            return 1;
                                        }
                                    else
                                        break;

                    }

                /// daca regele se afla pe diagonala
                if(linie < linie1 && coloana > coloana1)
                    for(i = linie1 + 1, j = coloana1 - 1; i <= 8 && j >= 1; i++, j--)
                        if(matrice[i][j])
                            if((matrice[i][j] -> get_tip() == 2 || matrice[i][j] -> get_tip() == 4) && (matrice[i][j] -> get_culoare() == player))
                                {
                                    if(inlocuire == 1)
                                        matrice[linie2][coloana2] = NULL;

                                    linie1 = linie;
                                    coloana1 = coloana;
                                    linie2 = i;
                                    coloana2 = j;
                                    tip = matrice[linie2][coloana2] -> get_tip();
                                    return 1;
                                }
                            else
                                break;

                if(linie > linie1 && coloana > coloana1)
                    for(i = linie1 - 1, j = coloana1 - 1; i >= 1 && j >= 1; i--, j--)
                        if(matrice[i][j])
                            if((matrice[i][j] -> get_tip() == 2 || matrice[i][j] -> get_tip() == 4) && (matrice[i][j] -> get_culoare() == player))
                                {
                                    if(inlocuire == 1)
                                        matrice[linie2][coloana2] = NULL;

                                    linie1 = linie;
                                    coloana1 = coloana;
                                    linie2 = i;
                                    coloana2 = j;
                                    tip = matrice[linie2][coloana2] -> get_tip();
                                    return 1;
                                }
                            else
                                break;

                if(linie > linie1 && coloana < coloana1)
                    for(i = linie1 - 1, j = coloana1 + 1; i >= 1 && j <= 8; i--, j++)
                        if(matrice[i][j])
                            if((matrice[i][j] -> get_tip() == 2 || matrice[i][j] -> get_tip() == 4) && (matrice[i][j] -> get_culoare() == player))
                                {
                                    if(inlocuire == 1)
                                        matrice[linie2][coloana2] = NULL;

                                    linie1 = linie;
                                    coloana1 = coloana;
                                    linie2 = i;
                                    coloana2 = j;
                                    tip = matrice[linie2][coloana2] -> get_tip();
                                    return 1;
                                }
                            else
                                break;

                if(linie < linie1 && coloana < coloana1)
                    for(i = linie1 + 1, j = coloana1 + 1; i <= 8 && j <= 8; i++, j++)
                        if(matrice[i][j])
                            if((matrice[i][j] -> get_tip() == 2 || matrice[i][j] -> get_tip() == 4) && (matrice[i][j] -> get_culoare() == player))
                                {
                                    if(inlocuire == 1)
                                        matrice[linie2][coloana2] = NULL;

                                    linie1 = linie;
                                    coloana1 = coloana;
                                    linie2 = i;
                                    coloana2 = j;
                                    tip = matrice[linie2][coloana2] -> get_tip();
                                    return 1;
                                }
                            else
                                break;

                 if(inlocuire == 1)
                    matrice[linie2][coloana2] = NULL;

                return 0;
            }

         if(inlocuire == 1)
            matrice[linie2][coloana2] = NULL;

        return 0;
    }

int Tabla::verific_rege_sah(int linie1, int coloana1, int linie, int coloana, int player, int &tip)
    {
        int i, j, sw = 0;

        for(i = linie - 1; i >= 1; i--)
            if(matrice[i][coloana])
                if((matrice[i][coloana] -> get_tip() == 2 || matrice[i][coloana] -> get_tip() == 3) && matrice[i][coloana] -> get_culoare() != player)
                    {

                        tip = matrice[i][coloana] -> get_tip();
                        return 1;
                    }
                else
                    break;

        for(i = coloana + 1; i <= 8; i++)
            if(matrice[linie][i])
                if((matrice[linie][i] -> get_tip() == 2 || matrice[linie][i] -> get_tip() == 3) && matrice[linie][i] -> get_culoare() != player)
                    {
                        tip = matrice[linie][i] -> get_tip();
                        return 1;
                    }
                else
                    break;

        for(i = linie + 1; i <= 8; i++)
            if(matrice[i][coloana])
                if((matrice[i][coloana] -> get_tip() == 2 || matrice[i][coloana] -> get_tip() == 3) && matrice[i][coloana] -> get_culoare() != player)
                    {
                        tip = matrice[i][coloana] -> get_tip();
                        return 1;
                    }
                else
                    break;

        for(i = coloana - 1; i >= 1; i--)
            if(matrice[linie][i])
                if((matrice[linie][i] -> get_tip() == 2 || matrice[linie][i] -> get_tip() == 3) && matrice[linie][i] -> get_culoare() != player)
                    {
                        tip = matrice[linie][i] -> get_tip();
                        return 1;
                    }
                else
                    break;

        for(i = linie - 1, j = coloana + 1; i >= 1 && j <= 8; i--, j++)
            if(matrice[i][j])
                if((matrice[i][j] -> get_tip() == 2 || matrice[i][j] -> get_tip() == 4) && matrice[i][j] -> get_culoare() != player)
                    {
                        tip = matrice[i][j] -> get_tip();
                        return 1;
                    }
                else
                    break;

        for(i = linie + 1, j = coloana + 1; i <= 8 && j <= 8; i++, j++)
            if(matrice[i][j])
                if((matrice[i][j] -> get_tip() == 2 || matrice[i][j] -> get_tip() == 4) && matrice[i][j] -> get_culoare() != player)
                    {
                        tip = matrice[i][j] -> get_tip();
                        return 1;
                    }
                else
                    break;

        for(i = linie + 1, j = coloana - 1; i <= 8 && j >= 1; i++, j--)
            if(matrice[i][j])
                if((matrice[i][j] -> get_tip() == 2 || matrice[i][j] -> get_tip() == 4) && matrice[i][j] -> get_culoare() != player)
                    {
                        tip = matrice[i][j] -> get_tip();
                        return 1;
                    }
                else
                    break;

        for(i = linie - 1, j = coloana - 1; i >= 1 && j >= 1; i--, j--)
            if(matrice[i][j])
                if((matrice[i][j] -> get_tip() == 2 || matrice[i][j] -> get_tip() == 4) && matrice[i][j] -> get_culoare() != player)
                    {
                        tip = matrice[i][j] -> get_tip();
                        return 1;
                    }
                else
                    break;

    /// testam pentru cal
    if(matrice[linie + 2][coloana + 1])
        if(matrice[linie + 2][coloana + 1] -> get_tip() == 5 && matrice[linie + 2][coloana + 1] -> get_culoare() != player)
        {
            tip = 5;
            return 1;
        }

    if(matrice[linie + 1][coloana + 2])
        if(matrice[linie + 1][coloana + 2] -> get_tip() == 5 && matrice[linie + 1][coloana + 2] -> get_culoare() != player)
        {
            tip = 5;
            return 1;
        }

    if(linie - 2 >= 1)
    if(matrice[linie - 2][coloana + 1])
        if(matrice[linie - 2][coloana + 1] -> get_tip() == 5 && matrice[linie - 2][coloana + 1] -> get_culoare() != player)
        {
            tip = 5;
            return 1;
        }

    if(coloana - 1 >= 1)
    if(matrice[linie + 2][coloana - 1])
        if(matrice[linie + 2][coloana - 1] -> get_tip() == 5 && matrice[linie + 2][coloana - 1] -> get_culoare() != player)
        {
            tip = 5;
            return 1;
        }

    if(coloana - 2 >= 1)
    if(matrice[linie + 1][coloana - 2])
        if(matrice[linie + 1][coloana - 2] -> get_tip() == 5 && matrice[linie + 1][coloana - 2] -> get_culoare() != player)
        {
            tip = 5;
            return 1;
        }

    if(linie - 1 >= 1)
    if(matrice[linie - 1][coloana + 2])
        if(matrice[linie - 1][coloana + 2] -> get_tip() == 5 && matrice[linie - 1][coloana + 2] -> get_culoare() != player)
        {
            tip = 5;
            return 1;
        }

    if(coloana - 1 >= 1)
    if(matrice[linie + 2][coloana - 1])
        if(matrice[linie + 2][coloana - 1] -> get_tip() == 5 && matrice[linie + 2][coloana - 1] -> get_culoare() != player)
        {
            tip = 5;
            return 1;
        }

    if(linie - 1 >= 1 && coloana - 2 >= 1)
    if(matrice[linie - 1][coloana - 2])
        if(matrice[linie - 1][coloana - 2] -> get_tip() == 5 && matrice[linie - 1][coloana - 2] -> get_culoare() != player)
        {
            tip = 5;
            return 1;
        }

    if(linie - 2 >= 1 && coloana1 >= 1)
    if(matrice[linie - 2][coloana - 1])
        if(matrice[linie - 2][coloana - 1] -> get_tip() == 5 && matrice[linie - 2][coloana - 1] -> get_culoare() != player)
        {
            tip = 5;
            return 1;
        }

    /// testam pentru pion
    if(linie - 1 >= 1 && coloana - 1 >= 1)
    if(matrice[linie - 1][coloana - 1])
        if(matrice[linie - 1][coloana - 1] -> get_tip() == 6 && matrice[linie - 1][coloana - 1] -> get_culoare() != player)
        {
            tip = 6;
            return 1;
        }

    if(linie - 1 >= 1)
    if(matrice[linie - 1][coloana + 1])
        if(matrice[linie - 1][coloana + 1] -> get_tip() == 6 && matrice[linie - 1][coloana + 1] -> get_culoare() != player)
        {
            tip = 6;
            return 1;
        }

    if(matrice[linie + 1][coloana + 1])
        if(matrice[linie + 1][coloana + 1] -> get_tip() == 6 && matrice[linie + 1][coloana + 1] -> get_culoare() != player)
        {
            tip = 6;
            return 1;
        }

    if(coloana - 1 >= 1)
    if(matrice[linie + 1][coloana - 1])
        if(matrice[linie + 1][coloana - 1] -> get_tip() == 6 && matrice[linie + 1][coloana - 1] -> get_culoare() != player)
        {
            tip = 6;
            return 1;
        }


        return 0;
    }

char* Tabla::validare_mutare_tabla(int linie1, int coloana1, int linie2, int coloana2, int player, char motiv[100])
    {
        int tip_piesa, i, j, sw = 0, ok, l1, l2, c1, c2, tip;
        Piesa *X = new Rege(linie1,coloana1,player);

        tip_piesa = matrice[linie1][coloana1] -> get_tip();

        switch(tip_piesa)
            {
            case 1 : {
                        /// testam daca pe potizitia in care se ajunge este o piesa proprie
                        if(matrice[linie2][coloana2])
                        if(matrice[linie2][coloana2] -> get_culoare() == player)
                            {
                                strcpy(motiv,"nu poti cuceri o piesa proprie");
                                return motiv;
                            }

                        /// testam daca se apropie de celalalt rege
                        if(matrice[linie2][coloana2 - 1])
                           if(matrice[linie2][coloana2 - 1] -> get_tip() == 1 && matrice[linie2][coloana2 - 1] -> get_culoare() != player)
                            {
                                strcpy(motiv,"nu te poti apropia la mai putin de o pozitie de celalalt rege");
                                return motiv;
                            }

                         if(matrice[linie2 - 1][coloana2 - 1])
                           if(matrice[linie2 - 1][coloana2 - 1] -> get_tip() == 1 && matrice[linie2 - 1][coloana2 - 1] -> get_culoare() != player)
                            {
                                strcpy(motiv,"nu te poti apropia la mai putin de o pozitie de celalalt rege");
                                return motiv;
                            }

                         if(matrice[linie2 - 1][coloana2])
                           if(matrice[linie2 - 1][coloana2] -> get_tip() == 1 && matrice[linie2 - 1][coloana2] -> get_culoare() != player)
                            {
                                strcpy(motiv,"nu te poti apropia la mai putin de o pozitie de celalalt rege");
                                return motiv;
                            }

                         if(matrice[linie2 - 1][coloana2 + 1])
                           if(matrice[linie2 - 1][coloana2 + 1] -> get_tip() == 1 && matrice[linie2 - 1][coloana2 + 1] -> get_culoare() != player)
                            {
                                strcpy(motiv,"nu te poti apropia la mai putin de o pozitie de celalalt rege");
                                return motiv;
                            }

                         if(matrice[linie2][coloana2 + 1])
                           if(matrice[linie2][coloana2 + 1] -> get_tip() == 1 && matrice[linie2][coloana2 + 1] -> get_culoare() != player)
                            {
                                strcpy(motiv,"nu te poti apropia la mai putin de o pozitie de celalalt rege");
                                return motiv;
                            }

                         if(matrice[linie2 + 1][coloana2 + 1])
                           if(matrice[linie2 + 1][coloana2 + 1] -> get_tip() == 1 && matrice[linie2 + 1][coloana2 + 1] -> get_culoare() != player)
                            {
                                strcpy(motiv,"nu te poti apropia la mai putin de o pozitie de celalalt rege");
                                return motiv;
                            }

                         if(matrice[linie2 + 1][coloana2])
                           if(matrice[linie2 + 1][coloana2] -> get_tip() == 1 && matrice[linie2 + 1][coloana2] -> get_culoare() != player)
                            {
                                strcpy(motiv,"nu te poti apropia la mai putin de o pozitie de celalalt rege");
                                return motiv;
                            }

                         if(matrice[linie2 + 1][coloana2 - 1])
                           if(matrice[linie2 + 1][coloana2 - 1] -> get_tip() == 1 && matrice[linie2 + 1][coloana2 - 1] -> get_culoare() != player)
                            {
                                strcpy(motiv,"nu te poti apropia la mai putin de o pozitie de celalalt rege");
                                return motiv;
                            }

                        matrice[linie1][coloana1] = NULL;
                        if(verific_rege_sah(linie1,coloana1,linie2,coloana2,player,tip) == 1)
                            {
                                switch(tip)
                                    {
                                        case 2: strcpy(motiv, "Intrii in sah de la Regina"); break;
                                        case 3: strcpy(motiv, "Intrii in sah de la Turn"); break;
                                        case 4: strcpy(motiv, "Intrii in sah de la Nebun"); break;
                                        case 5: strcpy(motiv, "Intrii in sah de la Cal"); break;
                                        case 6: strcpy(motiv, "Intrii in sah de la Pion"); break;
                                    }
                                matrice[linie1][coloana1] = X;

                                return motiv;
                            }
                        matrice[linie1][coloana1] = X;

                        /// verificam daca adversarul ramane in sah
                        l1 = linie1;
                        l2 = linie2;
                        c1 = coloana1;
                        c2 = coloana2;
                        tip = 1;
                        if(verifc_adversar_ramane_sah(l1,c1,l2,c2,player,tip) == 1)
                            {
                                    matrice[l1][c1] -> set_sah(1,tip,l2,c2);
                                    set_rege(l1,c1);
                            }

                     } break;
            case 2 : {
                        /// testam daca muta peste o piesa proprie
                        if(matrice[linie2][coloana2])
                        if(matrice[linie2][coloana2] -> get_culoare() == player)
                            {
                                strcpy(motiv,"nu poti cuceri o piesa proprie");
                                return motiv;
                            }

                        /// testam daca pe drum se afla o alta piesa
                        if(linie1 == linie2 && coloana1 < coloana2)
                            for(i = coloana1 + 1; i < coloana2; i++)
                                if(matrice[linie1][i])
                                    {
                                        strcpy(motiv,"regina nu poate sari peste piese");
                                        return motiv;
                                    }

                        if(linie1 == linie2 && coloana1 > coloana2)
                            for(i = coloana1 - 1; i > coloana2; i--)
                                if(matrice[linie1][i])
                                    {
                                        strcpy(motiv,"regina nu poate sari peste piese");
                                        return motiv;
                                    }

                        if(coloana1 == coloana2 && linie1 < linie2)
                            for(i = linie1 + 1; i < linie2; i++)
                                if(matrice[i][coloana1])
                                    {
                                        strcpy(motiv,"regina nu poate sari peste piese");
                                        return motiv;
                                    }

                        if(coloana1 == coloana2 && linie1 > linie2)
                            for(i = linie1 - 1; i > linie2; i--)
                                if(matrice[i][coloana1])
                                    {
                                        strcpy(motiv,"regina nu poate sari peste piese");
                                        return motiv;
                                    }

                        if(linie2 > linie1 && coloana2 > coloana1)
                        for(i = linie1 + 1, j = coloana1 + 1; i < linie2; i++, j++)
                            if(matrice[i][j])
                                {
                                    strcpy(motiv,"regina nu poate sari peste piese piesa");
                                    return motiv;
                                }

                        if(linie2 > linie1 && coloana2 < coloana1)
                        for(i = linie1 + 1, j = coloana1 - 1; i < linie2; i++, j--)
                            if(matrice[i][j])
                                {
                                    strcpy(motiv,"regina nu poate sari peste piese piesa");
                                    return motiv;
                                }

                        if(linie2 < linie1 && coloana2 < coloana1)
                        for(i = linie1 - 1, j = coloana1 - 1; i > linie2; i--, j--)
                            if(matrice[i][j])
                                {
                                    strcpy(motiv,"regina nu poate sari peste o piesa");
                                    return motiv;
                                }

                        if(linie2 < linie1 && coloana2 > coloana1)
                        for(i = linie1 - 1, j = coloana1 + 1; j < coloana2; i--, j++)
                            if(matrice[i][j])
                                {
                                    strcpy(motiv,"regina nu poate sari peste o piesa");
                                    return motiv;
                                }

                        if(verific_raman_sah(linie1, coloana1, linie2, coloana2, player) == 1)
                            {
                                strcpy(motiv,"Daca muti Regina vei ramane in sah");
                                return motiv;
                            }

                        /// verificam daca adversarul ramane in sah
                        l1 = linie1;
                        l2 = linie2;
                        c1 = coloana1;
                        c2 = coloana2;
                        tip = 1;
                        if(verifc_adversar_ramane_sah(l1,c1,l2,c2,player,tip) == 1)
                            {
                                    matrice[l1][c1] -> set_sah(1,tip,l2,c2);
                                    set_rege(l1,c1);
                            }
                        set_sah_inline(linie2,coloana2,player,2);
                        set_sah_indiagonala(linie2,coloana2,player,2);

                     } break;
            case 3 : {
                        /// testam daca muta peste o piesa proprie
                        if(matrice[linie2][coloana2])
                        if(matrice[linie2][coloana2] -> get_culoare() == player)
                            {
                                strcpy(motiv,"nu poti cuceri o piesa proprie");
                                return motiv;
                            }

                        /// testam daca se afla o piesa pe drumul parcurs
                        if(linie1 == linie2 && coloana1 < coloana2)
                            for(i = coloana1 + 1; i < coloana2; i++)
                                if(matrice[linie1][i])
                                    {
                                        strcpy(motiv,"turnul nu poate sari peste piese");
                                        return motiv;
                                    }

                        if(linie1 == linie2 && coloana1 > coloana2)
                            for(i = coloana1 - 1; i > coloana2; i--)
                                if(matrice[linie1][i])
                                    {
                                        strcpy(motiv,"turnul nu poate sari peste piese");
                                        return motiv;
                                    }

                        if(coloana1 == coloana2 && linie1 < linie2)
                            for(i = linie1 + 1; i < linie2; i++)
                                if(matrice[i][coloana1])
                                    {
                                        strcpy(motiv,"turnul nu poate sari peste piese");
                                        return motiv;
                                    }

                        if(coloana1 == coloana2 && linie1 > linie2)
                            for(i = linie1 - 1; i > linie2; i--)
                                if(matrice[i][coloana1])
                                    {
                                        strcpy(motiv,"turnul nu poate sari peste piese");
                                        return motiv;
                                    }

                        if(verific_raman_sah(linie1, coloana1, linie2, coloana2, player) == 1)
                            {
                                strcpy(motiv,"Daca muti Turnul vei ramane in sah");
                                return motiv;
                            }

                        /// verificam daca adversarul ramane in sah
                        /// verificam daca adversarul ramane in sah
                        l1 = linie1;
                        l2 = linie2;
                        c1 = coloana1;
                        c2 = coloana2;
                        tip = 1;
                        if(verifc_adversar_ramane_sah(l1,c1,l2,c2,player,tip) == 1)
                            {
                                    matrice[l1][c1] -> set_sah(1,tip,l2,c2);
                                    set_rege(l1,c1);
                            }
                        set_sah_inline(linie2,coloana2,player,3);

                     } break;
            case 4 : {
                        /// testam daca muta peste o piesa proprie
                        if(matrice[linie2][coloana2])
                        if(matrice[linie2][coloana2] -> get_culoare() == player)
                            {
                                strcpy(motiv,"nu poti cuceri o piesa proprie");
                                return motiv;
                            }

                        /// testam daca pe drum intalneste o piesa
                        if(linie2 > linie1 && coloana2 > coloana1)
                        for(i = linie1 + 1, j = coloana1 + 1; i < linie2; i++, j++)
                            if(matrice[i][j])
                                {
                                    strcpy(motiv,"nebunul nu poate sari peste o piesa");
                                    return motiv;
                                }

                        if(linie2 > linie1 && coloana2 < coloana1)
                        for(i = linie1 + 1, j = coloana1 - 1; i < linie2; i++, j--)
                            if(matrice[i][j])
                                {
                                    strcpy(motiv,"nebunul nu poate sari peste o piesa");
                                    return motiv;
                                }

                        if(linie2 < linie1 && coloana2 < coloana1)
                        for(i = linie1 - 1, j = coloana1 - 1; i > linie2; i--, j--)
                            if(matrice[i][j])
                                {
                                    strcpy(motiv,"nebunul nu poate sari peste o piesa");
                                    return motiv;
                                }

                        if(linie2 < linie1 && coloana2 > coloana1)
                        for(i = linie1 - 1, j = coloana1 + 1; j < coloana2; i--, j++)
                            if(matrice[i][j])
                                {
                                    strcpy(motiv,"nebunul nu poate sari peste o piesa");
                                    return motiv;
                                }

                        if(verific_raman_sah(linie1, coloana1, linie2, coloana2, player) == 1)
                            {
                                strcpy(motiv,"Daca muti Nebunul vei ramane in sah");
                                return motiv;
                            }

                        /// verificam daca adversarul ramane in sah
                        l1 = linie1;
                        l2 = linie2;
                        c1 = coloana1;
                        c2 = coloana2;
                        tip = 1;
                        if(verifc_adversar_ramane_sah(l1,c1,l2,c2,player,tip) == 1)
                            {
                                    matrice[l1][c1] -> set_sah(1,tip,l2,c2);
                                    set_rege(l1,c1);
                            }
                        set_sah_indiagonala(linie2,coloana2,player,4);

                     } break;
            case 5 : {
                        /// testam daca pe potizitia in care se ajunge este o piesa proprie
                        if(matrice[linie2][coloana2])
                        if(matrice[linie2][coloana2] -> get_culoare() == player)
                            {
                                strcpy(motiv,"nu poti cuceri o piesa proprie");
                                return motiv;
                            }

                        if(verific_raman_sah(linie1, coloana1, linie2, coloana2, player) == 1)
                            {
                                strcpy(motiv,"Daca muti Calul vei ramane in sah");
                                return motiv;
                            }

                        /// verificam daca adversarul ramane in sah
                        l1 = linie1;
                        l2 = linie2;
                        c1 = coloana1;
                        c2 = coloana2;
                        tip = 1;
                        if(verifc_adversar_ramane_sah(l1,c1,l2,c2,player,tip) == 1)
                            {
                                    matrice[l1][c1] -> set_sah(1,tip,l2,c2);
                                    set_rege(l1,c1);
                            }

                        /// verificam daca se produce sah de la cal
                        if(matrice[linie2 + 2][coloana2 + 1])
                        if(matrice[linie2 + 2][coloana2 + 1] -> get_tip() == 1 && matrice[linie2 + 2][coloana2 + 1] -> get_culoare() != player)
                            {
                                matrice[linie2 + 2][coloana2 + 1] -> set_sah(1,5,linie2,coloana2);
                                set_rege(linie2 + 2, coloana2 + 1);
                            }

                        if(matrice[linie2 + 1][coloana2 + 2])
                        if(matrice[linie2 + 1][coloana2 + 2] -> get_tip() == 1 && matrice[linie2 + 1][coloana2 + 2] -> get_culoare() != player)
                            {
                                matrice[linie2 + 1][coloana2 + 2] -> set_sah(1,5,linie2,coloana2);
                                set_rege(linie2 + 1, coloana2 + 2);
                            }

                        if(matrice[linie2 - 2][coloana2 + 1])
                        if(matrice[linie2 - 2][coloana2 + 1] -> get_tip() == 1 && matrice[linie2 - 2][coloana2 + 1] -> get_culoare() != player)
                            {
                                matrice[linie2 - 2][coloana2 + 1] -> set_sah(1,5,linie2,coloana2);
                                set_rege(linie2 - 2, coloana2 + 1);
                            }

                        if(matrice[linie2 + 2][coloana2 - 1])
                        if(matrice[linie2 + 2][coloana2 - 1] -> get_tip() == 1 && matrice[linie2 + 2][coloana2 - 1] -> get_culoare() != player)
                            {
                                matrice[linie2 + 2][coloana2 - 1] -> set_sah(1,5,linie2,coloana2);
                                set_rege(linie2 + 2, coloana2 - 1);
                            }

                        if(matrice[linie2 + 1][coloana2 - 2])
                        if(matrice[linie2 + 1][coloana2 - 2] -> get_tip() == 1 && matrice[linie2 + 1][coloana2 - 2] -> get_culoare() != player)
                            {
                                matrice[linie2 + 1][coloana2 - 2] -> set_sah(1,5,linie2,coloana2);
                                set_rege(linie2 + 1, coloana2 - 2);
                            }

                        if(matrice[linie2 - 1][coloana2 + 2])
                        if(matrice[linie2 - 1][coloana2 + 2] -> get_tip() == 1 && matrice[linie2 - 1][coloana2 + 2] -> get_culoare() != player)
                            {
                                matrice[linie2 - 1][coloana2 + 2] -> set_sah(1,5,linie2,coloana2);
                                set_rege(linie2 - 1, coloana2 + 2);
                            }

                        if(matrice[linie2 + 2][coloana2 - 1])
                        if(matrice[linie2 + 2][coloana2 - 1] -> get_tip() == 1 && matrice[linie2 + 2][coloana2 - 1] -> get_culoare() != player)
                            {
                                matrice[linie2 + 2][coloana2 - 1] -> set_sah(1,5,linie2,coloana2);
                                set_rege(linie2 + 2, coloana2 - 1);
                            }

                        if(matrice[linie2 - 1][coloana2 - 2])
                        if(matrice[linie2 - 1][coloana2 - 2] -> get_tip() == 1 && matrice[linie2 - 1][coloana2 - 2] -> get_culoare() != player)
                            {
                                matrice[linie2 - 1][coloana2 - 2] -> set_sah(1,5,linie2,coloana2);
                                set_rege(linie2 - 1, coloana2 - 2);
                            }

                     } break;
            case 6 : {
                        if(player == 1)
                            {
                                /// verificam daca pozitia de mutare este libera
                                if(coloana1 == coloana2 && matrice[linie2][coloana2])
                                    {
                                        strcpy(motiv,"pionul nu poate muta peste piesa de la pozitia indicata");
                                        matrice[linie1][coloana1] -> reset_nr_mutari();
                                        return motiv;
                                    }

                                /// verificam daca muta in diagonala trebuie sa se afla o piesa de-a adversarului
                                if(abs(coloana1 - coloana2) == 1)
                                    if(!matrice[linie2][coloana2])
                                        {
                                            strcpy(motiv,"pionul nu poate muta in diagonala daca nu se afla o piesa de-a adversarului");
                                            matrice[linie1][coloana1] -> reset_nr_mutari();
                                            return motiv;
                                        }

                                /// verificam daca se afla o piesa peste care nu poate trece
                                if(coloana1 == coloana2 && (linie2 - linie1 == 2))
                                    if(matrice[linie1 + 1][coloana1])
                                        {
                                            strcpy(motiv,"pionul nu poate sari peste o piesa");
                                            matrice[linie1][coloana1] -> reset_nr_mutari();
                                            return motiv;
                                        }

                                /// verificam daca in potitia in care muta se afla o piesa de a sa
                                if(matrice[linie2][coloana2])
                                if(matrice[linie2][coloana2] -> get_culoare() == player)
                                    {
                                        strcpy(motiv,"nu poti cuceri o piesa proprie");
                                        matrice[linie1][coloana1] -> reset_nr_mutari();
                                        return motiv;
                                    }

                                if(verific_raman_sah(linie1, coloana1, linie2, coloana2, player) == 1)
                                    {
                                        strcpy(motiv,"Daca muti Pionul vei ramane in sah");
                                        return motiv;
                                    }

                                /// verificam daca adversarul ramane in sah
                                l1 = linie1;
                                l2 = linie2;
                                c1 = coloana1;
                                c2 = coloana2;
                                tip = 1;
                                if(verifc_adversar_ramane_sah(l1,c1,l2,c2,player,tip) == 1)
                                    {
                                        matrice[l1][c1] -> set_sah(1,tip,l2,c2);
                                        set_rege(l1,c1);
                                    }

                                /// verificam daca se produce sah de la pion alb
                                if(matrice[linie2 + 1][coloana2 - 1])
                                    if(matrice[linie2 + 1][coloana2 - 1] -> get_tip() == 1 && matrice[linie2 + 1][coloana2 - 1] -> get_culoare() != player)
                                        {
                                            matrice[linie2 + 1][coloana2 - 1] -> set_sah(1, 6, linie2, coloana2);
                                            set_rege(linie2 + 1, coloana2 - 1);
                                        }

                                /// verificam daca se produce sah de la pion negru
                                if(matrice[linie2 + 1][coloana2 + 1])
                                    if(matrice[linie2 + 1][coloana2 + 1] -> get_tip() == 1 && matrice[linie2 + 1][coloana2 + 1] -> get_culoare() != player)
                                        {
                                            matrice[linie2 + 1][coloana2 + 1] -> set_sah(1, 6, linie2, coloana2);
                                            set_rege(linie2 + 1, coloana2 + 1);
                                        }
                            }

                        if(player == 2)
                            {
                                /// verificam daca pozitia de mutare este libera
                                if(coloana1 == coloana2 && matrice[linie2][coloana2])
                                    {
                                        strcpy(motiv,"pionul nu poate muta peste piesa de la pozitia indicata");
                                        matrice[linie1][coloana1] -> reset_nr_mutari();
                                        return motiv;
                                    }

                                /// verificam daca muta in diagonala trebuie sa se afla o piesa de-a adversarului
                                if(abs(coloana1 - coloana2) == 1)
                                    if(!matrice[linie2][coloana2])
                                        {
                                            strcpy(motiv,"pionul nu poate muta in diagonala daca nu se afla o piesa de-a adversarului");
                                            matrice[linie1][coloana1] -> reset_nr_mutari();
                                            return motiv;
                                        }

                                /// verificam daca se afla o piesa peste care nu poate trece
                                if(coloana1 == coloana2 && (linie1 - linie2 == 2))
                                    if(matrice[linie1 - 1][coloana1])
                                        {
                                            strcpy(motiv,"pionul nu poate sari peste o piesa");
                                            matrice[linie1][coloana1] -> reset_nr_mutari();
                                            return motiv;
                                        }

                                /// verificam daca in potitia in care muta se afla o piesa de a sa
                                if(matrice[linie2][coloana2])
                                if(matrice[linie2][coloana2] -> get_culoare() == player)
                                    {
                                        strcpy(motiv,"nu poti cuceri o piesa proprie");
                                        matrice[linie1][coloana1] -> reset_nr_mutari();
                                        return motiv;
                                    }

                                if(verific_raman_sah(linie1, coloana1, linie2, coloana2, player) == 1)
                                    {
                                        strcpy(motiv,"Daca muti Pionul vei ramane in sah");
                                        matrice[linie1][coloana1] -> reset_nr_mutari();
                                        return motiv;
                                    }

                                /// verificam daca adversarul ramane in sah
                                l1 = linie1;
                                l2 = linie2;
                                c1 = coloana1;
                                c2 = coloana2;
                                tip = 1;
                                if(verifc_adversar_ramane_sah(l1,c1,l2,c2,player,tip) == 1)
                                    {
                                        matrice[l1][c1] -> set_sah(1,tip,l2,c2);
                                        set_rege(l1,c1);
                                    }

                                /// verificam daca se produce sah de la pion alb
                                if(matrice[linie2 - 1][coloana2 - 1])
                                    if(matrice[linie2 - 1][coloana2 - 1] -> get_tip() == 1 && matrice[linie2 - 1][coloana2 - 1] -> get_culoare() != player)
                                        {
                                            matrice[linie2 - 1][coloana2 - 1] -> set_sah(1, 6, linie2, coloana2);
                                            set_rege(linie2 - 1, coloana2 - 1);
                                        }

                                 /// verificam daca se produce sah de la pion alb
                                if(matrice[linie2 - 1][coloana2 + 1])
                                    if(matrice[linie2 - 1][coloana2 + 1] -> get_tip() == 1 && matrice[linie2 - 1][coloana2 + 1] -> get_culoare() != player)
                                        {
                                            matrice[linie2 - 1][coloana2 + 1] -> set_sah(1, 6, linie2, coloana2);
                                            set_rege(linie2 - 1, coloana2 + 1);
                                        }
                                }
                        } break;
            }
        return NULL;
    }

char* Tabla::validare_mutare_sah_pat(int linie1, int coloana1, int linie2, int coloana2, int player, char motiv[100])
    {
        int tip_piesa, i, j, sw = 0, ok, l1, l2, c1, c2, tip;
        Piesa *X = new Rege(linie1,coloana1,player);

        tip_piesa = matrice[linie1][coloana1] -> get_tip();

        switch(tip_piesa)
            {
            case 1 : {
                        /// testam daca pe potizitia in care se ajunge este o piesa proprie
                        if(matrice[linie2][coloana2])
                        if(matrice[linie2][coloana2] -> get_culoare() == player)
                            {
                                strcpy(motiv,"nu poti cuceri o piesa proprie");
                                return motiv;
                            }

                        /// testam daca se apropie de celalalt rege
                        if(matrice[linie2][coloana2 - 1])
                           if(matrice[linie2][coloana2 - 1] -> get_tip() == 1 && matrice[linie2][coloana2 - 1] -> get_culoare() != player)
                            {
                                strcpy(motiv,"nu te poti apropia la mai putin de o pozitie de celalalt rege");
                                return motiv;
                            }

                         if(matrice[linie2 - 1][coloana2 - 1])
                           if(matrice[linie2 - 1][coloana2 - 1] -> get_tip() == 1 && matrice[linie2 - 1][coloana2 - 1] -> get_culoare() != player)
                            {
                                strcpy(motiv,"nu te poti apropia la mai putin de o pozitie de celalalt rege");
                                return motiv;
                            }

                         if(matrice[linie2 - 1][coloana2])
                           if(matrice[linie2 - 1][coloana2] -> get_tip() == 1 && matrice[linie2 - 1][coloana2] -> get_culoare() != player)
                            {
                                strcpy(motiv,"nu te poti apropia la mai putin de o pozitie de celalalt rege");
                                return motiv;
                            }

                         if(matrice[linie2 - 1][coloana2 + 1])
                           if(matrice[linie2 - 1][coloana2 + 1] -> get_tip() == 1 && matrice[linie2 - 1][coloana2 + 1] -> get_culoare() != player)
                            {
                                strcpy(motiv,"nu te poti apropia la mai putin de o pozitie de celalalt rege");
                                return motiv;
                            }

                         if(matrice[linie2][coloana2 + 1])
                           if(matrice[linie2][coloana2 + 1] -> get_tip() == 1 && matrice[linie2][coloana2 + 1] -> get_culoare() != player)
                            {
                                strcpy(motiv,"nu te poti apropia la mai putin de o pozitie de celalalt rege");
                                return motiv;
                            }

                         if(matrice[linie2 + 1][coloana2 + 1])
                           if(matrice[linie2 + 1][coloana2 + 1] -> get_tip() == 1 && matrice[linie2 + 1][coloana2 + 1] -> get_culoare() != player)
                            {
                                strcpy(motiv,"nu te poti apropia la mai putin de o pozitie de celalalt rege");
                                return motiv;
                            }

                         if(matrice[linie2 + 1][coloana2])
                           if(matrice[linie2 + 1][coloana2] -> get_tip() == 1 && matrice[linie2 + 1][coloana2] -> get_culoare() != player)
                            {
                                strcpy(motiv,"nu te poti apropia la mai putin de o pozitie de celalalt rege");
                                return motiv;
                            }

                         if(matrice[linie2 + 1][coloana2 - 1])
                           if(matrice[linie2 + 1][coloana2 - 1] -> get_tip() == 1 && matrice[linie2 + 1][coloana2 - 1] -> get_culoare() != player)
                            {
                                strcpy(motiv,"nu te poti apropia la mai putin de o pozitie de celalalt rege");
                                return motiv;
                            }

                        matrice[linie1][coloana1] = NULL;
                        if(verific_rege_sah(linie1,coloana1,linie2,coloana2,player,tip) == 1)
                            {
                                switch(tip)
                                    {
                                        case 2: strcpy(motiv, "Intrii in sah de la Regina"); break;
                                        case 3: strcpy(motiv, "Intrii in sah de la Turn"); break;
                                        case 4: strcpy(motiv, "Intrii in sah de la Nebun"); break;
                                        case 5: strcpy(motiv, "Intrii in sah de la Cal"); break;
                                        case 6: strcpy(motiv, "Intrii in sah de la Pion"); break;
                                    }
                                matrice[linie1][coloana1] = X;

                                return motiv;
                            }
                        matrice[linie1][coloana1] = X;

                     } break;
            case 2 : {
                        /// testam daca muta peste o piesa proprie
                        if(matrice[linie2][coloana2])
                        if(matrice[linie2][coloana2] -> get_culoare() == player)
                            {
                                strcpy(motiv,"nu poti cuceri o piesa proprie");
                                return motiv;
                            }

                        /// testam daca pe drum se afla o alta piesa
                        if(linie1 == linie2 && coloana1 < coloana2)
                            for(i = coloana1 + 1; i < coloana2; i++)
                                if(matrice[linie1][i])
                                    {
                                        strcpy(motiv,"regina nu poate sari peste piese");
                                        return motiv;
                                    }

                        if(linie1 == linie2 && coloana1 > coloana2)
                            for(i = coloana1 - 1; i > coloana2; i--)
                                if(matrice[linie1][i])
                                    {
                                        strcpy(motiv,"regina nu poate sari peste piese");
                                        return motiv;
                                    }

                        if(coloana1 == coloana2 && linie1 < linie2)
                            for(i = linie1 + 1; i < linie2; i++)
                                if(matrice[i][coloana1])
                                    {
                                        strcpy(motiv,"regina nu poate sari peste piese");
                                        return motiv;
                                    }

                        if(coloana1 == coloana2 && linie1 > linie2)
                            for(i = linie1 - 1; i > linie2; i--)
                                if(matrice[i][coloana1])
                                    {
                                        strcpy(motiv,"regina nu poate sari peste piese");
                                        return motiv;
                                    }

                        if(linie2 > linie1 && coloana2 > coloana1)
                        for(i = linie1 + 1, j = coloana1 + 1; i < linie2; i++, j++)
                            if(matrice[i][j])
                                {
                                    strcpy(motiv,"regina nu poate sari peste piese piesa");
                                    return motiv;
                                }

                        if(linie2 > linie1 && coloana2 < coloana1)
                        for(i = linie1 + 1, j = coloana1 - 1; i < linie2; i++, j--)
                            if(matrice[i][j])
                                {
                                    strcpy(motiv,"regina nu poate sari peste piese piesa");
                                    return motiv;
                                }

                        if(linie2 < linie1 && coloana2 < coloana1)
                        for(i = linie1 - 1, j = coloana1 - 1; i > linie2; i--, j--)
                            if(matrice[i][j])
                                {
                                    strcpy(motiv,"regina nu poate sari peste o piesa");
                                    return motiv;
                                }

                        if(linie2 < linie1 && coloana2 > coloana1)
                        for(i = linie1 - 1, j = coloana1 + 1; j < coloana2; i--, j++)
                            if(matrice[i][j])
                                {
                                    strcpy(motiv,"regina nu poate sari peste o piesa");
                                    return motiv;
                                }

                        if(verific_raman_sah(linie1, coloana1, linie2, coloana2, player) == 1)
                            {
                                strcpy(motiv,"Daca muti Regina vei ramane in sah");
                                return motiv;
                            }

                     } break;
            case 3 : {
                        /// testam daca muta peste o piesa proprie
                        if(matrice[linie2][coloana2])
                        if(matrice[linie2][coloana2] -> get_culoare() == player)
                            {
                                strcpy(motiv,"nu poti cuceri o piesa proprie");
                                return motiv;
                            }

                        /// testam daca se afla o piesa pe drumul parcurs
                        if(linie1 == linie2 && coloana1 < coloana2)
                            for(i = coloana1 + 1; i < coloana2; i++)
                                if(matrice[linie1][i])
                                    {
                                        strcpy(motiv,"turnul nu poate sari peste piese");
                                        return motiv;
                                    }

                        if(linie1 == linie2 && coloana1 > coloana2)
                            for(i = coloana1 - 1; i > coloana2; i--)
                                if(matrice[linie1][i])
                                    {
                                        strcpy(motiv,"turnul nu poate sari peste piese");
                                        return motiv;
                                    }

                        if(coloana1 == coloana2 && linie1 < linie2)
                            for(i = linie1 + 1; i < linie2; i++)
                                if(matrice[i][coloana1])
                                    {
                                        strcpy(motiv,"turnul nu poate sari peste piese");
                                        return motiv;
                                    }

                        if(coloana1 == coloana2 && linie1 > linie2)
                            for(i = linie1 - 1; i > linie2; i--)
                                if(matrice[i][coloana1])
                                    {
                                        strcpy(motiv,"turnul nu poate sari peste piese");
                                        return motiv;
                                    }

                        if(verific_raman_sah(linie1, coloana1, linie2, coloana2, player) == 1)
                            {
                                strcpy(motiv,"Daca muti Turnul vei ramane in sah");
                                return motiv;
                            }

                     } break;
            case 4 : {
                        /// testam daca muta peste o piesa proprie
                        if(matrice[linie2][coloana2])
                        if(matrice[linie2][coloana2] -> get_culoare() == player)
                            {
                                strcpy(motiv,"nu poti cuceri o piesa proprie");
                                return motiv;
                            }

                        /// testam daca pe drum intalneste o piesa
                        if(linie2 > linie1 && coloana2 > coloana1)
                        for(i = linie1 + 1, j = coloana1 + 1; i < linie2; i++, j++)
                            if(matrice[i][j])
                                {
                                    strcpy(motiv,"nebunul nu poate sari peste o piesa");
                                    return motiv;
                                }

                        if(linie2 > linie1 && coloana2 < coloana1)
                        for(i = linie1 + 1, j = coloana1 - 1; i < linie2; i++, j--)
                            if(matrice[i][j])
                                {
                                    strcpy(motiv,"nebunul nu poate sari peste o piesa");
                                    return motiv;
                                }

                        if(linie2 < linie1 && coloana2 < coloana1)
                        for(i = linie1 - 1, j = coloana1 - 1; i > linie2; i--, j--)
                            if(matrice[i][j])
                                {
                                    strcpy(motiv,"nebunul nu poate sari peste o piesa");
                                    return motiv;
                                }

                        if(linie2 < linie1 && coloana2 > coloana1)
                        for(i = linie1 - 1, j = coloana1 + 1; j < coloana2; i--, j++)
                            if(matrice[i][j])
                                {
                                    strcpy(motiv,"nebunul nu poate sari peste o piesa");
                                    return motiv;
                                }

                        if(verific_raman_sah(linie1, coloana1, linie2, coloana2, player) == 1)
                            {
                                strcpy(motiv,"Daca muti Nebunul vei ramane in sah");
                                return motiv;
                            }

                     } break;
            case 5 : {
                        /// testam daca pe potizitia in care se ajunge este o piesa proprie
                        if(matrice[linie2][coloana2])
                        if(matrice[linie2][coloana2] -> get_culoare() == player)
                            {
                                strcpy(motiv,"nu poti cuceri o piesa proprie");
                                return motiv;
                            }

                        if(verific_raman_sah(linie1, coloana1, linie2, coloana2, player) == 1)
                            {
                                strcpy(motiv,"Daca muti Calul vei ramane in sah");
                                return motiv;
                            }

                     } break;
            case 6 : {
                        if(player == 1)
                            {
                                /// verificam daca pozitia de mutare este libera
                                if(coloana1 == coloana2 && matrice[linie2][coloana2])
                                    {
                                        strcpy(motiv,"pionul nu poate muta peste piesa de la pozitia indicata");
                                        matrice[linie1][coloana1] -> reset_nr_mutari();
                                        return motiv;
                                    }

                                /// verificam daca muta in diagonala trebuie sa se afla o piesa de-a adversarului
                                if(abs(coloana1 - coloana2) == 1)
                                    if(!matrice[linie2][coloana2])
                                        {
                                            strcpy(motiv,"pionul nu poate muta in diagonala daca nu se afla o piesa de-a adversarului");
                                            matrice[linie1][coloana1] -> reset_nr_mutari();
                                            return motiv;
                                        }

                                /// verificam daca se afla o piesa peste care nu poate trece
                                if(coloana1 == coloana2 && (linie2 - linie1 == 2))
                                    if(matrice[linie1 + 1][coloana1])
                                        {
                                            strcpy(motiv,"pionul nu poate sari peste o piesa");
                                            matrice[linie1][coloana1] -> reset_nr_mutari();
                                            return motiv;
                                        }

                                /// verificam daca in potitia in care muta se afla o piesa de a sa
                                if(matrice[linie2][coloana2])
                                if(matrice[linie2][coloana2] -> get_culoare() == player)
                                    {
                                        strcpy(motiv,"nu poti cuceri o piesa proprie");
                                        matrice[linie1][coloana1] -> reset_nr_mutari();
                                        return motiv;
                                    }

                                if(verific_raman_sah(linie1, coloana1, linie2, coloana2, player) == 1)
                                    {
                                        strcpy(motiv,"Daca muti Pionul vei ramane in sah");
                                        matrice[linie1][coloana1] -> reset_nr_mutari();
                                        return motiv;
                                    }
                            }

                        if(player == 2)
                            {
                                /// verificam daca pozitia de mutare este libera
                                if(coloana1 == coloana2 && matrice[linie2][coloana2])
                                    {
                                        strcpy(motiv,"pionul nu poate muta peste piesa de la pozitia indicata");
                                        matrice[linie1][coloana1] -> reset_nr_mutari();
                                        return motiv;
                                    }

                                /// verificam daca muta in diagonala trebuie sa se afla o piesa de-a adversarului
                                if(abs(coloana1 - coloana2) == 1)
                                    if(!matrice[linie2][coloana2])
                                        {
                                            strcpy(motiv,"pionul nu poate muta in diagonala daca nu se afla o piesa de-a adversarului");
                                            matrice[linie1][coloana1] -> reset_nr_mutari();
                                            return motiv;
                                        }

                                /// verificam daca se afla o piesa peste care nu poate trece
                                if(coloana1 == coloana2 && (linie1 - linie2 == 2))
                                    if(matrice[linie1 - 1][coloana1])
                                        {
                                            strcpy(motiv,"pionul nu poate sari peste o piesa");
                                            matrice[linie1][coloana1] -> reset_nr_mutari();
                                            return motiv;
                                        }

                                /// verificam daca in potitia in care muta se afla o piesa de a sa
                                if(matrice[linie2][coloana2])
                                if(matrice[linie2][coloana2] -> get_culoare() == player)
                                    {
                                        strcpy(motiv,"nu poti cuceri o piesa proprie");
                                        matrice[linie1][coloana1] -> reset_nr_mutari();
                                        return motiv;
                                    }

                                if(verific_raman_sah(linie1, coloana1, linie2, coloana2, player) == 1)
                                    {
                                        strcpy(motiv,"Daca muti Pionul vei ramane in sah");
                                        matrice[linie1][coloana1] -> reset_nr_mutari();
                                        return motiv;
                                    }
                                }
                        } break;
            }
        return NULL;
    }

char* Tabla::validare_iesire_sah(int linie1, int coloana1, int linie2, int coloana2, int &linie_rege, int &coloana_rege, int &linie_piesa, int &coloana_piesa, int &tip_piesa, int player, char motiv[100], int intrare)
    {
	int i, j, ok, tip;
	Piesa *X = new Rege(linie1,coloana1,player);

            ok = 0;
            switch(tip_piesa)
                {
                    case 2: {
                                /// verificam daca luam piesa ce produce sah
                                if(linie_piesa != linie2 || coloana_piesa != coloana2)
                                    strcpy(motiv,"Sunteti in sah de la Regina");
                                else
                                    ok = 1;

                                /// verificam daca punem o piesa pe traseu pe baza la turn
                                if(linie_rege == linie_piesa && coloana_rege < coloana_piesa)
                                    for(i = coloana_rege + 1; i < coloana_piesa; i++)
                                        if(coloana2 != i || linie_rege)
                                            {
                                                strcpy(motiv,"Sunteti in sah de la Regina");
                                             //   break;
                                            }
                                        else
                                            {
                                                ok = 1;
                                                break;
                                            }

                                if(linie_rege > linie_piesa && coloana_rege == coloana_piesa)
                                    for(i = linie_rege - 1; i > linie_piesa; i--)
                                        if(linie2 != i || coloana2 != coloana_rege)
                                            {
                                                strcpy(motiv,"Sunteti in sah de la Regina");
                                             //   break;
                                            }
                                        else
                                            {
                                                ok = 1;
                                                break;
                                            }

                                if(linie_rege < linie_piesa && coloana_rege == coloana_piesa)
                                    for(i = linie_rege + 1; i < linie_piesa; i++)
                                        if(linie2 != i || coloana2 != coloana_rege)
                                            {
                                                strcpy(motiv,"Sunteti in sah de la Regina");
                                             //   break;
                                            }
                                        else
                                            {
                                                ok = 1;
                                                break;
                                            }

                                if(linie_rege == linie_piesa && coloana_rege > coloana_piesa)
                                    for(i = coloana_rege - 1; i > coloana_piesa; i--)
                                        if(coloana2 != i || linie2 != linie_rege)
                                            {
                                                strcpy(motiv,"Sunteti in sah de la Regina");
                                             //   break;
                                            }
                                        else
                                            {
                                                ok = 1;
                                                break;
                                            }

                                /// verificam daca punem o piesa pe traseu pe baza la nebun
                                if(linie_piesa < linie_rege && coloana_piesa < coloana_rege)
                                    for(i = linie_piesa + 1, j = coloana_piesa + 1; i < linie_rege, j < coloana_rege; i++, j++)
                                        if(linie2 != i || coloana2 != j)
                                            {
                                                strcpy(motiv,"Sunteti in sah de la Regina");
                                                //break;
                                            }
                                        else
                                            {
                                                ok = 1;
                                                break;
                                            }

                                if(linie_piesa < linie_rege && coloana_piesa > coloana_rege)
                                    for(i = linie_piesa + 1, j = coloana_piesa - 1; i < linie_rege, j > coloana_rege; i++, j--)
                                        if(linie2 != i || coloana2 != j)
                                            {
                                               strcpy(motiv,"Sunteti in sah de la Regina");
                                                //break;
                                            }
                                        else
                                            {
                                                ok = 1;
                                                break;
                                            }

                                if(linie_piesa > linie_rege && coloana_piesa > coloana_rege)
                                    for(i = linie_piesa - 1, j = coloana_piesa - 1; i < linie_rege, j > coloana_rege; i--, j--)
                                        if(linie2 != i || coloana2 != j)
                                            {
                                                strcpy(motiv,"Sunteti in sah de la Regina");
                                                //break;
                                            }
                                        else
                                            {
                                                ok = 1;
                                                break;
                                            }

                                if(linie_piesa > linie_rege && coloana_piesa < coloana_rege)
                                    for(i = linie_piesa - 1, j = coloana_piesa + 1; i > linie_rege, j < coloana_rege; i--, j++)
                                        if(linie2 != i || coloana2 != j)
                                            {
                                                strcpy(motiv,"Sunteti in sah de la Regina");
                                                //break;
                                            }
                                        else
                                            {
                                                ok = 1;
                                                break;
                                            }

                                /// verificam daca plecam cu regele din zona de sah
                                if(ok != 1)
                                    {
                                        strcpy(motiv,"Sunteti in sah de la Regina");
                                        if(matrice[linie1][coloana1] -> get_tip() == 1)
                                        if((linie_piesa != linie2 || coloana_piesa != coloana2))
                                            {
                                                matrice[linie1][coloana1] = X;
                                                if(verific_rege_sah(linie1,coloana1,linie2,coloana2,player,tip) == 1)
                                                {
                                                    switch(tip)
                                                    {
                                                        case 2: strcpy(motiv, "Intrii in sah de la Regina"); break;
                                                        case 3: strcpy(motiv, "Intrii in sah de la Turn"); break;
                                                        case 4: strcpy(motiv, "Intrii in sah de la Nebun"); break;
                                                        case 5: strcpy(motiv, "Intrii in sah de la Cal"); break;
                                                        case 6: strcpy(motiv, "Intrii in sah de la Pion"); break;
                                                    }
                                                    return motiv;
                                                }
                                                matrice[linie1][coloana1] = X;
                                                ok = 1;
                                                break;
                                            }
                                    }

                                if(ok != 1)
                                    return motiv;

                                if(intrare == 25)
                                    get_rege() -> set_sah(0,0,0,0);

                            } break;
                    case 3: {

                                /// verificam daca luam piesa ce produce sah
                                if(linie_piesa != linie2 || coloana_piesa != coloana2)
                                    strcpy(motiv,"Sunteti in sah de la Turn");
                               else
                                    ok = 1;

                                /// verificam daca punem o piesa pe traseu
                                if(linie_rege == linie_piesa && coloana_rege < coloana_piesa)
                                    for(i = coloana_rege + 1; i < coloana_piesa; i++)
                                        if(coloana2 != i || linie2 != linie_rege)
                                            {
                                                strcpy(motiv,"Sunteti in sah de la Turn");
                                             // break;
                                            }
                                        else
                                            {
                                                ok = 1;
                                                break;
                                            }

                                if(linie_rege > linie_piesa && coloana_rege == coloana_piesa)
                                    for(i = linie_rege - 1; i > linie_piesa; i--)
                                        if(linie2 != i || coloana2 != coloana_rege)
                                            {
                                                strcpy(motiv,"Sunteti in sah de la Turn");
                                             //   break;
                                            }
                                        else
                                            {
                                                ok = 1;
                                                break;
                                            }

                                if(linie_rege < linie_piesa && coloana_rege == coloana_piesa)
                                    for(i = linie_rege + 1; i < linie_piesa; i++)
                                        if(linie2 != i || coloana2 != coloana_rege)
                                            {
                                                strcpy(motiv,"Sunteti in sah de la Turn");
                                             //   break;
                                            }
                                        else
                                            {
                                                ok = 1;
                                                break;
                                            }

                                if(linie_rege == linie_piesa && coloana_rege > coloana_piesa)
                                    for(i = coloana_rege - 1; i > coloana_piesa; i--)
                                        if(coloana2 != i || linie2 != linie_rege)
                                            {
                                                strcpy(motiv,"Sunteti in sah de la Turn");
                                             //   break;
                                            }
                                        else
                                            {
                                                ok = 1;
                                                break;
                                            }

                                /// verificam daca plecam cu regele din zona de sah
                                if(ok != 1)
                                    {
                                        strcpy(motiv,"Sunteti in sah de la Turn");
                                        if(matrice[linie1][coloana1] -> get_tip() == 1)
                                        if((linie_piesa != linie2 || coloana_piesa != coloana2))
                                            {
                                                matrice[linie1][coloana1] = X;
                                                if(verific_rege_sah(linie1,coloana1,linie2,coloana2,player,tip) == 1)
                                                {
                                                    switch(tip)
                                                    {
                                                        case 2: strcpy(motiv, "Intrii in sah de la Regina"); break;
                                                        case 3: strcpy(motiv, "Intrii in sah de la Turn"); break;
                                                        case 4: strcpy(motiv, "Intrii in sah de la Nebun"); break;
                                                        case 5: strcpy(motiv, "Intrii in sah de la Cal"); break;
                                                        case 6: strcpy(motiv, "Intrii in sah de la Pion"); break;
                                                    }
                                                    return motiv;
                                                }
                                                matrice[linie1][coloana1] = X;
                                                ok = 1;
                                                break;
                                            }
                                    }

                                if(ok != 1)
                                    return motiv;

                                if(intrare == 25)
                                    get_rege() -> set_sah(0,0,0,0);

                            } break;
                    case 4: {

                                /// verificam daca luam piesa ce produce sah
                                if(linie_piesa != linie2 || coloana_piesa != coloana2)
                                    strcpy(motiv,"Sunteti in sah de la Nebun");
                                else
                                    ok = 1;

                                /// verificam daca punem o piesa pe traseu
                                if(linie_piesa < linie_rege && coloana_piesa < coloana_rege)
                                    for(i = linie_piesa + 1, j = coloana_piesa + 1; i < linie_rege, j < coloana_rege; i++, j++)
                                        if(linie2 != i || coloana2 != j)
                                            {
                                                strcpy(motiv,"Sunteti in sah de la Nebun");
                                                //break;
                                            }
                                        else
                                            {
                                                ok = 1;
                                                break;
                                            }

                                if(linie_piesa < linie_rege && coloana_piesa > coloana_rege)
                                    for(i = linie_piesa + 1, j = coloana_piesa - 1; i < linie_rege, j > coloana_rege; i++, j--)
                                        if(linie2 != i || coloana2 != j)
                                            {
                                                strcpy(motiv,"Sunteti in sah de la Nebun");
                                                //break;
                                            }
                                        else
                                            {
                                                ok = 1;
                                                break;
                                            }

                                if(linie_piesa > linie_rege && coloana_piesa > coloana_rege)
                                    for(i = linie_piesa - 1, j = coloana_piesa - 1; i < linie_rege, j > coloana_rege; i--, j--)
                                        if(linie2 != i || coloana2 != j)
                                            {
                                                strcpy(motiv,"Sunteti in sah de la Nebun");
                                                //break;
                                            }
                                        else
                                            {
                                                ok = 1;
                                                break;
                                            }

                                if(linie_piesa > linie_rege && coloana_piesa < coloana_rege)
                                    for(i = linie_piesa - 1, j = coloana_piesa + 1; i > linie_rege, j < coloana_rege; i--, j++)
                                        if(linie2 != i || coloana2 != j)
                                            {
                                                strcpy(motiv,"Sunteti in sah de la Nebun");
                                                //break;
                                            }
                                        else
                                            {
                                                ok = 1;
                                                break;
                                            }

                                /// verificam daca plecam cu regele din zona de sah
                                if(ok != 1)
                                    {
                                        strcpy(motiv,"Sunteti in sah de la Nebun");
                                        if(matrice[linie1][coloana1] -> get_tip() == 1)
                                        if((linie_piesa != linie2 || coloana_piesa != coloana2))
                                            {
                                                matrice[linie1][coloana1] = X;
                                                if(verific_rege_sah(linie1,coloana1,linie2,coloana2,player,tip) == 1)
                                                {
                                                    switch(tip)
                                                    {
                                                        case 2: strcpy(motiv, "Intrii in sah de la Regina"); break;
                                                        case 3: strcpy(motiv, "Intrii in sah de la Turn"); break;
                                                        case 4: strcpy(motiv, "Intrii in sah de la Nebun"); break;
                                                        case 5: strcpy(motiv, "Intrii in sah de la Cal"); break;
                                                        case 6: strcpy(motiv, "Intrii in sah de la Pion"); break;
                                                    }
                                                    return motiv;
                                                }
                                                matrice[linie1][coloana1] = X;
                                                ok = 1;
                                                break;
                                            }
                                    }

                                if(ok != 1)
                                    return motiv;

                                if(intrare == 25)
                                    get_rege() -> set_sah(0,0,0,0);

                            } break;
                    case 5: {
                                /// verificam daca luam piesa ce produce sah
                                if(linie_piesa != linie2 || coloana_piesa != coloana2)
                                    strcpy(motiv,"Sunteti in sah de la Cal");
                                else
                                    ok = 1;

                                /// verificam daca plecam cu regele din zona de sah
                                if(ok != 1)
                                    {
                                        strcpy(motiv,"Sunteti in sah de la Cal");
                                        if(matrice[linie1][coloana1] -> get_tip() == 1)
                                        if((linie_piesa != linie2 || coloana_piesa != coloana2))
                                            {
                                                matrice[linie1][coloana1] = X;
                                                if(verific_rege_sah(linie1,coloana1,linie2,coloana2,player,tip) == 1)
                                                {
                                                    switch(tip)
                                                    {
                                                        case 2: strcpy(motiv, "Intrii in sah de la Regina"); break;
                                                        case 3: strcpy(motiv, "Intrii in sah de la Turn"); break;
                                                        case 4: strcpy(motiv, "Intrii in sah de la Nebun"); break;
                                                        case 5: strcpy(motiv, "Intrii in sah de la Cal"); break;
                                                        case 6: strcpy(motiv, "Intrii in sah de la Pion"); break;
                                                    }
                                                    return motiv;
                                                }
                                                matrice[linie1][coloana1] = X;
                                                ok = 1;
                                                break;
                                            }
                                    }

                                if(ok != 1)
                                    return motiv;

                                if(intrare == 25)
                                    get_rege() -> set_sah(0,0,0,0);

                            } break;
                    case 6: {
                                /// verificam daca luam piesa ce produce sah
                                if(linie_piesa != linie2 || coloana_piesa != coloana2)
                                    strcpy(motiv,"Sunteti in sah de la Pion");
                                else
                                    ok = 1;

                                /// verificam daca plecam cu regele din zona de sah
                                if(ok != 1)
                                    {
                                        strcpy(motiv,"Sunteti in sah de la Pion");
                                        if(matrice[linie1][coloana1] -> get_tip() == 1)
                                        if((linie_piesa != linie2 || coloana_piesa != coloana2))
                                            {
                                                matrice[linie1][coloana1] = X;
                                                if(verific_rege_sah(linie1,coloana1,linie2,coloana2,player,tip) == 1)
                                                {
                                                    switch(tip)
                                                    {
                                                        case 2: strcpy(motiv, "Intrii in sah de la Regina"); break;
                                                        case 3: strcpy(motiv, "Intrii in sah de la Turn"); break;
                                                        case 4: strcpy(motiv, "Intrii in sah de la Nebun"); break;
                                                        case 5: strcpy(motiv, "Intrii in sah de la Cal"); break;
                                                        case 6: strcpy(motiv, "Intrii in sah de la Pion"); break;
                                                    }
                                                    return motiv;
                                                }
                                                matrice[linie1][coloana1] = X;
                                                ok = 1;
                                                break;
                                            }
                                    }

                                if(ok != 1)
                                    return motiv;

                                if(intrare == 25)
                                    get_rege() -> set_sah(0,0,0,0);

                            } break;
                }

        return NULL;
}

char* Tabla::muta(int linie1, int coloana1, int linie2, int coloana2, int player, char motiv[100])
    {
        int sw = 0, linie_rege, coloana_rege, linie_piesa, coloana_piesa, tip_piesa, culoare_rege;
        int l1,c1,l2,c2;

        if(linie1 <= 0 || coloana1 <= 0 || linie2 <= 0 || coloana2 <= 0 || linie1 >= 9 || coloana1 >= 9 || linie2 >= 9 || coloana2 >= 9)
            {
                strcpy(motiv, "In afara tablei!");
                return motiv;
            }

        /// modific functia de validare sah cu noile informatii prelucrate

        /// verificam daca este sah mat
        if(get_rege())
            if(get_rege() -> get_sah() == 1 && get_rege() -> get_culoare() == player)
                {
                    sw = 1;
                    linie_rege = get_rege() -> get_linie();
                    coloana_rege = get_rege() -> get_coloana();
                    linie_piesa = get_rege() -> get_linie_sah();
                    coloana_piesa = get_rege() -> get_coloana_sah();
                    culoare_rege = get_rege() -> get_culoare();
                    tip_piesa = get_rege() -> get_piesa_sah();
                }

        if(sw == 1)
            if(sah_mat(player,l1,c1,l2,c2) == 0)
                {
                    strcpy(motiv,"SAH");
                    return motiv;
                }

        /// verificam daca este pat
        if(pat(player) == 0)
            {
                strcpy(motiv,"PAT");
                return motiv;
            }

        if(sw == 1)
            get_rege()-> set_sah(1,tip_piesa,linie_piesa,coloana_piesa);

        /// verificam daca se afla o piesa in zona indicata
        if(!matrice[linie1][coloana1])
            {
                strcpy(motiv,"nu se afla nicio piesa in zona indicata");
                return motiv;
            }

        /// verificam daca piesa este a jucatorului
        if(matrice[linie1][coloana1] -> get_culoare() != player)
            {
                strcpy(motiv,"nu poti muta o piesa ce nu e a ta");
                return motiv;
            }

        /// verificam daca mutarea este valida pentru piesa respectiva
        if(matrice[linie1][coloana1] -> validare_mutare(linie2, coloana2, player, motiv) != NULL)
            {
                if(matrice[linie1][coloana1] -> get_tip() == 6)
                    matrice[linie1][coloana1] -> reset_nr_mutari();

                return motiv;
            }

        /// verificam celelate conditii ce depind de tabla pentru tipul de piesa ales
        if(validare_mutare_tabla(linie1,coloana1,linie2,coloana2,player,motiv) != NULL)
            return motiv;

        /// verificam daca a iesit din sah
        if(sw == 1)
            if(validare_iesire_sah(linie1,coloana1,linie2,coloana2,linie_rege,coloana_rege,linie_piesa,coloana_piesa,tip_piesa,player,motiv,25) != NULL)
                return motiv;

        matrice[linie2][coloana2] = matrice[linie1][coloana1];
        matrice[linie2][coloana2] -> setare_coordonate(linie2,coloana2);
        matrice[linie2][coloana2] -> setare_culoare(player);
        matrice[linie2][coloana2] -> setare_tip(matrice[linie1][coloana1] -> get_tip());
        matrice[linie1][coloana1] = NULL;

        setare_mutare(linie1,coloana1,linie2,coloana2,player,matrice[linie2][coloana2] -> get_tip());

        return NULL;
    }

char* Tabla::muta_sah_mat(int linie1, int coloana1, int linie2, int coloana2, int player, char motiv[100])
    {
        int sw = 0, linie_rege, coloana_rege, linie_piesa, coloana_piesa, tip_piesa, culoare_rege;

        if(get_rege())
            if(get_rege() -> get_sah() == 1 && get_rege() -> get_culoare() == player)
                {
                    sw = 1;
                    linie_rege = get_rege() -> get_linie();
                    coloana_rege = get_rege() -> get_coloana();
                    linie_piesa = get_rege() -> get_linie_sah();
                    coloana_piesa = get_rege() -> get_coloana_sah();
                    culoare_rege = get_rege() -> get_culoare();
                    tip_piesa = get_rege() -> get_piesa_sah();
                }

        /// verificam daca se afla o piesa in zona indicata
        if(!matrice[linie1][coloana1])
            {
                strcpy(motiv,"nu se afla nicio piesa in zona indicata");
                return motiv;
            }

        /// verificam daca piesa este a jucatorului
        if(matrice[linie1][coloana1] -> get_culoare() != player)
            {
                strcpy(motiv,"nu poti muta o piesa ce nu e a ta");
                return motiv;
            }

        /// verificam daca mutarea este valida pentru piesa respectiva
        if(matrice[linie1][coloana1] -> validare_mutare(linie2, coloana2, player, motiv) != NULL)
            return motiv;

        if(matrice[linie1][coloana1] -> get_tip() == 6)
            matrice[linie1][coloana1] -> reset_nr_mutari();

        /// verificam celelate conditii ce depind de tabla pentru tipul de piesa ales
        if(validare_mutare_sah_pat(linie1,coloana1,linie2,coloana2,player,motiv) != NULL)
            {
                if(matrice[linie1][coloana1] -> get_tip() == 6)
                    matrice[linie1][coloana1] -> reset_nr_mutari();
                return motiv;
            }

        if(matrice[linie1][coloana1] -> get_tip() == 6)
            matrice[linie1][coloana1] -> reset_nr_mutari();

        /// verificam daca a iesit din sah cand e cazul
        if(validare_iesire_sah(linie1,coloana1,linie2,coloana2,linie_rege, coloana_rege,linie_piesa,coloana_piesa,tip_piesa,player,motiv,1) != NULL)
            return motiv;

        return NULL;
    }

char* Tabla::muta_pat(int linie1, int coloana1, int linie2, int coloana2, int player, char motiv[100])
    {
        /// verificam daca se afla o piesa in zona indicata
        if(!matrice[linie1][coloana1])
            {
                strcpy(motiv,"nu se afla nicio piesa in zona indicata");
                return motiv;
            }

        /// verificam daca piesa este a jucatorului
        if(matrice[linie1][coloana1] -> get_culoare() != player)
            {
                strcpy(motiv,"nu poti muta o piesa ce nu e a ta");
                return motiv;
            }

        /// verificam daca mutarea este valida pentru piesa respectiva
        if(matrice[linie1][coloana1] -> validare_mutare(linie2, coloana2, player, motiv) != NULL)
            return motiv;

        if(matrice[linie1][coloana1] -> get_tip() == 6)
            matrice[linie1][coloana1] -> reset_nr_mutari();

        /// verificam celelate conditii ce depind de tabla pentru tipul de piesa ales
        if(validare_mutare_sah_pat(linie1,coloana1,linie2,coloana2,player,motiv) != NULL)
            return motiv;

        return NULL;
    }

int Tabla::sah_mat(int player, int &l1, int &c1, int &l2, int &c2)
    {
        int i, j, k, l, s = 0;
        char motiv[100];

        for(i = 1; i <= 8; i++)
            for(j = 1; j <= 8; j++)
                {
                    if(matrice[i][j])
                        if(matrice[i][j] -> get_culoare() == player)
                            {
                                for(k = 1; k <= 8; k++)
                                    for(l = 1; l <= 8; l++)
                                        if(muta_sah_mat(i, j, k, l, player, motiv) == NULL)
                                            {
                                                l1 = i;
                                                c1 = j;
                                                l2 = k;
                                                c2 = l;
                                                return 1;

                                            }
                            }
                }

        return 0;
    }

int Tabla::pat(int player)
    {
        int i, j, k, l, s = 0;
        char motiv[100];

        for(i = 1; i <= 8; i++)
            for(j = 1; j <= 8; j++)
                {
                    if(matrice[i][j])
                        if(matrice[i][j] -> get_culoare() == player)
                            {
                                for(k = 1; k <= 8; k++)
                                    for(l = 1; l <= 8; l++)
                                        if(muta_pat(i, j, k, l, player, motiv) == NULL)
                                            return 1;
                            }
                }

        return 0;
    }

ostream& operator<<(ostream& out, Piesa *X)
    {
        out << 10 * X -> get_culoare() + X -> get_tip();
        return out;
    }

void Tabla::Afisare_Tabla()
    {
        int i, j;

        cout << "   ";
        for(i = 1; i <= 8; i++)
            cout << " " << i << " ";
        cout << endl << endl;
        for(i = 1; i <= 8; i++)
        {   cout << i << "  ";
            for(j = 1; j <= 8; j++)
                if(matrice[i][j])
                    cout << matrice[i][j] << " ";
                else
                    cout << "00 ";
            cout << endl << endl;
        }

        afisare_mutari();
    }

#endif // CLASA_TABLA_H_INCLUDED
