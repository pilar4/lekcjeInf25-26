nigga


zad 3

  #include <iostream>
#include <fstream>


using namespace std;


const int N = 5;
const int makswaga = 15;


struct przedmiot{
   int wart, waga;
};




int backpack(przedmiot P[]){

    int w[makswaga+1];
    for(int i=0; i <= makswaga; i++){
       w[i]=0;
   }
   
    for(int j=0; j < N; j++){
        for(int i = makswaga; i >= P[j].waga; i--){
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

   ifstream we("do_plecaka.txt");
   for(int i=0; i<N; i++){
       we>>P[i].wart>>P[i].waga;
   }
   we.close();


   cout<<backpack(P)<<endl;


   return 0;
}
