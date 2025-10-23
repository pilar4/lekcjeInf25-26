//karol to pisal
Ćw. 1
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
const int N=10;

void losuj(int A[],int N){
for(int i=0;i<N;i++){
  A[i]=rand()%10;
}
}

void wypisz(int A[],int N){
for(int i=0;i<N;i++){
  cout<<A[i]<<" "<<endl;
}
}

int DNSPNM(int A[]){
   int max_dl=1, akt_dl=1;
   for(int i=1;i<N;i++){
       if(A[i]>=A[i-1]){
           akt_dl++;
           if(akt_dl>max_dl){
               max_dl=akt_dl;
           }
       }
       else{
           akt_dl=1;
       }
   }
   return max_dl;
}

int main(){
   int A[N];

   srand(time(NULL));
   losuj(A,N);
   wypisz(A,N);

   cout<<DNSPNM(A);

   return 0;
}

Ćw. 2
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int N=10;

void losuj(int A[],int N){
for(int i=0;i<N;i++){
  A[i]=rand()%10;
}
}

void wypisz(int A[],int N){
for(int i=0;i<N;i++){
  cout<<A[i]<<" "<<endl;
}
}

int NSPNM(int A[]){
   int max_dl=1, akt_dl=1, maks_pocz=0, akt_pocz=0;
   for(int i=1;i<N;i++){
       if(A[i]>=A[i-1]){
           akt_dl++;
           if(akt_dl>max_dl){
               max_dl=akt_dl;
               maks_pocz=akt_pocz;
           }
       }
       else{
           akt_dl=1;
           akt_pocz=i;
       }
   }
   return maks_pocz;
}

int main(){
   int A[N],i;

   srand(time(NULL));
   losuj(A,N);
   wypisz(A,N);

   i=NSPNM(A);
   do{
       cout<<A[i]<<" ";
       i++;
   }
   while(i<N && A[i]>=A[i-1]);

   return 0;
}

Ćw. 3
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int N=10;

void losuj(int A[],int N){
for(int i=0;i<N;i++){
  A[i]=rand()%10;
}
}

void wypisz(int A[],int N){
for(int i=0;i<N;i++){
  cout<<A[i]<<" "<<endl;
}
}

int DNSPNM(int A[]){
   int max_dl=1, akt_dl=1;
   for(int i=1;i<N;i++){
       if(A[i]>=A[i-1]){
           akt_dl++;
           if(akt_dl>max_dl){
               max_dl=akt_dl;
           }
       }
       else{
           akt_dl=1;
       }
   }
   return max_dl;
}

int NSPNM(int A[], int &max_dl){
   max_dl=1;
   int akt_dl=1, maks_pocz=0, akt_pocz=0;
   for(int i=1;i<N;i++){
       if(A[i]>=A[i-1]){
           akt_dl++;
           if(akt_dl>max_dl){
               max_dl=akt_dl;
               maks_pocz=akt_pocz;
           }
       }
       else{
           akt_dl=1;
           akt_pocz=i;
       }
   }
   return maks_pocz;
}

int main(){
   int A[N],p,dl;

   srand(time(NULL));
   losuj(A,N);
   wypisz(A,N);

   p=NSPNM(A,dl);
   for(int i=p;i<p+dl;i++){
       cout<<A[i];
   }

   return 0;
}

Ćw. 4
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int N=10;

void losuj(int A[],int N){
for(int i=0;i<N;i++)
  A[i]=rand()%100-50;
A[rand()%N]=rand()%50;
}

void wypisz(int A[],int N){
for(int i=0;i<N;i++){
  cout<<A[i]<<" "<<endl;
}
}

int MSPS(int A[]){
   int maks_suma=0,akt_suma;
   for(int i=0;i<N;i++){
       for(int j=i;j<N;j++){
           akt_suma=0;
           for(int k=i;k<=j;k++){
               akt_suma+=A[k];
               if(akt_suma>maks_suma){
                   maks_suma=akt_suma;
               }
           }
       }
   }
   return maks_suma;
}

int main(){
   int A[N];

   srand(time(NULL));
   losuj(A,N);
   wypisz(A,N);

   cout<<MSPS(A);
   return 0;
}

Ćw. 5

Ćw. 6

Ćw. 7

Ćw. 8

Ćw. 9
