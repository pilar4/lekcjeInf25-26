zad 1
#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

const int N = 5;
int A[N][N];

void los(){

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




zad 3
#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

const int N = 5;
int A[N][N];

void los(){

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            A[i][j] = rand()%10;
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

void sortujKolumny(int k){
    int tab[N];
    for(int i=0;i<N;i++){
        tab[i] = A[i][k];
    }
    sort(tab, tab + N);
    for(int i=0;i<N;i++){
        A[i][k] = tab[i];
    }
}

int main() {

    srand(time(NULL));
    los();
    test();
    for(int i=0;i<N;i++){
        sortujKolumny(i);
    }
    cout<<endl<<endl;
    test();
    
    
    return 0;
}

