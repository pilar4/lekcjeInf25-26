Praca samodzielna / korzystałem z pomocy ……………………………

Zad. 1
c
Zad. 2
funkcja ciagrek(n)
	jezeli n=0 to
		zwroc 1
	jezeli n>0 to
		zwroc 2*ciagrek(n-1)

funkcja ciagiter(n)
	wynik <- 1
	dla i <- 1,2,3…,n wykonuj
		wynik <- 2* wynik
	zwroc  wynik
Zad. 3


Zad. 4
#include <iostream>
using namespace std;


int ciag(int n){
    
    if(n==1){
        return 2;
    }
    else{
        return ciag(n-1)*2;
    }

}

int main(){
    int x; cin>>x;
    int y = ciag(x);
    if(x%2==1){
        y = y * -1;
    }
    cout<<y<<'\n';
    
}

Zad. 5


Zad. 6


Zad. 7


Zad. 8


Zad. 9


Zad. 10



