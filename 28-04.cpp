cw 1

#include <iostream>

using namespace std;


int Znajdz(string w, string t)
{
    int dw = w.size();
    int dt = t.size();
    int i, p = 0;

    while (p <= dt - dw)
    {
        i = 0;
        while (i < dw && w[i] == t[p + i])
            i++;

        if (i == dw)
            return p;
        else
            p++;
    }

    return -1;
}

int main(){
    string t, w;
    cout<<"podaj tekst i wzorzec"<<endl;
    cin>>t>>w;

    cout<<Znajdz(w,t);

}


cw 2 
  np. modulo, gdzie wszystkie liczby są zapisywane jako reszta z dzielenia przez pewną liczbę

Ćw.3 
a)
(7+15)mod 5 = 2 
(7-15)mod 5 = 2
(7*15)mod 5 = 0
b) 
(5+11) mod 13 = 3
(5-11) mod 13 = 7
(5*11) mod 13 = 3

