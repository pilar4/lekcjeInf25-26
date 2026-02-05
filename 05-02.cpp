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

zad 3
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

bool DFS(int w1, tgraf &Graf, vector<bool> &Odwiedzone,vector<bool> &nastosie){
   Odwiedzone[w1]=true;
   nastosie[w1]=true;

   for(int i=0;i<Graf[w1].size();i++){
    int w2=Graf[w1][i];

    if(nastosie[w2]){
        return true;
    }

    if(!Odwiedzone[w2]){
        if(DFS(w2,Graf,Odwiedzone,nastosie)){
            return true;
        }
    }
   }
   nastosie[w1]=false;
    return false;
}
int main()
{
   tgraf Graf;
   czytaj(Graf);

   vector<bool> nastosie;
   nastosie.resize(Graf.size(),false);
   vector<bool> Odwiedzone;
   Odwiedzone.resize(Graf.size(),false);

   bool cykl=false;

   int i;cin>>i;

    if(!Odwiedzone[i]){
        if(DFS(i,Graf,Odwiedzone,nastosie)){
            cout<<"jest cykl";
            return 0;
        }
    }

    cout<<"ni ma cykla";
   return 0;
}

zad 4
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

bool DFS(int w1, tgraf &Graf, vector<bool> &Odwiedzone,vector<bool> &nastosie){
   Odwiedzone[w1]=true;
   nastosie[w1]=true;

   for(int i=0;i<Graf[w1].size();i++){
    int w2=Graf[w1][i];

    if(nastosie[w2]){
        return true;
    }

    if(!Odwiedzone[w2]){
        if(DFS(w2,Graf,Odwiedzone,nastosie)){
            return true;
        }
    }
   }
   nastosie[w1]=false;
    return false;
}
int main()
{
   tgraf Graf;
   czytaj(Graf);

   vector<bool> nastosie;
   nastosie.resize(Graf.size(),false);
   vector<bool> Odwiedzone;
   Odwiedzone.resize(Graf.size(),false);

   bool cykl=false;

   for(int i=0;i<Graf.size();i++){
    if(!Odwiedzone[i]){
        if(DFS(i,Graf,Odwiedzone,nastosie)){
            cout<<"jest cykl";
            return 0;
        }
    }
}
    cout<<"ni ma cykla";
   return 0;
}

zad 5
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

    vector<bool> vec;
    for(int i=0;i<num;i++){
        vec.push_back(0);
    }


    DFS(w1, Graf, Odwiedzone);
    for(int i=0;i<num;i++){
        vec[s.top()]=1;
        s.pop();
    }
    for(int i=0;i<num;i++){
        if(vec[i]==0){
            cout<<" Nie jest spojny";
            return 0;
        }
    }
    cout<<"Jest spojny ";
    return 0;

    /*
    6 9
0 3
1 0
1 2
1 4
2 0
2 5
3 1
3 5
4 5
    */
}
zad 6
#include <iostream>
#include <vector>
#include <fstream>
#include <stack>

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

void DFS(int start, tgraf &Graf, vector<bool> &Odwiedzone){
    stack<int> s;
    s.push(start);

    while(!s.empty()){
        int w1 = s.top();
        s.pop();

        if(Odwiedzone[w1]) continue;

        cout<<w1<<endl;
        Odwiedzone[w1]=true;

        for(int i=Graf[w1].size()-1;i>=0;i--){
            int w2=Graf[w1][i];
            if(!Odwiedzone[w2]){
                s.push(w2);
            }
        }
    }
}

int main()
{
    tgraf Graf;
    czytaj(Graf);

    vector<bool> Odwiedzone;
    Odwiedzone.resize(Graf.size(),false);

    int w1 = 0;

    DFS(w1,Graf,Odwiedzone);
    return 0;
}
