#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <map>
using namespace std;

bool czyDasiePrzejscTabliceNx2 (int MaxClimb ,int Rozmiar, int** tablica, int x, int y)
{
    if(x == Rozmiar - 1 && y == 1)
        return true;

    // czy da siê iœæ w prawo?

    if(tablica[y][x+1]-tablica[y][x]<=MaxClimb && x+1<Rozmiar && czyDasiePrzejscTabliceNx2(MaxClimb , Rozmiar , tablica , x+1 , y)==true)
        return true;

    // czy da sie isc w dol?

    if(tablica[y+1][x]-tablica[y][x]<=MaxClimb && y+1<2 && czyDasiePrzejscTabliceNx2(MaxClimb , Rozmiar , tablica , x , y+1)==true)
            return true;

    // czy da sie isc do gory?

    if(tablica[y-1][x]-tablica[y][x]<=MaxClimb && y-1>=0 && czyDasiePrzejscTabliceNx2(MaxClimb , Rozmiar , tablica , x , y-1)==true)
        return true;

    return false;


    EHJAHSDHFAKSDHFA,


}

/* tablica, kórej nie da siê przejsæ

MaxClimb =1

[0 1 3
 0 3 5]

*/

bool Test1(int MaxClimb, int x, int y)
{
    int t[2][3]={{0,1,3},{0,3,5}};
    return czyDasiePrzejscTabliceNx2(MaxClimb, 3, t, x, y);
}

bool Test2(int MaxClimb, int x, int y)
{
    int t[2][3]={{0,1,2},{0,4,3}};
    return czyDasiePrzejscTabliceNx2(MaxClimb, 3, t, x, y);
}





main()
{
    srand(time(NULL));
    cout<<"hscajxba"<<endl;
    cout<<Test1(1,0,0);
    cout<<endl<<Test2(1,0,0);




}
