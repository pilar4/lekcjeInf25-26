zad 1
1/3 - bi0,(01)

zad 2
1/3 dzies = 0,1 w troj

zad 3
123,375 dziesiętny = bi-01111011,01100000

zad 4 

100,1 → 1100100,0001100110011… (bi) → 11,00100000110011… (bi) * 2^6

wykladnik - 6 + 1023 = 1029 → 10000000101 (bi)

mantysa - 0 10000000101 1001000001100110011001100110011001100110011001100110


zad 5
#include <iostream>
#include <list>
using namespace std;

struct wymierna{
    int calk;
    int licz;
};

int main()
{
    int licz, mian, j=0;
    cout<<"Licznik: "; cin>>licz;
    cout<<"Mianownik: "; cin>>mian;

    string s="0,";
    bool jest_okres=false;
    wymierna w;

    list<wymierna> Tab;
    int i = 0, pos = 0;

    while (!jest_okres)
    {
        licz = licz * 2;
        w.calk = licz / mian;
        licz = licz % mian;
        w.licz = licz;
        i = 0;
        pos = 0;

        for (auto it = Tab.begin(); it != Tab.end() && !jest_okres; ++it)
        {
            if (it->calk == w.calk && it->licz == w.licz)
            {
                jest_okres = true;
                pos = i;
            }
            i++;
        }
        if (!jest_okres) Tab.push_back(w);
    }

    j = 0;

    for (auto it = Tab.begin(); it != Tab.end(); ++it)
    {
        if (j == pos) s = s + '(';
        if (it->calk == 1) s = s + '1';
        else s = s + '0';
        j++;
    }
    s = s + ')';
    cout<<"Rozwiniecie binarne: "<<s;

    return 0;
}

zad 6
#include <iostream>
using namespace std;

struct wymierna{
    int calk;
    int licz;
};

int main()
{
    int licz, mian, i, j;
    cout<<"Licznik: "; cin>>licz;
    cout<<"Mianownik: "; cin>>mian;
    string s="0,";
    bool jest_okres=false;
    wymierna w;
    vector<wymierna> Tab;
    while (!jest_okres)
    {
        licz=licz*2;
        w.calk=licz/mian;
        licz=licz%mian;
        w.licz=licz;
        i=0;
        while(i<Tab.size() && !jest_okres)
            if(Tab[i].calk==w.calk && Tab[i].licz==w.licz)
                jest_okres=true;
        else i++;
    if (!jest_okres) Tab.push_back(w);
    }
    for (j=0;j<Tab.size();j++)
    {
        if (j==i) s=s+'(';
        if (Tab[j].calk==1) s=s+'1';
        else s=s+'0';
    }
    s=s+')';
    cout<<"Rozwiniecie binarne: "<<s;
    return 0;
}

zad 7

#include <iostream>
using namespace std;

string toBinary(int n, bool f)
{
    if(n == 0) return 0;
    string s = "";
    while(n > 0)
    {
        s = char('0' + (n % 2)) + s;
        n /= 2;
    }
    while(s.size()<8 && f){
        s='0'+s;
    }
    return s;
}

int main()
{
    int d, u; cin>>d; cin>>u;
    if(d>253 || u>253 || d<0 || u<0) return 0;
    cout<<toBinary(d, 1)<<","<<toBinary(u, 0)<<endl;

}

zad 8
#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int main() {
    string s1, s2;
    
    cout << "Podaj pierwsza liczbe (16 znakow 0/1): ";
    cin >> s1;
    cout << "Podaj druga liczbe (16 znakow 0/1): ";
    cin >> s2;

    int e1 = stoi(s1.substr(0, 8), nullptr, 2);
    int m1 = stoi(s1.substr(8, 8), nullptr, 2);

    int e2 = stoi(s2.substr(0, 8), nullptr, 2);
    int m2 = stoi(s2.substr(8, 8), nullptr, 2);

    if (e1 > 0) { m1 = m1 + 256; }
    if (e2 > 0) { m2 = m2 + 256; }

    while (e1 < e2) {
        m1 = m1 / 2;
        e1++;
    }
    while (e2 < e1) {
        m2 = m2 / 2;
        e2++;
    }

    int m_sum = m1 + m2;
    int e_sum = e1; 

    if (m_sum >= 512) {
        m_sum = m_sum / 2;
        e_sum++;
    }

    if (m_sum >= 256) {
        m_sum = m_sum - 256;
    }

    string wy_cecha = bitset<8>(e_sum).to_string();
    string wy_mantysa = bitset<8>(m_sum).to_string();

    cout << "Wynik dodawania: " << wy_cecha << wy_mantysa << endl;

    return 0;
}
