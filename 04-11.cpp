zad 1
#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

const int N = 5;
int A[N][N];

void los(){
    int SzukajIdola;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            A[i][j] = rand()%100;
        }
    }
}

void test(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout<<A[i][j]<<" ";

        }
        cout<<endl;
    }
}

int main() {

    srand(time(NULL));
    los();
    test();

    int pom=-1;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(A[i][j]>pom) pom = A[i][j];
        }
    }
    cout<<pom;
    
    return 0;
}
