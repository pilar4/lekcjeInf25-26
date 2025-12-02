zad 1
#include <iostream>
using namespace std;

const int N=4;
const int NOMINALY[]={1,4,5};
const int KWOTA=9;

int IleMonet(){
    int i, j;
    int IleM[KWOTA+1];
    
    IleM[0]=0;
    for(i=1;i<=KWOTA;i++)
        IleM[i]=KWOTA+1;

    for(j=0;j<N;j++){
        for(i=NOMINALY[j];i<=KWOTA;i++){
            if(IleM[i-NOMINALY[j]]+1<IleM[i]){
                IleM[i]=IleM[i-NOMINALY[j]]+1;
            }
        }
    }
    return IleM[KWOTA];
}

int main(){
    cout<<"Minimalna liczba monet dla kwoty ";
    cout<<KWOTA<<": "<<IleMonet()<<endl;
    return 0;
}

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


zadanie numer cztery

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> c(n + 1);
    for (int i = 1; i <= n; i++) cin >> c[i];

    vector<int> R(n + 1, 0);
    vector<int> S(n + 1, 0);

    for (int j = 1; j <= n; j++) {
        int najlepszy = -1000000000;
        int najlepsze_i = 1;

        for (int i = 1; i <= j; i++) {
            int wartosc = c[i] + R[j - i];
            if (wartosc > najlepszy) {
                najlepszy = wartosc;
                najlepsze_i = i;
            }
        }

        R[j] = najlepszy;
        S[j] = najlepsze_i;
    }

    cout << "Maksymalny zysk: " << R[n] <<endl;

    return 0;
}
