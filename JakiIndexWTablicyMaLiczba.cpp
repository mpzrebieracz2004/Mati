#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

using namespace std;

void PrzekazywanieCzesciTablicyNaNowaTablice(int* TablicaDoPrzekazania, int* tablicaOtrzymujacaWartosci, int ZakresDolny, int ZakresGorny)
{
    int j=0;
    for(int i = ZakresDolny; i < ZakresGorny; i++)
    {
        tablicaOtrzymujacaWartosci[j] = TablicaDoPrzekazania[i];
    }
}
int IndexWTablicyDanejLiczby_Log(int* tablica, int RozmiarTablicy, int LiczbaDoSprawdzenia)
{
    if (LiczbaDoSprawdzenia == tablica[RozmiarTablicy / 2]
    {
        int Indexk = RozmiarTablicy / 2;
        return Indexk;
    }
    if( LiczbaDoSprawdzenia < tablica[RozmiarTablicy / 2])
    {
        int DolnaTablica[RozmiarTablicy/2];
        PrzekazywanieCzesciTablicyNaNowaTablice(tablica, DolnaTablica, 0, RozmiarTablicy/2);
        return IndexWTablicyDanejLiczby_Log( Dolnatablica, RozmiarTablicy/2, LiczbaDoSprawdzenia);
    }
    else
    {
        int GornaTablica[RozmiarTablicy / 2];
        PrzekazywanieCzesciTablicyNaNowaTablice(tablica, GornaTablica, RozmiarTablicy/2), RozmiarTablicy);
        return IndexWTablicyDanejLiczby_Log( Gornatablica, RozmiarTablicy/2, LiczbaDoSprawdzenia);
    }
    return -1;
}

void KWSrodku_Test ()
{
    int k = 5;
    int Tablica[] = {1,2,3,4,5,6};
    bool res1 = IndexWTablicyDanejLiczby_Lin(Tablica, 6, k) - 4;
    bool res2 = IndexWTablicyDanejLiczby_Log(Tablica, 6, k) - 4;
    assert(!res1);
    assert(!res2);
}
void NieMaK_Test ()
{
    int k = 10;
    int Tablica[] = {1,2,3,4,5,6};
    bool res1 = IndexWTablicyDanejLiczby_Lin(Tablica, 6, k) + 1;
    bool res2 = IndexWTablicyDanejLiczby_Log(Tablica, 6, k) + 1;
    assert(!res1);
    assert(!res2);
}
void KNaPoczatku_Test ()
{
    int k = 1;
    int Tablica[] = {1,2,3,4,5,6};
    bool res1 = IndexWTablicyDanejLiczby_Lin(Tablica, 6, k);
    bool res2 = IndexWTablicyDanejLiczby_Log(Tablica, 6, k);
    assert(!res1);
    assert(!res2);
}
void KNaKoncu_Test ()
{
    int k = 6;
    int Tablica[] = {1,2,3,4,5,6};
    bool res1 = IndexWTablicyDanejLiczby_Lin(Tablica, 6, k) - 5;
    bool res2 = IndexWTablicyDanejLiczby_Log(Tablica, 6, k) - 5;
    assert(!res1);
    assert(!res2);
}
void Tablica1El_Test ()
{
    int k = 6;
    int Tablica[] = {6};
    bool res1 = IndexWTablicyDanejLiczby_Lin(Tablica, 1, k);
    bool res2 = IndexWTablicyDanejLiczby_Log(Tablica, 1, k);
    assert(!res1);
    assert(!res2);
}
int main()
{
    KNaKoncu_Test();
    KNaPoczatku_Test();
    NieMaK_Test();
    KWSrodku_Test();
    Tablica1El_Test();
    return 0;
}
