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
