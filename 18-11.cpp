Praca samodzielna / korzystałem z pomocy ……………………………


Zad. 1
na lekcji
c)
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

Zad. 2
#include <iostream>

using namespace std;

int NWD(int a, int b){
    int pom;
    while(b!=0){
        pom=b;
        b=a%b;
        a=pom;
    }
    return a;
}

int main(){
    int a,b,n;
    cin>>n;
    cin>>a;
    cin>>b;
    a=NWD(a,b);
    for(int i=2;i<n;i++){
        cin>>b;
        a=NWD(a,b);
    }

    cout<<a;

    return 0;
}

Zad. 3

funkcja ciagrek(n)
	jezeli n = 1 to
		zwroc 1
	jezeli n = 2 to
		zwroc 2
	jeżeli n mod 2 = 1 to
		zwroc ciagrek(n-1) + ciagrek(n-2)
	w przeciwnym wypadku
		zwroc ciagrek(n-1) + ciagrek(n-2) + 1

Zad. 4
funkcja ciag(n)
	jezeli n = 1
		zwroc 2
	zwroc ciag(n-1)*2


funkcja main()
	int x <- dane wejsciowe
	jezeli x%2==1
		wypisz ciag(x) * -1
		zakoncz
	ciag(x)

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
a)ciag fibbonaciego tylko wszedzie jest odejmowanie / liczby na minusie
b) An = An-1 - An-2 gdzie A1=-1 i A2=-1
#include <iostream>


using namespace std;


int fibo(int n){
   if(n<=2){
       return -1;
   }
   return fibo(n-1) - fibo(n-2);
}


int main(){
   int a; cin>>a;
   cout<<fibo(a);
}


Zad. 6


Zad. 7

	wpisz n;
jezeli n=1 to przenies (a,c); zakoncz
przenies(a,b) n-1 krazkow
przenies(a,c) (najwiekszy) krazek
przenies(b,c) n-1 krazkow


Zad. 8


Zad. 9


Zad. 10



