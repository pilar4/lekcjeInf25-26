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
