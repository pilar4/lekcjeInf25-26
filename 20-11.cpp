cw 1

https://docs.google.com/spreadsheets/d/15P3SY1jOkwHXhrhsQHvGrNaqSVuZ1CKTTTpe-UQup84/edit?usp=sharing
link do google

cw 2
a)
#include <iostream>

using namespace std;

const int N=15;
const int NOMIN[]={50000,20000,10000,5000,2000,1000,500,200,100,50,20,10,5,2,1};

void Dajkase(int kwota, int Reszta[]){
    for(int i=0;i<N;i++){
        Reszta[i]=kwota/NOMIN[i];
        kwota=kwota%NOMIN[i];
    }
}

int main(){
    int kwota, Reszta[N];
    cin>>kwota;

    Dajkase(kwota, Reszta);

    for(int i=0;i<N;i++){
        if(Reszta[i]>0){
            cout<<NOMIN[i]<<" - "<<Reszta[i]<<endl;
        }
    }

    return 0;
}
b)
#include <iostream>

using namespace std;

const int N=15;
const int NOMIN[]={50000,20000,10000,5000,2000,1000,500,200,100,50,20,10,5,2,1};

void Dajkase(int kwota, int Reszta[]){
    for(int i=0;i<N;i++){
        Reszta[i]=kwota/NOMIN[i];
        kwota=kwota%NOMIN[i];
    }
}

int main(){
    int kwota, Reszta[N];
    cin>>kwota;

    Dajkase(kwota, Reszta);

    for(int i=0;i<N;i++){
        if(Reszta[i]>0){
            if(i<9){
            cout<<NOMIN[i]/100<<"zl"<<" - "<<Reszta[i]<<endl;
            }
            else{
            cout<<NOMIN[i]<<"gr"<<" - "<<Reszta[i]<<endl;
            }
        }
    }

    return 0;
}
cw 3
zrobilismy na lekcji, system:
1 grosz
3 grosze
4 grosze
10 groszy
30 groszy
40 groszy
1 zlotowka
3 zlotowki
4 zlowowki
10 zlotych
30 zlotych
40 zlotych
100 zlotych
300 zlotych
400 zlotych

cw5
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

int MaksSuma(int A[] [N + 1] ){
    int suma=A[0][0];
    int w = 0, k = 0;
        for (int i = 1; i < 2*N - 1 ;i++)
        if (A[w + 1][k] > A[w][k + 1])
        {
            suma+=A[w+1] [k]; w++;
        }
        else
        {
            suma+=A[w] [k+1]; k++;
        }
    return suma;
}

int main(){
    srand(time(NULL));
    Wypisz(A);
    cout<<'\n';
    Losuj(A);
    cout<<'\n';
    cout<<MaksSuma(A);

}
