Ćw. 1
a(n) = a(n-1) + 3 rekurencyjnie
a(n) = 3n - 1

n(i) = n(i-1)*3 + 1      nastepna liczba to 200
Ćw. 2
w arkuszu (użycie funkcji SILNIA())
Ćw. 3
#include <iostream>


using namespace std;




long long sil(int n){
   if(n<2){
       return 1;
   }
   return sil(n-1)*n;
}
int main(){
   int n;cin>>n;


   cout<<endl<<sil(n);


   return 0;
}

Ćw. 4
#include <iostream>

using namespace std;

void DeNBin(int n){
    if(n<10){

        cout<<n<<endl;
    }
    else{
        DeNBin(n/10);
        cout<<n%10<<endl;
    }
}
int main(){
    int n;cin>>n;

    DeNBin(n);

    return 0;
}
Ćw. 5
6 mnożeń
Ćw. 6
ten sam ciąg tylko przesunięty o jeden

w arkuszu (w każdej następnej kratce np K5 wpisywać =K4+K3)
Ćw. 7

Ćw. 8

Ćw. 9

Ćw. 10



