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


Zad. 6


Zad. 7


Zad. 8


Zad. 9


Zad. 10



