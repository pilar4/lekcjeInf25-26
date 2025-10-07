// -----------------CW1
#include<iostream>
using namespace std;


const int N=6;


void Sortuj(int A[]){
   int i, j, pom;
   for(i=1;i<N;i++){
       for(j=0;j<N-i;j++){
           if(A[j]>A[j+1]){
               pom=A[j];
               A[j]=A[j+1];
               A[j+1]=pom;
           }
       }
   }
}


int main(){
   int A[N] = {3,4,6,1,7,5};
   Sortuj(A);
   for(int i=0;i<N;i++){
       cout<<A[i];
   }
}



// ------------------CW2
#include<iostream>
using namespace std;

const int N=10;

void Sortuj(int A[]){
    int i, j, pom, m;
    for(i=0;i<N-1;i++){
        m=i;
        for(j=i+1;j<N;j++){
            if(A[j]<A[m]){
                m=j;
            }
        }
        pom=A[i];
        A[i]=A[m];
        A[m]=pom;
    }
}

int main(){
    int A[N] = {3, 4, 6, 1, 7, 5, 9, 2, 5, 9};
    Sortuj(A);
    for(int i=0;i<N;i++){
        cout<<A[i];
    }
    cout<<'\n';
}

//---------------------CW3
#include<iostream>
using namespace std;

const int N=10;
int A[N+2] = {0, 0, 3, 4, 6, 1, 7, 5, 9, 2, 5, 9};
void Sortuj(int A[]){
    int i, j;
    for(i=2;i<=N;i++){
        A[0]=A[i];
        j=i-1;
        while(A[j]>A[0]){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=A[0];
    }
        
}

int main(){
    
    Sortuj(A);
    for(int i=2;i<=N+1;i++){
        cout<<A[i];
    }
    cout<<'\n';
}



//------------------CW4




