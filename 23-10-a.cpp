#include <iostream>
#include <cmath>
using namespace std;

const int N = 10;
int tab[N];

int DNSPNM(){
    int maks_dl=1, akt_dl=1, i;
    for(i=1;i<N;i++){
        if(tab[i]>=tab[i-1]){
            akt_dl++;
            if(akt_dl>maks_dl) maks_dl=akt_dl;
        } else {
            akt_dl=1;
        }
    }

    return maks_dl;
}

int main() {

    for(int i=0;i<N;i++){
        cin>>tab[i];
    }

    cout<<DNSPNM();
    
    return 0;
}
