#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <stdio.h>
#include <math.h>

using namespace std;


int IndexWTablicyDanejLiczby_Lin(int* tablica, int RozmiarTablicy, int LiczbaDoSprawdzenia)
{
    for(int i=0; i < RozmiarTablicy; i++)
    {
        if( tablica[i] == LiczbaDoSprawdzenia)
        return i;
    }
    return -1;
}
int IndexWTablicyDanejLiczby_LogRek(int* tablica, int Rozmiar, int LiczbaDoSprawdzenia, int indexPoczatkowy, int indexKoncowy)
{
    int k = ( indexPoczatkowy + indexKoncowy) / 2;
    if( LiczbaDoSprawdzenia == tablica[k])
    return k;
    if( LiczbaDoSprawdzenia < tablica[k])
    {
        if( indexKoncowy > indexPoczatkowy)
        return IndexWTablicyDanejLiczby_LogRek(tablica, Rozmiar, LiczbaDoSprawdzenia, indexPoczatkowy, k);
        else
        return -1;
    }
    else
    {
        if( indexKoncowy >= indexPoczatkowy)
        return IndexWTablicyDanejLiczby_LogRek(tablica, Rozmiar, LiczbaDoSprawdzenia, k+1, indexKoncowy);
        else
        return -1;
    }
    return -1;
}
int IndexWTablicyDanejLiczby_Log(int* tablica, int Rozmiar, int LiczbaDoSprawdzenia)
{
    int indexPoczatkowy = 0;
    int indexKoncowy = Rozmiar - 1;
    while ( LiczbaDoSprawdzenia != tablica[(indexKoncowy + indexPoczatkowy) / 2] && indexPoczatkowy != indexKoncowy )
    {
        if (LiczbaDoSprawdzenia > tablica[(indexKoncowy + indexPoczatkowy) / 2])
        {
            indexPoczatkowy = ceil( (indexKoncowy + indexPoczatkowy) / 2.0 );
        }
        else
        {
            indexKoncowy = floor( (indexKoncowy + indexPoczatkowy) / 2.0 );
        }
    }
    if( LiczbaDoSprawdzenia != tablica[(indexKoncowy + indexPoczatkowy) / 2])
    return -1;
    return ( indexKoncowy + indexPoczatkowy ) / 2;
}

void KWSrodku_Test1 ()
{
    int k = 5;
    int Tablica[] = {1,2,3,4,5,6};
    int res1 = IndexWTablicyDanejLiczby_Lin (Tablica, 6, k);
    assert(res1 == 4);
}
void KWSrodku_Test2 ()
{
    int k = 5;
    int Tablica[] = {1,2,3,4,5,6};
    int res2 = IndexWTablicyDanejLiczby_LogRek (Tablica, 6, k, 0, 6);
    assert(res2 == 4);
}
void KWSrodku_Test3 ()
{
    int k = 5;
    int Tablica[] = {1,2,3,4,5,6};
    int res3 = IndexWTablicyDanejLiczby_Log (Tablica, 6, k);
    assert(res3 == 4);
}
void NieMaK_Test1 ()
{
    int k = -10;
    int Tablica[] = {1,2,3,4,5,6};
    int res1 = IndexWTablicyDanejLiczby_Lin (Tablica, 6, k);
    assert(res1 == -1);
}
void NieMaK_Test2 ()
{
    int k = -10;
    int Tablica[] = {1,2,3,4,5,6};
    int res2 = IndexWTablicyDanejLiczby_LogRek (Tablica, 6, k, 0, 5);
    assert(res2 == -1);
}
void NieMaK_Test3 ()
{
    int k = -10;
    int Tablica[] = {1,2,3,4,5,6};

    int res3 = IndexWTablicyDanejLiczby_Log (Tablica, 6, k);
    assert(res3 == -1);
}
void KNaPoczatku_Test1 ()
{
    int k = 1;
    int Tablica[] = {1,2,3,4,5,6};
    int res1 = IndexWTablicyDanejLiczby_Lin(Tablica, 6, k);
    assert(res1 == 0);
}
void KNaPoczatku_Test2 ()
{
    int k = 1;
    int Tablica[] = {1,2,3,4,5,6};
    int res2 = IndexWTablicyDanejLiczby_LogRek(Tablica, 6, k, 0, 5);
    assert(res2 == 0);
}
void KNaPoczatku_Test3 ()
{
    int k = 1;
    int Tablica[] = {1,2,3,4,5,6};
    int res3 = IndexWTablicyDanejLiczby_Log (Tablica, 6, k);
    assert(res3 == 0);
}
void KNaKoncu_Test1 ()
{
    int k = 6;
    int Tablica[] = {1,2,3,4,5,6};
    int res1 = IndexWTablicyDanejLiczby_Lin(Tablica, 6, k);
    assert(res1 == 5);
}
void KNaKoncu_Test2 ()
{
    int k = 6;
    int Tablica[] = {1,2,3,4,5,6};
    int res2 = IndexWTablicyDanejLiczby_LogRek(Tablica, 6, k, 0, 5);
    assert(res2 == 5);
}
void KNaKoncu_Test3 ()
{
    int k = 6;
    int Tablica[] = {1,2,3,4,5,6};
    int res3 = IndexWTablicyDanejLiczby_Log (Tablica, 6, k);
    assert(res3 == 5);
}

int main()
{
    KNaKoncu_Test1();
    KNaKoncu_Test2();
    KNaKoncu_Test3();
    KNaPoczatku_Test1();
    KNaPoczatku_Test2();
    KNaPoczatku_Test3();
    NieMaK_Test1();
    NieMaK_Test2();
    NieMaK_Test3();
    KWSrodku_Test1();
    KWSrodku_Test2();
    KWSrodku_Test3();
    return 0;
}
