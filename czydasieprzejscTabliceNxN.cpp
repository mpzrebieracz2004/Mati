#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <map>
using namespace std;


bool czyDasiePrzejscTabliceNxM(int** tablica, int dlugosc, int szerokosc, int maxClimb, int x, int y, bool** czyBylo)
{
    if (czyBylo[y][x]==true)
        return false;

    czyBylo[y][x]=true;

    if(x==szerokosc - 1 && y==dlugosc - 1)
        return true;
    //czy da sie isc w prawo
    if(x < szerokosc - 1
       && tablica[y][x+1] - tablica[y][x] <= maxClimb
       && czyDasiePrzejscTabliceNxM(tablica, dlugosc, szerokosc, maxClimb, x+1, y, czyBylo))
    {
        return true;
    }
    //czy da sie isc w gore
    if(y > 0
       && tablica[y-1][x] - tablica[y][x] <= maxClimb
       && czyDasiePrzejscTabliceNxM(tablica, dlugosc, szerokosc, maxClimb, x, y-1, czyBylo))
    {

        return true;
    }
    //czy da sie isc w lewo
    if(x > 0
       && tablica[y][x-1] - tablica[y][x] <= maxClimb
       && czyDasiePrzejscTabliceNxM(tablica, dlugosc, szerokosc, maxClimb, x-1, y, czyBylo))
       {

           return true;
       }
    //czy da sie isc w dol
    if(y < dlugosc - 1
       && tablica[y+1][x] - tablica[y][x] <= maxClimb
       && czyDasiePrzejscTabliceNxM(tablica, dlugosc, szerokosc, maxClimb, x, y+1, czyBylo))
    {

        return true;
    }
    return false;
}

void InitVisitedTable(bool**& czyBylo, int x, int y)
{
    czyBylo = new bool*[x];

    for (int i = 0; i < x; i++)
    {
        czyBylo[i] = new bool[y];
        for (int j = 0; j < y; j++)
        {
            czyBylo[i][j] = false;
        }

    }

}

bool Test1(int maxClimb)
   // int tablica[2][3]={{1,2,3},{1,4,4}};
{

    int* tablica[2];

    int array1[] = {1,2,3};
    int array2[] = {1,4,4};

    tablica[0] =  array1;
    tablica[1] =  array2;


    bool** czyBylo;

    InitVisitedTable(czyBylo, 2, 3);


    return czyDasiePrzejscTabliceNxM(tablica, 2, 3, maxClimb, 0, 0, czyBylo);
}

bool Test2(int maxClimb)
{

    int* tablica[3];

    int array1[] = {1,2,3};
    int array2[] = {1,4,4};
    int array3[] = {1,3,6};

    tablica[0] =  array1;
    tablica[1] =  array2;
    tablica[2] =  array3;


    bool** czyBylo;

    InitVisitedTable(czyBylo, 3, 3);


    return czyDasiePrzejscTabliceNxM(tablica, 3, 3, maxClimb, 0, 0, czyBylo);
}
bool Test3(int maxClimb)
{

    int* tablica[3];

    int array1[] = {1,4,7};
    int array2[] = {1,9,6};
    int array3[] = {1,11,10};

    tablica[0] =  array1;
    tablica[1] =  array2;
    tablica[2] =  array3;


    bool** czyBylo;

    InitVisitedTable(czyBylo, 3, 3);


    return czyDasiePrzejscTabliceNxM(tablica, 3, 3, maxClimb, 0, 0, czyBylo);
}
main()
{
    cout<< Test1(1)<<endl;
    cout<< Test2(1)<<endl;
    cout<< Test3(4)<<endl;


    return 0;
}
