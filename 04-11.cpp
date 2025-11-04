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

zad 2
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
            A[i][j] = rand()%10;
        }
    }
    if(rand()%2){
        SzukajIdola = rand()%N;
        for (int i=0; i<N; i++){
            A[i][SzukajIdola] = true;
        }
        for (int j=0; j<N; j++){
            A[SzukajIdola][j] = false;
        }
    }
}

void wypisz(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
}

void sortwier(){
    for(int k=0;k<N;k++){
      sort(A[k],A[k]+N);
    }
}

int main() {

    srand(time(NULL));
    los();
    wypisz();

    cout<<endl;

    sortwier();

    wypisz();

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

zad 4
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

int sumy_k[N];
void sumyKolumn(){
    for(int i=0;i<N;i++){
        int suma=0;
        for(int j=0;j<N;j++){
            suma += A[j][i];
        }
        sumy_k[i]=suma;
        // cout<<endl<<suma<<" test kolumny";
    }
    
}

int sumy_w[N];
void sumyWierzy(){
    for(int i=0;i<N;i++){
        int suma=0;
        for(int j=0;j<N;j++){
            suma += A[i][j];
        }
        sumy_w[i]=suma;
        // cout<<endl<<suma<<" test wierszy";
    }
}



int main() {

    srand(time(NULL));
    los();
    test();
    sumyKolumn();
    sumyWierzy();
    
    cout<<endl;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(sumy_k[i]==sumy_w[j]){
                cout<<"kolumna: "<<i+1<<" "<<"wiersz: "<<j+1<<endl;
                return 0;
            }
        }
    }
    cout<<"BRAK";
    
    return 0;
}


zad 6
#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

const int N = 16;
int A[N][N];
const int randommax = 400;

void los(){

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            A[i][j] = rand()%randommax;
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

int tab[randommax];
void zlicz_wystapienia(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            tab[A[i][j]]++;
        }
    }

    for(int i=0;i<randommax;i++){
        if(tab[i]>N/4) cout<<i<<" wystapilo wiecej niz N/4 razy"<<endl;
    }
}



int main() {

    srand(time(NULL));
    los();
    test();
    cout<<endl;
    zlicz_wystapienia();

    
    
    return 0;
}
