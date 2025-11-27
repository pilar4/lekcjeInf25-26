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


