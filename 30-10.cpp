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
