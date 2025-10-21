//sito eratostelesa

cw1
O = n^2
cw2
prześledziłem

cw3

Sito

Dla i od 2 do N:
	pierwsze[i] = prawda
i = 2
Dopóki i * i <= N:
	Jeżeli pierwsze[i] to prawda:
		j = i * i
		Dopóki j <= N:
			pierwsze[j] = falsz
			j = j + i
	i = i + 1
zakoncz

cw4
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


void sito(int pierwsza[],int n)
{
   pierwsza[2]=true;
   for(int i=3;i<n;i++)
   {
       pierwsza[i]=(i%2==1);
   }
   int d=3;
   while(d*d<n)
   {
       for(int i=d;i*d<n;i+=2)
       {
           pierwsza[i*d]=false;
       }
       do
       {
           d+=2;
       }
       while(!pierwsza[d]);
   }
}
int main()
{
   int n;
   cin >> n;
   int pierwsza[n];
   for(int i=0;i<n+2;i++)
   {
       pierwsza[i-2]=i+2;
   }
   sito(pierwsza,n);
   for(int i=2;i<n;i++)
   {
       if(pierwsza[i])
       {
           cout << i << " ";
       }
   }
}


Zad. 1
#include <iostream>
#include <cmath>
using namespace std;


const int N = 1000000;
bool pierwsze[N];


void SitoEratostenesa(bool pierwsze[]){
   pierwsze[2] = true;
   for(int i=3; i<N; i++){
       pierwsze[i] = (i%2==1);
   }
   int d=3;


   while(d*d<N){
       for(int i=d; i*d<N; i+=2){
           pierwsze[i*d] = false;
       }
       do
           d+=2;
       while(!pierwsze[d]);
   }
}




bool pierwsza(int n) {
  if (n < 2) return false;
  for (int i = 2; i <= sqrt(n); i++) {
      if (n % i == 0)
          return false;
  }
  return true;
}


int main() {
   SitoEratostenesa(pierwsze);
   int s, k;
   cin >> s;
   cin >> k;


   for(int i=s;i<=k;i++){
       if(pierwsze[i])
           cout<<i<<" ";
   }


   // for (int liczba = s; liczba <= k; liczba++) {
   //    if (pierwsza(liczba))
   //        cout << liczba << endl;
   // }
   return 0;
}




Zad. 2
#include <iostream>
#include <cmath>
using namespace std;


const int N = 1000000;
bool pierwsze[N];


void SitoEratostenesa(bool pierwsze[]){
   pierwsze[2] = true;
   for(int i=3; i<N; i++){
       pierwsze[i] = (i%2==1);
   }
   int d=3;


   while(d*d<N){
       for(int i=d; i*d<N; i+=2){
           pierwsze[i*d] = false;
       }
       do
           d+=2;
       while(!pierwsze[d]);
   }
}




bool pierwsza(int n) {
  if (n < 2) return false;
  for (int i = 2; i <= sqrt(n); i++) {
      if (n % i == 0)
          return false;
  }
  return true;
}


int main() {
   SitoEratostenesa(pierwsze);
   int k;
   cin >> k;


   for(int i=2;i<=k;i++){
       if(pierwsze[i] && pierwsze[i+2])
           cout<<i<<", "<<i+2<<"\n";
   }


  
   return 0;
}





Zad. 3
#include <iostream>
#include <cmath>
using namespace std;

const int N = 1000000;
bool pierwsze[N];

void SitoEratostenesa(bool pierwsze[]){
    
    for(int i=0; i<N; i++){
        pierwsze[i] = true;
    }
    pierwsze[0] = false;
    int d=3;

    while(d*d<2*N){
        if(pierwsze[(d-1/2==true)])
        {
            int k=d;
            int j=(k*d-1)/2;
            while(j<N){
                pierwsze[j]=false;
                k+=2;
                j=(k*d-1)/2;
            }
        }
        d+=2;
    }
}

int main() {
    SitoEratostenesa(pierwsze);
    int k;
    cin >> k;

    for(int i=0;i<=k/2-1;i++){
        if(pierwsze[i])
            cout<<(2*i)+1<<", ";
    }

    
    return 0;
}


Zad. 4

	#include <iostream>
#include <cmath>
using namespace std;

const int N = 1000000;
bool pierwsze[N];

void SitoEratostenesa(bool pierwsze[]){
   pierwsze[2] = true;
   for(int i=3; i<N; i++){
       pierwsze[i] = (i%2==1);
   }
   int d=3;


   while(d*d<N){
       for(int i=d; i*d<N; i+=2){
           pierwsze[i*d] = false;
       }
       do
           d+=2;
       while(!pierwsze[d]);
   }
}

int main() {
    SitoEratostenesa(pierwsze);
    int k;
    cin >> k;

    for(int i=2; i<=k; i++){
        for(int j=i; j<=k; j++){
            if(pierwsze[i] && pierwsze[j]){
                cout<<i*j<<" ";
            }
        }
        cout<<'\n';
        
    }

    
    return 0;
}


Zad. 5



