zad1
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

typedef vector<vector<int> > tgraf;

void czytaj(tgraf &Graf){
   int n, m, w1, w2;
   ifstream we("graf_2.txt");
   we>>n>>m;
   Graf.resize(n);
   for(int i=0;i<m;i++){
       we>>w1>>w2;
       Graf[w1].push_back(w2);
   }
   we.close();
}

void DFS(int w1, tgraf &Graf, vector<bool> &Odwiedzone){
   cout<<w1<<"da sie "<<endl;
   Odwiedzone[w1]=true;

   for(int i=0;i<Graf[w1].size();i++){
       int w2=Graf[w1][i];
       if(!Odwiedzone[w2]){
           DFS(w2,Graf,Odwiedzone);
       }
   }
}

int main()
{
   tgraf Graf;
   czytaj(Graf);

   vector<bool> Odwiedzone;
   Odwiedzone.resize(Graf.size(),false);

   int w1; cin>>w1;

   DFS(w1,Graf,Odwiedzone);
   return 0;
}


zad 2
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

typedef vector<vector<int> > tgraf;

int czytaj(tgraf &Graf){
    int n, m, w1, w2;
    ifstream we("graf_2.txt");
    we>>n>>m;
    Graf.resize(n);
    for(int i=0;i<m;i++){
        we>>w1>>w2;
        Graf[w1].push_back(w2);
    }
    we.close();

    return n;
}

stack<int> s;

void DFS(int w1, tgraf &Graf, vector<bool> &Odwiedzone){
    s.push(w1);
    Odwiedzone[w1]=true;

    for(int i=0;i<Graf[w1].size();i++){
        int w2=Graf[w1][i];
        if(!Odwiedzone[w2]){
            DFS(w2,Graf,Odwiedzone);
        }
    }

}

int main()
{
    tgraf Graf;
    int num = czytaj(Graf);

    vector<bool> Odwiedzone;
    Odwiedzone.resize(Graf.size(),false);

    int w1 = 0;


    DFS(w1, Graf, Odwiedzone);
    for(int i=0;i<num;i++){
        if(s.top()==num-1){
            cout<<"Istnieje droga ";
            return 0;
        }
        s.pop();
    }
    cout<<"Nie istnieje droga ";
    return 0;
}
