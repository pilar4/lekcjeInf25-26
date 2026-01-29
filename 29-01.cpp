zad 3
#include<iostream>
#include<random>
using namespace std;

const int N = 10;
int tab[N];

void losowanie(){
    srand(time(0));
    for(int i=0;i<N;i++){
        tab[i]=rand()%19-9;
    }
}

void wypisz(){
    cout<<endl;
    for(int i=0;i<N;i++)
        cout<<tab[i]<<" ";
}

void bubble_sort(){
    for(int i = 0; i < N - 1; i++){
        for(int j = 0; j < N - 1 - i; j++){
            if (abs(tab[j]) > abs(tab[j+1])) {
                swap(tab[j], tab[j+1]);
            }
        }
    }
}



int main(){
    losowanie();
    wypisz();
    bubble_sort();
    wypisz();

}


zad 5
#include<iostream>
#include<random>
using namespace std;

const int N = 10;
int tab[N];

void losowanie(){
    srand(time(0));
    for(int i=0;i<N;i++){
        tab[i]=rand()%100;
    }
}

void wypisz(){
    cout<<endl;
    for(int i=0;i<N;i++)
        cout<<tab[i]<<" ";
}

void bubble_sort(){
    for(int i = 0; i < N - 1; i++){
        for(int j = 0; j < N - 1 - i; j++){
            if ((tab[j]%10) > (tab[j+1]%10)) {
                swap(tab[j], tab[j+1]);
            }
        }
    }
}



int main(){
    losowanie();
    wypisz();
    bubble_sort();
    wypisz();

}
