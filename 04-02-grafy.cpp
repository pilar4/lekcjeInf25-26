Ćwiczenie 1
Było na lekcji

Ćwiczenie 2
Było na lekcji

Ćwiczenie 3
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int n;
    cout<<"Podaj rozmiar: ";
    cin>>n;

    vector<int> v(n);
    srand(time(NULL));
    for(int i=0; i<n; i++)
    {
        v[i]=rand()%100;
    }

    cout<<"Wektor: "<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<v[i]<<" ";
    }

    return 0;
}


Ćwiczenie 4
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
const int N = 10;
int tab[N][N];

int main()
{
    srand(time(NULL));
    for(int i=0; i<N; i++){
        for(int j=0;j<i;j++){
            tab[i][j]=rand()%100;
        }
    }

    cout<<"elementy: "<<endl;
    for(int i=0; i<N; i++)
    {
        for(int j=0;j<i;j++){
            cout<<tab[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}


Ćwiczenie 5

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

typedef vector<vector<int> > tgraf;

void czytaj(tgraf &Graf){
    int n, m, w1, w2;
    ifstream we("graf.txt");
    we>>n>>m;
    Graf.resize(n);
    for(int i=0;i<m;i++){
        we>>w1>>w2;
        Graf[w1].push_back(w2);
    }
    we.close();
}

void DFS(int w1, tgraf &Graf, vector<bool> &Odwiedzone){
    cout<<"odw wierz: "<<w1<<endl;
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


Ćwiczenie 6

#include <iostream>
#include <fstream>

using namespace std;

typedef vector<vector<bool> > tgraf;

void Czytaj(tgraf &Graf)
{
    int n, m, w1, w2;
    ifstream we("graf.txt");
    we >> n >> m;
    Graf.resize(n);
    for (int i = 0; i < m; i++)
    {
        we >> w1 >> w2;
        Graf[w1].push_back(w2);
    }
    we.close();
}

void BFS(int w1, tgraf Graf)
{
    int w2;
    vector<bool> Odwiedzone;
    Odwiedzone.resize(Graf.size(), false);
    queue<int> wierzch;

    wierzch.push(w1);
    Odwiedzone[w1] = true;

    while (!wierzch.empty())
    {
        w1 = wierzch.front();
        wierzch.pop();

        cout << "Odwiedzony wierzcholek: " << w1 << endl;

        for (int i = 0; i < Graf[w1].size(); i++)
        {
            w2 = Graf[w1][i];
            if (!Odwiedzone[w2])
            {
                wierzch.push(w2);
                Odwiedzone[w2] = true;
            }
        }
    }
}

int main(){

    tgraf Graf;

    Czytaj(Graf);
    BFS(0, Graf);

    return 0;
}
Ćwiczenie 7
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct krawedz{
    int w2;
    int waga;
};

typedef vector<vector<krawedz> > tgraf;

void wczytaj(tgraf &Graf){
    int n,m,w1;
    krawedz kraw;
    ifstream we("graf_1.txt");
    we>>n>>m;
    Graf.resize(n);
    for(int i=0;i<m;i++){
        we>>w1>>kraw.w2>>kraw.waga;
        Graf[w1].push_back(kraw);
    }
    we.close();
}

void Djikstra(tgraf &Graf, int pocz, vector<int> &Koszt){
    krawedz kraw;
    int i, j, k, w1;
    vector<bool> Odwiedzone;
    Odwiedzone.resize(Graf.size(), false);
    Koszt[pocz]=0;
    for(i=0;i<Graf.size()-1;i++){
        k=0; while (Odwiedzone[k]) k++; w1=k;
        for(j=k+1;j<Graf.size();j++){
            if(!Odwiedzone[j] && Koszt[j]<Koszt[w1]) w1=j;
        }
        Odwiedzone[w1]=true;
        for(j = 0; j < Graf[w1].size(); j++){
            kraw = Graf[w1][j];
            if(!Odwiedzone[kraw.w2] &&
                Koszt[w1] + kraw.waga < Koszt[kraw.w2])
                Koszt[kraw.w2] = Koszt[w1] + kraw.waga;
        }

    }
}




int main()
{
    tgraf Graf;
    wczytaj(Graf);
    vector<int> Koszt;
    Koszt.resize(Graf.size(), 1000);
    int pocz;
    cout<<"Numer wierzcholka poczatkowego: ";
    cin>>pocz;
    Djikstra(Graf, pocz, Koszt);
    cout<<"Koszt dojscia z wierzcholka "<<pocz;
    cout<<"do wierzcholka:"<<endl;
    for(int i=0;i<Graf.size();i++){
        if(i!=pocz) cout<<i<<": "<<Koszt[i]<<endl;     
    }
    

    return 0;
}



Ćwiczenie 8


