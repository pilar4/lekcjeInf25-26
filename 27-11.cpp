cw 1
metoda zachlanna - 8,5,1,1 nie jest optymalna 

cw 2 
a.  na lekcji
b. NIE

cw 3

#include <iostream>

using namespace std;

const int N = 3;
const int NOM[] = {1, 5, 7};
const int KWOTA = 10;

int IleMonet(){

    int ileM[KWOTA+1];
    ileM[0] = 0;
    for(int i=1; i<=KWOTA; i++){
        ileM[i]=KWOTA+1;
    }
    for(int i=1; i<=KWOTA; i++){
        for(int j=0; j<N; j++){
            if(NOM[j] <= i){
                if(ileM[i-NOM[j]]+1 < ileM[i]){
                    ileM[i] = ileM[i-NOM[j]]+1;
                }
            }
        }
    }
    return ileM[KWOTA];
}

int main(){

    cout<<KWOTA<<" --> "<<IleMonet()<<endl;

    return 0;
}

cw 4
#include <iostream>

using namespace std;

const int N=4;
const int KWOTA=78;
const int NOMIN[]={1,2,4,5};

int IleMon(int Reszta[]){

    int IleM[KWOTA+1];
    int ResztaM[KWOTA+1][N];
    IleM[0]=0;

    for(int i=0;i<N;i++){
        ResztaM[0][i]=0;
    }
    for(int i=1;i<=KWOTA;i++){
        IleM[i]=KWOTA+1;
    }
    for(int i=1;i<=KWOTA;i++){
        for(int j=0;j<N;j++){
            if(NOMIN[j]<=i){
                if(IleM[i-NOMIN[j]]+1<IleM[i]){
                    IleM[i]=IleM[i-NOMIN[j]]+1;
                    for(int k=0;k<N;k++){
                        ResztaM[i][k]=ResztaM[i-NOMIN[j]][k];
                    }
                    ResztaM[i][j]++;
                }
            }
        }
    }
    for(int i=0;i<N;i++){
        Reszta[i]=ResztaM[KWOTA][i];
    }
    return IleM[KWOTA];
}

int main(){
    int Reszta[N];
    for(int i=0;i<N;i++){
        Reszta[i]=0;
    }

    IleMon(Reszta);

    for(int i=0;i<N;i++){
        cout<<"Nominal "<<NOMIN[i]<<" - "<<Reszta[i]<<endl;  
    }

    return 0;
}

cw 6
#include <iostream>

using namespace std;

const int N=4;
int P[N][N];

void los(){
   for(int i=0; i<N; i++){
       for(int j=0; j<N; j++){
           P[i][j] = rand()%10;
       }
   }
}

void wypisz(){
   for(int i=0; i<N; i++){
       for(int j=0; j<N; j++){
           cout<<P[i][j]<<" ";
       }
       cout<<endl;
   }
}

int MaxSum(){
    for(int i=1;i<N;i++){
        P[0][i]+=P[0][i-1];
        P[i][0]+=P[i-1][0];
    }
    for(int i=1;i<N;i++){
        for(int j=1;j<N;j++){
            P[i][j]+=max(P[i-1][j],P[i][j-1]);
        }
    }
    return P[N-1][N-1];
}

int main(){

    los();
    wypisz();

    cout<<endl;

    cout<<MaxSum();
    
    return 0;
}

cw 7
a)
dodajemy przedmiot 0 -> wartosc(6) + 3
dodajemy przedmiot 1 -> wartosc(6) + 4
przedmiot 2 -> wartosc(5) + 10
przedmiot 3 -> wartosc (4) + 11
przedmiot 4 -> wartosc (3) + 15

b)
https://gamma.app/docs/Problem-Plecakowy-i-Programowanie-Dynamiczne-ugpuj21ruf7pkcj

cwicz 8

#include <iostream>
#include <fstream>

using namespace std;

const int N = 5;
const int makswaga = 17;

struct przedmiot{
    int wart, waga;
};


int backpack(przedmiot P[]){

    int w[makswaga+1];
    for(int i=0; i <= makswaga; i++){
        w[i]=0;
    }
    for(int i=0; i <= makswaga; i++){
        for(int j=0; j < N; j++){
            if(P[j].waga <= i){
                if(w[i-P[j].waga] + P[j].wart > w[i]){
                    w[i] = w[i-P[j].waga] + P[j].wart;
                }
            }
        }
    }
    return w[makswaga];
}

int main(){
    
    przedmiot P[N];
    ifstream we("do-plecaka.txt");


    for(int i=0; i<N; i++){
        we>>P[i].wart>>P[i].waga;
    }
    we.close();

    cout<<backpack(P)<<endl;

    return 0;
}
