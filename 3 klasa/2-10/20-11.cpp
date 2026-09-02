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

cw 4
plik proby.txt to jest ten ktory mielismy pobrac, proby2.txt to tez ze zmodyfiowanymi danymi
#include <iostream>
#include <cmath>
#include <ctime>
#include <fstream>
using namespace std;


const int N=7;


struct proba
{
   int pocz, czas;
};


bool Porownaj(proba a, proba b)
{
   return (a.pocz*60+a.czas<b.pocz*60+b.czas);
}


int MLP(proba P[])
{
   int lp=1, ost=0;
   for (int i=1;i<N;i++)
       if (P[i].pocz*60>=P[ost].pocz*60+P[ost].czas)
       {
           lp++;
           ost=i;
       }
       return lp;
}


int main()
{
   proba P[N];
   ifstream we("proby.txt");
   for(int i=0;i<N;i++)
       we>>P[i].pocz>>P[i].czas;
   we.close();
   sort(P,P+N,Porownaj);
   cout<<"Maksymalna liczba prob: "<<MLP(P)<<'\n';
   return 0;
}


cw 5
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

W większości przypadków działa poprawnie, powód tego wytłumaczyliśmy na lekcji

cw 6
a max suma to 56 (trasa się nie zmienia)

b Gdybyśmy wybrali metodę zachłanną to max suma=52 (nowa trasa) 

cw 7 

    a.
    
#include <iostream>
#include <fstream>

using namespace std;

const int N = 5;
const int makswaga = 17;
int K[N];

struct przedmiot{
    int wart, waga;
};


bool differentation(przedmiot a, przedmiot b){
    return (float(a.wart)/a.waga > float(b.wart/b.waga));
}


int backpack(przedmiot P[], int makswaga, int K[]){
    int makswart = 0;
    for(int i=0; i<N; i++){
        K[i]=makswaga/P[i].waga;
        makswaga=makswaga%P[i].waga;
        makswart+=K[i]*P[i].wart;
    }
    return makswart;
}

int main(){
    
    przedmiot P[N];
    ifstream we("do_plecaka.txt");
    for(int i=0; i<N; i++){
        we>>P[i].wart>>P[i].waga;
    }
    we.close();
    sort(P,P+N,differentation);

    cout<<backpack(P, makswaga, K)<<endl;

    return 0;
}

    b.
        4 * 3 (wart 10)
	    1 * 5 (wart 15)


