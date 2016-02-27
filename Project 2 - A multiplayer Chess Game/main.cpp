#include <iostream>
#include <stdlib.h>
#include "Clasa_Piesa.h"
#include "Clasa_Rege.h"
#include "Clasa_Regina.h"
#include "Clasa_Turn.h"
#include "Clasa_Nebun.h"
#include "Clasa_Cal.h"
#include "Clasa_Pion.h"
#include "Clasa_Tabla.h"

using namespace std;

int main()
{
    int linie1, coloana1, linie2, coloana2, player, sah_mat = 0, pat = 0, ok;
    char motiv[100];

    Tabla X;

    player = 2;
    while(!sah_mat || !pat)
        {
            system("CLS");
            system("COLOR 0A");
            X.Afisare_Tabla();

            cout << endl;
            if(player == 1)
                player = 2;
            else
                player = 1;

            ok = 0;
            while(!ok)
                {
                    system("CLS");
                    X.Afisare_Tabla();

                    cout << "\tJucator " << player << endl;

                    cout << "Linie: ";
                    cin >> linie1;
                    cout << "Coloana: ";
                    cin >> coloana1;

                    cout << endl;

                    cout << "Linie: ";
                    cin >> linie2;
                    cout << "Coloana: ";
                    cin >> coloana2;

                    cout << endl;
                    if(!X.muta(linie1, coloana1, linie2, coloana2, player, motiv))
                        {
                            cout << "Mutare efectuata cu succes! " << (char)1;
                            ok = 1;
                        }
                    else
                        if(strcmp(motiv,"SAH") == 0)
                            sah_mat = 1;
                        else
                            if(strcmp(motiv,"PAT") == 0)
                                pat = 1;
                            else
                                cout << motiv;

                    if(sah_mat == 1)
                        {
                            cout << "\tSAH - MAT : JOC TERMINAT!\n\t   Player ";
                            if(player == 2)
                                cout << "1";
                            else
                                cout << "2";
                            cout << " a castigat!\n";

                            return 0;
                        }

                    if(pat == 1)
                        {
                            cout << "\tPAT : JOC TERMINAT!\n  Jocul s-a finalizat cu o remiza!\n";
                            return 0;
                        }

                    cout << endl;
                    system("PAUSE");
                }
        }

    return 0;
}
