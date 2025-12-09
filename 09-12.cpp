Zadania wykonane samodzielnie bardzo samodzielnie

Zad. 1
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int N = 20;

void losuj(int A[]){
    for(int i=0; i<N; i++){
        A[i] = rand() % 100;
    }
}

void wypisz(int A[]){
    for(int i=0; i<N; i++){
        cout << A[i] << " ";
    }
}

void quickSort(int A[], int p, int k){
    if (p >= k) return;

    int pivotIndex = rand() % (k - p + 1) + p;
    swap(A[pivotIndex], A[k]);

    int m = A[k];  
    int i = p - 1;
    for (int j = p; j < k; j++){
        if (A[j] <= m){
            i++;
            swap(A[i], A[j]);
        }
    }

    swap(A[i + 1], A[k]);  
    int pivotPos = i + 1;

    quickSort(A, p, pivotPos - 1);
    quickSort(A, pivotPos + 1, k);
}

int main(){
    int A[N];
    srand(time(NULL));

    losuj(A);
    wypisz(A);
    quickSort(A, 0, N - 1);

    cout << "Tablica po sortowaniu" << endl;
    wypisz(A);
    cout << endl;

    return 0;
}

Zad. 2

Zad. 3

Zad. 4

Zad. 5

Zad. 6

Zad. 7

Zad. 8

Zad. 9

Zad. 10




