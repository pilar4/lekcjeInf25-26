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
Ćwiczenie 7
Ćwiczenie 8


