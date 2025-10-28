zad 1

#include <iostream>
#include <cmath>
using namespace std;


const int N = 10;
int A[N];

void losuj(int A[]){
   for(int i=0;i<N;i++)
       A[i]=rand()%100-50;
   A[rand()%N]=rand()%50;
}

void Wpisz(int A[]){
   for(int i=0;i<N;i++){
       cout<<A[i]<<" "<<endl;
   }
}

int NSPNM(){
   int maks_dl = 1, akt_dl = 1, maks_pocz = 0, akt_pocz = 0;
   for(int i = 1; i < N; i++){
       if(A[i] < A[i-1]){
           akt_dl++;
           if(akt_dl > maks_dl){
               maks_dl = akt_dl;
               maks_pocz = akt_pocz;
           }
       }
       else {
           akt_dl = 1; akt_pocz = i;
       }
   }
   return maks_pocz;
}


int main() {

    losuj(A);
    Wpisz(A);


    int g = NSPNM();


   do{
       cout<<A[g]<<" "; g++;
   }
   while(g < N && A[g] < A[g-1]);

  
   return 0;
}

zad 2

#include <iostream>
#include <cmath>
using namespace std;


const int N = 10;
int tab[N];


int NSPNM(){
   int maks_dl = 1, akt_dl = 1, maks_pocz = 0, akt_pocz = 0;
   for(int i = 1; i < N; i++){
       if(tab[i] >= tab[i-1]){
           akt_dl++;
           if(akt_dl >= maks_dl){
               maks_dl = akt_dl;
               maks_pocz = akt_pocz;
           }
       }
       else {
           akt_dl = 1; akt_pocz = i;
       }
   }
   return maks_pocz;
}


int main() {


   for(int i = 0; i < N; i++){
       cin>>tab[i];
   }


   int g = NSPNM();


   do{
       cout<<tab[g]<<" "; g++;
   }
   while(g < N && tab[g] >= tab[g-1]);
  
   return 0;
}

zad 3
