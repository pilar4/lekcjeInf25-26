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


    cw4
a)
bcba n=11 → (1*3^3 + 2*3^2 + 1*3^1 + 0*3^0)=(27+18+3)=48    48 mod 11 = 4
b)
abccbb n=29 → (0*3^5 + 1*3^4 + 2*3^3 + 2*3^2 + 1*3^1 + 1*3^0)=157   157 mod 29 = 12



cw 5

#include <iostream>

using namespace std;

const int N = 997; // liczba pierwsza
const int M = 26;  // długość alfabetu

int Potega(int podst, int wykl)
{
    int w = 1;
    while (wykl > 0)
    {
        if (wykl % 2 == 1) w = (w * podst) % N;
        wykl = wykl / 2;
        if (wykl > 0) podst = (podst * podst) % N;
    }
    return w;
}

int Hash0(string s)
{
    int w = 0;
    for (int i = 0; i < s.size(); i++)
        w = ((w * M) % N + s[i] - 'a') % N;
    return w;
}

int Hash1(int h0, int jd, char ch)
{
    int w = (h0 - jd) % N;
    if (w < 0) w = w + N;
    return ((w * M) % N + ch - 'a') % N;
}

int Znajdz(string w, string t)
{
    int i, p = 0, dw = w.size(), dt = t.size();
    int hw = Hash0(w);
    int ht = Hash0(t.substr(0, dw));
    int pot = Potega(M, dw - 1);

    while (p <= dt - dw)
    {
        if (hw == ht)
        {
            i = 0;
            while (i < dw && w[i] == t[p + i]) i++;
            if (i == dw) return p;
        }

        if (p < dt - dw)
            ht = Hash1(ht, (pot * (t[p] - 'a')) % N, t[p + dw]);

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
