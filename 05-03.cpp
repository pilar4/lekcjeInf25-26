zad 1
1/3 - bi0,(01)

zad 2
1/3 dzies = 0,1 w troj


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
