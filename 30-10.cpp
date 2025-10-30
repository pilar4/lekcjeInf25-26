cw. 1
mozemy zapamietac ilosc sprawdzantch elementow w zmiennej pomocniczej i gdy przekroczy polowe rozmiaru tablicy to wiadomo ze nie bedzie lidera. 

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
