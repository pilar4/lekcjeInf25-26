cw. 1
funkcja szukajlidera(A[])
	iwystapien<-0
	dla i <-0,1,...,n-1 wykonuj
		jesli iwystapien >n/2 to
			przerwij
		ile<-0
		dla j<- 0,1,...,n-1 wykonuj
			jesli A[j]=A[i] to 
				ile<-ile+1
				iwytapien<-iwystapien+1
		jesli ile>n div 2 to
			zwroc A[i] i zakoncz
	zwroc -1 zakoncz

cw. 2
Zrobilismy to na lekcji. O(n^2) i O(n)

cw3

#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

const int N = 10;
int A[N];

void los(){
    int x=rand()%100;
    for(int i=0; i<N; i++){
        if(rand()%2) A[i]=rand()%100;
        else A[i]=x;
    }
}

void test(){
    for(int i=0; i<N; i++){
        cout<<A[i]<<" ";
    }
}

int lider(){
    int I;
    for(int i=0; i<N; i++){
        I = 0;
        for(int j=0; j<N; j++){
            if(A[j] == A[i]){
                I++;
            }
        }
        if(I>N/2) return A[i];
    }
    return -1;
}

int main() {

    los();
    test();

    cout<<endl<<lider();
    
    return 0;
}


cw 4

#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

const int N = 10;
int A[N];

void los(){
    int x=rand()%100;
    for(int i=0; i<N; i++){
        if(rand()%2) A[i]=rand()%100;
        else A[i]=x;
    }
}

void test(){
    for(int i=0; i<N; i++){
        cout<<A[i]<<" ";
    }
}

int lider(){
    int I=0, Ka;
    sort(A, A + N);
    Ka = A[N/2];
    for(int i=0; i<N; i++){
        if(A[i] == Ka) I++;
    }
    if(I>N/2) return Ka;
    return -1;
}

int main() {

    srand(time(NULL));
    los();
    test();

    cout<<endl<<lider()<<endl;
    
    return 0;
}

cw 5
#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

const int N = 10;
int A[N];

void los(){
    int x=rand()%100;
    for(int i=0; i<N; i++){
        if(rand()%2) A[i]=rand()%100;
        else A[i]=x;
    }
}

void test(){
    for(int i=0; i<N; i++){
        cout<<A[i]<<" ";
    }
}

int lider(){
    int I;
    for(int i=0; i<N; i++){
        I = 0;
        for(int j=0; j<N; j++){
            if(A[j] == A[i]){
                I++;
            }
        }
        if(I>N/2) return A[i];
    }
    return -1;
}

int SzukajLidera(){
    int kandydat, ile=0;
    for(int i=0;i<N;i++){
        if (!ile){
            ile = 1;
            kandydat = A[i];
        } else if (A[i]==kandydat) ile++;
        else ile--;
    }
    if(!ile) return-1;
    ile=0;
    for(int i=0;i<N;i++){
        if(A[i]==kandydat) ile++;
    }
    if(ile>N/2) return kandydat;
    else return -1;
        
}

int main() {

    srand(time(NULL));
    los();
    test();

    cout<<endl<<SzukajLidera();
    
    return 0;
}

cw 7

#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

const int N = 5;
bool A[N][N];


void los(){
    int idol;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            A[i][j] = rand()%2;
        }
    }
    if(rand()%2){
        idol = rand()%N;
        for (int i=0; i<N; i++){
            A[i][idol] = true;
        }
        for (int j=0; j<N; j++){
            A[idol][j] = false;
        }
    }

}

void test(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(i!=j) cout<<A[i][j]<<" ";
            else cout<<"   ";
        }
        cout<<endl;
    }
}

int SzukajIdola(){
    int kandydat=0, i;
    bool jest_kandydat=false;
    while(kandydat<N && !jest_kandydat){
        i=0;
        A[kandydat][kandydat]=false;
        while (i<N && !A[kandydat][i]) i++;
        if(i==N) jest_kandydat=true;
        else kandydat++;
    }
    if(!jest_kandydat) return -1;

    i=0; A[kandydat][kandydat]=true;
    while (i<N && A[i][kandydat]) i++;
    if(i==N) return kandydat;
    else return -1;
}

int main() {

    srand(time(NULL));
    los();
    test();

    cout<<"Idol ma indeks: "<<SzukajIdola()<<endl;
    
    return 0;
}

cw 8 

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>

using namespace std;

const int N=5;

void losuj(int A[][N]){
    int idol;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            A[i][j] = rand()%2;
        }
    }
    if(rand()%2){
        idol = rand()%N;
        for (int i=0; i<N; i++){
            A[i][idol] = true;
        }
        for (int j=0; j<N; j++){
            A[idol][j] = false;
        }
    }

}

void wypisz(int A[][N]){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(i!=j) cout<<A[i][j]<<" ";
            else cout<<"   ";
        }
        cout<<endl;
    }
}
int szukajido(int A[][N]){
    int kandydat=0,i=1;
    while(i<N){
        if(A[kandydat][i]){
            kandydat=i;  
        }
        i++;
    }
    i=0;A[kandydat][kandydat]=false;
    while(i<N && !A[kandydat][i]){
        i++;
    }
    if(i<N){
        return -1;
    }
    i=0;A[kandydat][kandydat]=true;
    while(i<N && A[i][kandydat]){
        i++;
    }
    if(i==N){
        return kandydat;
    }
    else{
        return -1;
    }
}

int main(){

  int A[N][N];

  srand(time(NULL));
  losuj(A);
  wypisz(A);

  cout<<endl<<"Indeks idola: "<<szukajido(A);
  return 0;
}
