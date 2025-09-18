#include <iostream>
#include <vector>

using namespace std;


int licz[10];

void zad1 (long long n){
    while(n>0){
        licz[(n%10)-1]++;
        n = (n-(n%10))/10;
    }
    for(int i=0; i<10; i++) cout<<i+1<<" * "<<licz[i]<<endl;
}

void zad2 (){
    int n=67, x=-2137;
    while(n){
        cin>>n;
        if(n>x) x=n;
    }
    cout<<x;
}

void zad5 (){
    int n=67;
    while(n){
        cin>>n;
        zad1 (n);
    }
}

int main() {    

    for(int i=0; i<10; i++) licz[i]=0;

    //long long n; cin>>n; 
    zad2 ();

    return 0;
}
