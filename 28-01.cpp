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
