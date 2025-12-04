cwiczenie 1

czwicz 2 

  #include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int N = 20;

void losuj(int A[]){
    for(int i=0; i<N; i++){
        A[i] = rand()%100;
    }
}

void wypisz(int A[]){
    for(int i=0; i<N; i++){
        cout<<A[i]<<" ";
    }
}

void quickSort (int A[], int p, int k){
    int i=p, j=k, m=A[(p+k)/2];

    while(i<=j){
        while(A[i] < m) i++;
        while(A[j] > m) j--;
        if(i<=j){
            swap(A[i], A[j]);
            i++; j--;
        }
    }

    if(p < j) quickSort(A, p, j);
    if(i < k) quickSort(A, i, k);
}

int main(){

    int A[N];
    srand(time(NULL));
    losuj(A);
    wypisz(A);
    cout<<endl<<endl;

    quickSort(A, 0, N-1);

    wypisz(A);
    cout<<endl;

    return 0;
}

Ć∑aficanie 3

#include <iostream>

using namespace std;

const int N=10;

void losuj(int A[]){
for(int i=0;i<N;i++){
 A[i]=rand()%10;
}
}

void wypisz(int A[]){
for(int i=0;i<N;i++){
 cout<<A[i]<<" ";
}
}

void QuiSot(int A[], int p, int k){
    int i, j, m;
    while(p<k){
        i=p; j=k; m=A[(p+k)/2];
        while(i<=j){
            while(A[i]<m){
                i++;
            }
            while(A[j]>m){
                j--;
            }
            if(i<=j){
                swap(A[i],A[j]);
                i++; j--;
            }
        }
        if(j-p<k-i){
            QuiSot(A,p,j);
            p=i;
        }
        else{
            QuiSot(A,i,k);
            k=j;
        }
    }
}

int main(){

    int A[N];

    losuj(A);
    wypisz(A);

    cout<<endl<<endl;

    QuiSot(A,0,N-1);
    wypisz(A);

    return 0;
}
