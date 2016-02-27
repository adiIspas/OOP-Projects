#include <iostream>
#include <cstdlib>

using namespace std;

class multime_finita
    {
        int* elemente, cardinal;

    public:
        multime_finita(int *v, int n);
        int* GetElemente();
        int GetCardinal();
        multime_finita ReuniuneCu(multime_finita X);
        multime_finita IntersectieCu(multime_finita X);
        multime_finita DiferentaCu(multime_finita X);
        void Sortare();
        void Afisare();
    };

multime_finita::multime_finita(int *v, int n)
    {
        int i, j;
        cardinal = n;

        elemente = new int[cardinal];

        for (i = 0; i < cardinal; i++)
            elemente[i] = v[i];

        Sortare();

        for (i = 0; i < cardinal - 1; i++)
            if(elemente[i] == elemente[i+1])
                {
                    for(j = i; j < cardinal - 1; j++)
                        elemente[j] = elemente[j+1];

                    cardinal--;
                    i--;
                }
    }

int* multime_finita::GetElemente()
    {
        return elemente;
    }

int multime_finita::GetCardinal()
    {
        return cardinal;
    }

multime_finita multime_finita::ReuniuneCu(multime_finita X)
    {
        int sw, i = 0, j = 0, k = 0, *v, l;

        v = new int[cardinal + X.cardinal];

        while(i < cardinal && j < X.GetCardinal())
            if(elemente[i] < X.elemente[j])
                {

                    v[k] = elemente[i];
                    i++;
                    k++;
                }
            else
                {
                    v[k] = X.elemente[j];
                    j++;
                    k++;
                }

           if(i < cardinal)
                for(l=i; l<cardinal; l++)
                    {
                        v[k]=elemente[l];
                        k++;
                    }
           else
                for(l=j; l<X.GetCardinal(); l++)
                    {
                        v[k]=X.elemente[l];
                        k++;
                    }

        multime_finita Y(v,k);

        delete v;

        return Y;
    }

multime_finita multime_finita::IntersectieCu(multime_finita X)
    {
        int i, j, *v, k = 0;

        v = new int[cardinal];

        for (i = 0; i < cardinal; i++)
            for (j = 0; j < X.cardinal; j++)
                    if(elemente[i] == X.elemente[j])
                        {
                            v[k] = elemente[i];
                            k++;
                        }

        multime_finita Y(v,k);

        delete v;

        return Y;
    }

multime_finita multime_finita::DiferentaCu(multime_finita X)
    {
        int i, j, sw, k = 0, *v;

        v = new int[cardinal];

        for(i = 0; i < cardinal; i++)
            {
                sw = 1;
                for (j = 0; j < X.GetCardinal(); j++)
                    if(elemente[i] == X.elemente[j])
                        {sw = 0; break;}

                if (sw == 1)
                   {
                       v[k] = elemente[i];
                       k++;
                   }
            }

        multime_finita Y(v,k);

        delete v;

        return Y;
    }

void multime_finita::Sortare()
    {
        int i, j, aux;

        for(i = 0; i < cardinal; i++)
            for (j = i; j < cardinal; j++)
                if(elemente[i] > elemente[j])
                    {
                        aux = elemente[i];
                        elemente[i] = elemente[j];
                        elemente[j] = aux;
                    }
    }

void multime_finita::Afisare()
    {
        int i;

        if(cardinal)
            {
                for(i = 0; i < cardinal; i++ )
                cout << elemente[i] << " ";
            }
        else
            cout << "nu se poate realiza.\n";
    }

void citire_elemente(int* a, int n)
    {
        int i, k = 1;

        for (i = 0; i < n; i++)
            {
                cout << " Elementul " << k << ": ";
                cin >> a[i];
                k++;
            }
    }

void afisare_optiuni(int &sw)
    {
        cout << "\n\n Alegeti o operatie pe cele 2 multimi!\n";
        cout << "\n 1 pentru Reuniune.\n 2 pentru Intersectie. \n 3 pentru Diferenta M - N. \n 4 pentru Diferenta N - M.\n 0 pentru a iesi din program.\n Optiune: ";
        cin >> sw;
    }

int main()
{
    int *a, *b, n, m, sw;

    cout << "\n\n\t\t\t Bun venit! " << (char)1 << endl << endl;

    cout << " Nr. elemente multimea M: ";
    cin >> n;

    cout << " Nr. elemente multimea N: ";
    cin >> m;

    system("cls");

    a = new int[n];
    b = new int[m];

    cout << "\n Introduceti elementele multimii M\n";
    citire_elemente(a,n);
    multime_finita M(a,n);

    cout << "\n Introduceti elementele multimii N\n";
    citire_elemente(b,m);
    multime_finita N(b,m);

    system("cls");

    cout << "\n Elementele multimi M: ";
    M.Afisare();
    cout << endl;
    cout << "\n Elementele multimi N: ";
    N.Afisare();

    afisare_optiuni(sw);

    while(sw)
    {
     switch(sw)
        {
            case 1 : {
                        cout << "\n Reuniunea M cu N: ";
                        M.ReuniuneCu(N).Afisare();
                        cout << endl;

                     } break;
            case 2: {
                        cout << "\n\n Intersectia M cu N: ";
                        M.IntersectieCu(N).Afisare();
                        cout << endl;

                    } break;
            case 3: {
                        cout << "\n\n Diferenta M si N: ";
                        M.DiferentaCu(N).Afisare();
                        cout << endl;

                    } break;
            case 4: {
                        cout << "\n\n Diferenta N si M: ";
                        N.DiferentaCu(M).Afisare();
                        cout << endl;

                    } break;

            default : cout << "\n Nu ati ales o optiune valida!\n";
        }

    cout << endl;
    system("PAUSE");
    system("cls");

    cout << "\n Elementele multimi M: ";
    M.Afisare();

    cout << endl;

    cout << "\n Elementele multimi N: ";
    N.Afisare();

    afisare_optiuni(sw);
    }

    delete a;
    delete b;

    return 0;
}
