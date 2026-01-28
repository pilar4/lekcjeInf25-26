cw1
Problem Flawiusza dla 7 os co 3 wstaje :
-Wszyscy siedzą przy stole numerki od 1 do 7
-Wstaje kolega nr. 3 
-Wstaje nr.6
-Wstaje ziomek nr.2
-Opuszcza stół nr.7
-Wychodzi nr.5
-Żegna nas nr.1
-Na koniec zostaje nr.4

cw2
#include<iostream>
#include<list>
using namespace std;


int main(){
    list<int> lista;
    list<int>::iterator it;
    int n, k;
    cout<<"n "; cin>>n;
    cout<<"k "; cin>>k;
    for(int i=1;i<=n;i++){
        lista.push_back(i);
    }
    it=lista.begin();
    for(int i=1;i<n;i++){
        for(int j=1;j<k;j++){
            it++;
            if(it==lista.end()) it=lista.begin();
        }
        cout<<"krok "<<i<<": usuniety element ";
        cout<<*it<<endl;
        it=lista.erase(it);
        if(it==lista.end()) it=lista.begin();
    }
    cout<<"ostatni element: "<<*it<<" ";
    return 0;

}
cw3


cw4
#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <queue>

using namespace std;

const string alfabet="abcdefghijklmnoprstuvwxyz";
const int N = alfabet.size();


void BudujListe(list<string> &lista, int &mdl)
{
    ifstream we("slowa.txt");
    string s;
    mdl=0;
    while (we>>s)
    {
        lista.push_back(s);
        if(s.size()>mdl) mdl=s.size();
    }
    we.close();
}

void ZapiszListe(list<string> lista)
{
    ofstream wy("slowa.txt");
    list<string>::iterator it;
    for(it=lista.begin();it!=lista.end();it++)
        wy<<*it<<endl;
    wy.close();
}

void SortujSlowa(list<string> &lista, int mdl)
{
    queue<string> Kubelki[N];
    list<string>::iterator it;
    int i, j;
    string s;
    for (i=mdl-1;i>=0;i--)
    {
        it=lista.begin();
        while (it!=lista.end())
        {
            s=*it;
            if (s.size()>i)
            {
                it=lista.erase(it);
                j=alfabet.find(s[i]);
                Kubelki[j].push(s);
            }
            else it++;
        }
        for (j=0;j<N;j++)
            while (!Kubelki[j].empty())
            {
                lista.push_back(Kubelki[j].front());
                Kubelki[j].pop();
            }
    }
}

int main()
{
    list<string> lista;
    int mdl;

    BudujListe(lista, mdl);
    SortujSlowa(lista, mdl);
    ZapiszListe(lista);

    return 0;
}

