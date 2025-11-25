zad 1

https://docs.google.com/spreadsheets/d/15P3SY1jOkwHXhrhsQHvGrNaqSVuZ1CKTTTpe-UQup84/edit?gid=0#gid=0 
link do arkusza (ten sam co w ćw od jonderka)

zad 2

  #include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

const int N = 3;
int A[N][N+1];

void Losuj (int A[] [N + 1]){
    for (int i = 0; i < N ;i++)
        for (int j = 0; j < N ;j++)
            A[i][j]=1+rand()%9;
    for (int i = 0; i<N;i++){
        A[N][i] = 0; 
        A[i][N] = 0;
    }
}

void Wypisz(int A[] [N + 1] ){
    for (int i = 0; i<N;i++){
        for (int j = 0; j < N ;j++) cout<<A[i][j]<<" ";
            cout<<endl;
    }
}

int MaksSumaCout(int A[] [N + 1] ){
    cout<<A[0] [0]<<" ";
    int suma=A[0][0];
    int w = 0, k = 0;
        for (int i = 1; i < 2*N - 1 ;i++)
        if (A[w + 1][k] > A[w][k + 1])
        {
            cout<<A[w+1] [k]<<" ";
            suma+=A[w+1] [k]; w++;
        }
        else
        {
            cout<<A[w] [k+1]<<" ";
            suma+=A[w] [k+1]; k++;
        }
    return suma;
}

int main(){
    srand(time(NULL));
    Losuj(A);
    cout<<'\n';
    Wypisz(A);
    cout<<'\n';
    cout<<MaksSumaCout(A);

}

zad 3

    dla i = 0 do n-1
        oblicz stosunek[i] = v[i] / w[i]  (obliczamy stosunek wartości)
    koniec dla

    sortuj przedmioty według stosunku, zachowując indeksy


    dla i = 0 do n-1
        jeśli w[i] <= remaining_capacity
            dodaj i do wybrane
            remaining_capacity -= w[i]    przerwij
    koniec dla

    total_value = 0
    dla i = 0 do rozmiar(wybrane)-1
        total_value += v[wybrane[i]]
    koniec dla

zwroc total value

zad 4
Wydawanie reszty metoda zachłanna:
czasowa O(n)
Pamięciowa O(1)
Max suma w kwadacie
obliczeniowa O(n)
Plecakowe sprawy:
O(n*Log n)

zad 5

#include <iostream>

using namespace std;

const int N = 5;
const int makswaga = 15;

struct przedmiot{
    int wart, waga;
};


bool differentation(przedmiot a, przedmiot b){
    return (float(a.wart)/a.waga > float(b.wart/b.waga));
}


int backpack(przedmiot P[], int makswaga){
    int makswart = 0;
    for(int i=0; i<N; i++){
            if(makswaga-P[i].waga>0){
                makswaga=makswaga-P[i].waga;
                makswart+=P[i].wart;
            }
            else break;
    }
    return makswart;
}

int main(){
    
    przedmiot P[N];
    for(int i=0; i<N; i++){
        cin>>P[i].wart>>P[i].waga;
    }
    sort(P,P+N,differentation);

    cout<<backpack(P, makswaga)<<endl;

    return 0;
}
zad 6
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int main() {
    // przykladowe dane:
    /*  5
        1 3
        3 4
        3 6
        4 7
        7 9
    
        wyjście:
        4
    */
    int N; cout<<"Liczba filmow: "; cin>>N;
    
    vector<pair<int, int>> filmy;
    
    for(int i=0;i<N;i++){
        cin>>filmy[i].first>>filmy[i].second;
    }
    
    //sortowanie po godzinie zakonczenia od najmniejszej do najwiekszej
    sort(filmy.begin(), filmy.end(), [](const pair<int, int> p1, const pair<int, int> p2) {
        return p1.second < p2.second;
    });

    
    int czas = 0, obejrzane = 0;
    
    
    for (int i = 0; i < N; i++) {
        //ustawianie czasu na godzine skonczenia ogladania filmu
        // jezeli godzina rozpoczecia jest mniejsza niz czas to pomijamy film
        if (filmy[i].first >= czas) {
            obejrzane++;
            czas = filmy[i].second;  
        }
    }

    cout << obejrzane << endl;

    return 0;
}
