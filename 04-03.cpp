Ćw.1
13/16 - bi 0,1101
2/5 - bi 0,(0110)


cwiczenie 2
0,00011(bi) = 2^-4 + 2^-5 = 1/16 + 1/32 = 3/32


cw 3
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


cw4
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
