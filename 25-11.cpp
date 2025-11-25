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

