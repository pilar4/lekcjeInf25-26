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

