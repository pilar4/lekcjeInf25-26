zad 2
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
           cout<<" "<<max(P[i-1][j],P[i][j-1]);
       }
   }
   return P[N-1][N-1];
}


int main(){
   los();
   wypisz();

   cout<<endl;

   int max=MaxSum();

   cout<<endl<<" Maxsumto "<<max;
  
   return 0;
}



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
