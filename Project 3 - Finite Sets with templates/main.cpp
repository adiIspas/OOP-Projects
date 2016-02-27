#include <iostream>
#include <cstdlib>

using namespace std;

template<typename Tip_X>
class multime_finita
    {
        Tip_X *elemente;
        int cardinal;

    public:
        multime_finita(Tip_X *v, int n);
        Tip_X* GetElemente();
        int GetCardinal();
        multime_finita ReuniuneCu(multime_finita X);
        multime_finita IntersectieCu(multime_finita X);
        multime_finita DiferentaCu(multime_finita X);
        void Eliminare_Duplicate();
        void Sortare();
        void Afisare();
    };

template <typename Tip_X>
void multime_finita<Tip_X>::Eliminare_Duplicate()
    {
        int i, j;

        for (i = 0; i < cardinal - 1; i++)
            if(elemente[i] == elemente[i+1])
                {
                    for(j = i; j < cardinal - 1; j++)
                        elemente[j] = elemente[j+1];

                    cardinal--;
                    i--;
                }
    }

template<typename Tip_X>
multime_finita<Tip_X>::multime_finita(Tip_X *v, int n)
    {
        int i, j;
        cardinal = n;

        elemente = new Tip_X[cardinal];

        for (i = 0; i < cardinal; i++)
            elemente[i] = v[i];

        Sortare();
        Eliminare_Duplicate();
    }

template<typename Tip_X>
Tip_X* multime_finita<Tip_X>::GetElemente()
    {
        return elemente;
    }

template<typename Tip_X>
int multime_finita<Tip_X>::GetCardinal()
    {
        return cardinal;
    }

template<typename Tip_X>
multime_finita<Tip_X> multime_finita<Tip_X>::ReuniuneCu(multime_finita X)
    {
        int sw, i = 0, j = 0, k = 0, l;

        Tip_X *v = new Tip_X[cardinal + X.cardinal];

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

template<typename Tip_X>
multime_finita<Tip_X> multime_finita<Tip_X>::IntersectieCu(multime_finita X)
    {
        int i, j, k = 0;

        Tip_X *v = new Tip_X[cardinal];

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

template<typename Tip_X>
multime_finita<Tip_X> multime_finita<Tip_X>::DiferentaCu(multime_finita X)
    {
        int i, j, sw, k = 0;

        Tip_X *v = new Tip_X[cardinal];

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

template<typename Tip_X>
void multime_finita<Tip_X>::Sortare()
    {
        int i, j;
        Tip_X aux;

        for(i = 0; i < cardinal; i++)
            for (j = i; j < cardinal; j++)
                if(elemente[i] > elemente[j])
                    {
                        aux = elemente[i];
                        elemente[i] = elemente[j];
                        elemente[j] = aux;
                    }
    }

template<typename Tip_X>
void multime_finita<Tip_X>::Afisare()
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

template<typename Tip_X>
void citire_elemente(Tip_X* a, int n)
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
    string *a, *b;
    int n, m, sw;

    cout << "\n\n\t\t\t Bun venit! " << (char)1 << endl << endl;

    cout << " Nr. elemente multimea M: ";
    cin >> n;

    cout << " Nr. elemente multimea N: ";
    cin >> m;

    system("cls");

    a = new string[n];
    b = new string[m];

    cout << "\n Introduceti elementele multimii M\n";
    citire_elemente(a,n);
    multime_finita<string> M(a,n);

    cout << "\n Introduceti elementele multimii N\n";
    citire_elemente(b,m);
    multime_finita<string> N(b,m);

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
