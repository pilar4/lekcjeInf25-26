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
