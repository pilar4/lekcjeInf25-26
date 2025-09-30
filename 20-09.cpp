#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>


using namespace std;




void ciout(int tab[]){
    for(int i=0; i<sizeof(tab); i++)
        cout<<tab[i]<<" ";
    cout<<endl;
}
//cw1
void losuj(int n, int tab[]){
    for(int i=0; i<n; i++){
        tab[i]=rand();
    }
}


//cw2
void szukajLin(int n, int tab[]){
    losuj(n, tab);
    ciout(tab);
    int x; cin>>x;
    for(int i=0; i<n; i++){
        if(tab[i]==x){
            cout<<"Znalazlem na pozycji: "<<i<<endl;
            return;
        }
    }
}


//cw3
void szukajBin(int n, int tab[]){
    losuj(n, tab);
    ciout(tab);
    int l=0, p=n-1, sr;
    int x; cin>>x; //szukane


    while(l<p){
        sr=(l+p)/2;
        if(tab[sr]==x){
            cout<<"Znalazlem na pozycji: "<<sr<<endl;
            return;
        }
        else if(tab[sr]<x) l=sr+1;
        else p=sr-1;
    }
}


//cw4
void minmaxing(int n, int tab[]){
    losuj(n, tab);
    sort(tab, tab+n); //include <algorithm>
    cout<<"Min: "<<tab[0]<<" Max: "<<tab[n-1]<<endl;
}


void zad1(int n, int tab[]){
    losuj(n, tab);
    int x; cin>>x;
    for(int i=0; i<n; i++){
        if(tab[i]==x){
            cout<<"Znalazlem na pozycji: "<<i<<endl;
            return;
        }
    }
}


void zad2(int n, int tab[]){
    losuj(n, tab);
    sort(tab, tab+n);
    int x; cin>>x;
    int l=0, p=n-1, sr;


    while(l<p){
        sr=(l+p)/2;
        if(tab[sr]==x){
            cout<<"Znalazlem na pozycji: "<<sr<<endl;
            return;
        }
        else if(tab[sr]<x) l=sr+1;
        else p=sr-1;
    }
}


void zad3(int n, int tab[]){
    losuj(n, tab);
    sort(tab, tab+n);
    cout<<"Min: "<<tab[0]<<" Max: "<<tab[n-1]<<endl;
}


void zad4(int n, int tab[]){
    losuj(n, tab);
    sort(tab, tab+n);
    cout<<tab[n-1]-tab[0]<<endl;
}




void zad5(int n, int tab[]){
    //to zadanie nie ma sensu
    //jak mam przyjac ze najpierw sa liczby nieparzyste a potem parzyste
    //i czemu mam binarnie szukac PIERWSZEJ liczby parzystej
    losuj(n, tab);
    sort(tab, tab+n);
    for(int i=0; i<n; i++){
        if(tab[i]%2==0){
            cout<<"Pierwsza liczba parzysta: "<<tab[i]<<" na pozycji: "<<i<<endl;
            return;
        }
    }
}


void zad6(){
    //nie, poniewaz nie uwzgledniamy opcji a[srodek]==x
}


void zad7(int n, int tab[]){
    losuj(n, tab);
    sort(tab, tab+n);
    int x; cin>>x;
    int l=0, p=n-1, sr, ans=-1;


    while(l<=p){
        sr=(l+p)/2;
        if(tab[sr]==x){
            ans=sr;
            p=sr-1;
        }
        else if(tab[sr]<x) l=sr+1;
        else p=sr-1;
    }
    if(ans!=-1) cout<<"Pierwsze wystapienie: "<<ans<<endl;
    else cout<<"Nie znaleziono"<<endl;


int main() {
   
    int n; cin>>n;
    int tab[n];


    szukajLin(n, tab);


    return 0;
}
