zad 1 (kiepsko ale dziala)
#include <iostream>

using namespace std;

int main(){
    int ludz;cin>>ludz;
    int kol=0;
    int maxkol=0;
    int maxkolfinal=0;

    while(ludz!=0){
        if(ludz!=-1){
            maxkol++;
            if(maxkol>maxkolfinal){
                maxkolfinal=maxkol;
            }
        }
        else{
            maxkol=0;
        }
        if(ludz==1){
            kol++;
        }
        else{
            kol--;
        }
        cin>>ludz;
    }
    cout<<maxkolfinal;
    return 0;
}

zad 2

//NIE ZAWSZE TRASA BEDZIE NAJKROTSZA

#include <iostream>
#include <fstream>
#include <stack>
#include <string>
#include <iomanip>

using namespace std;    

const int n = 20;

struct pole
{
    int w, k;
};

void wczytajlab(int lab[][n])
{
    string s;
    ifstream we("labirynt.txt");

    for(int i=0;i<n;i++)
    {
        we>>s;
        for(int j=0;j<n;j++)
        {
            if(s[j]=='X')
            {
                lab[i][j]=-1;
            }
            else
            {
                lab[i][j]=0;
            }
        }
    }
    we.close();
}

void wypiszlab(int lab[][n])
{
    cout<<"   ";
    for(int j=0;j<n;j++)
    {
        cout<<setw(3)<<j;
    }
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<setw(3)<<i;
        for(int j=0;j<n;j++)
        {
            if(lab[i][j]==-1)
            {
                cout<<"  X";
            }
            else if(lab[i][j]==-2)
            {
                cout<<"  D";
            }
            else
            {
                cout<<"   ";
            }
        }
        cout<<endl;
    }
}

bool droga(int lab[][n], pole p1, pole &p2)
{
    int w,k;
    bool wyjscie=false;

    stack<pole> stack;
    
    stack.push(p1);
    lab[p1.w][p1.k]=1;

    while(!wyjscie && !stack.empty())
    {
        p2=stack.top();
        stack.pop();
        
        w=p2.w;
        k=p2.k;
        
        if(w == 0 || w == n-1 || k==0 || k==n-1)
        {
            wyjscie=true;
        }
        else
        {
            if(lab[w-1][k]==0)
            {
                lab[w-1][k] = lab[w][k]+1;
                p2.w=w-1;
                p2.k=k;
                stack.push(p2);
            }
            if(lab[w+1][k]==0)
            {
                lab[w+1][k]=lab[w][k]+1;
                p2.w=w+1;
                p2.k=k;
                stack.push(p2);
            }
            if(lab[w][k-1]==0)
            {
                lab[w][k-1]=lab[w][k]+1;
                p2.w=w;
                p2.k=k-1;
                stack.push(p2);
            }
            if(lab[w][k+1]==0)
            {
                lab[w][k+1]=lab[w][k]+1;
                p2.w=w;
                p2.k=k+1;
                stack.push(p2);
            }
        }
    }
    return wyjscie;
}

void oznaczdroge(int Lab[][n], int w, int k)
{
    int x = Lab[w][k];
    Lab[w][k] = -2;

    while (x > 1)
    {
        x--;

        if (w > 0 && Lab[w - 1][k] == x)
            w--;
        else if (w < n - 1 && Lab[w + 1][k] == x)
            w++;
        else if (k > 0 && Lab[w][k - 1] == x)
            k--;
        else
            k++;

        Lab[w][k] = -2;
    }
}

int main()
{
    int lab[n][n];
    pole p1, p2;

    wczytajlab(lab);
    wypiszlab(lab);

    cout<<"WSPOLRZEDNE POLA STARTOWEGO: "<<endl;
    cout<<"w = "; cin>>p1.w;
    cout<<"k = "; cin>>p1.k;

    if(droga(lab,p1,p2))
    {
        oznaczdroge(lab,p2.w,p2.k);
        wypiszlab(lab);
    }
    else
    {
        cout<<"BRAK DROGI!!!";
    }
    return 0;
    
}

zad 3
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>


using namespace std;


const int N=10;
const int M=8;


void WczytajLabirynt(int Lab[N][M]){
   string s;
   ifstream we("labirynt.txt");
   for(int i=0;i<N;i++){
       we>>s;
       for(int j=0;j<M;j++){
           if(s[j]=='X'){
               Lab[i][j]=-1;
           }
           else{
               Lab[i][j]=0;
           }
       }
   }
   we.close();
}


void WypiszLabirynt(int Lab[N][M]){
   cout<<"   ";
   for(int j=0;j<M;j++){
       cout<<setw(3)<<j;
   }
   cout<<endl;
   for(int i=0;i<N;i++){
       cout<<setw(3)<<i;
       for(int j=0;j<M;j++){
           if(Lab[i][j]==-1){
               cout<<"  X";
           }
           else if(Lab[i][j]==0){
               cout<<"   ";
           }
           else
               cout<<"  #";
       }
       cout<<endl;
   }
}

int main(){
   int Lab[N][M];
   WczytajLabirynt(Lab);
   WypiszLabirynt(Lab);

   return 0;
}
zad 4
#include <iostream>
#include <fstream>
#include <stack>
#include <string>
#include <iomanip>

using namespace std;   

const int n = 20;

struct pole
{
   int w, k;
};

void wczytajlab(int lab[][n])
{
   string s;
   ifstream we("labirynt.txt");


   for(int i=0;i<n;i++)
   {
       we>>s;
       for(int j=0;j<n;j++)
       {
           if(s[j]=='X')
           {
               lab[i][j]=-1;
           }
           else
           {
               lab[i][j]=0;
           }
       }
   }
   we.close();
}

void wypiszlab(int lab[][n])
{
   cout<<"   ";
   for(int j=0;j<n;j++)
   {
       cout<<setw(3)<<j;
   }
   cout<<endl;
   for(int i=0;i<n;i++)
   {
       cout<<setw(3)<<i;
       for(int j=0;j<n;j++)
       {
           if(lab[i][j]==-1)
           {
               cout<<"  X";
           }
           else if(lab[i][j]==-2)
           {
               cout<<"  D";
           }
           else
           {
               cout<<"   ";
           }
       }
       cout<<endl;
   }
}

bool szukaj_ze_stosem(int lab[][n], int w, int k, pole &p2, stack<pole> &stos)
{
    pole aktualne;
    aktualne.w = w;
    aktualne.k = k;

    stos.push(aktualne);

    if (w == 0 || w == n - 1 || k == 0 || k == n - 1)
    {
        p2 = aktualne;
        return true;
    }
    
    if (lab[w - 1][k] == 0)
    {
        lab[w - 1][k] = lab[w][k] + 1;
        if (szukaj_ze_stosem(lab, w - 1, k, p2, stos)) return true;
    }

    if (lab[w + 1][k] == 0)
    {
        lab[w + 1][k] = lab[w][k] + 1;
        if (szukaj_ze_stosem(lab, w + 1, k, p2, stos)) return true;
    }

    if (lab[w][k - 1] == 0)
    {
        lab[w][k - 1] = lab[w][k] + 1;
        if (szukaj_ze_stosem(lab, w, k - 1, p2, stos)) return true;
    }

    if (lab[w][k + 1] == 0)
    {
        lab[w][k + 1] = lab[w][k] + 1;
        if (szukaj_ze_stosem(lab, w, k + 1, p2, stos)) return true;
    }

    stos.pop();

    return false;
}

bool droga(int lab[][n], pole p1, pole &p2)
{
    stack<pole> stos;

    lab[p1.w][p1.k] = 1;

    bool znaleziono = szukaj_ze_stosem(lab, p1.w, p1.k, p2, stos);
    
    return znaleziono;
}

void oznaczdroge(int Lab[][n], int w, int k)
{
   int x = Lab[w][k];
   Lab[w][k] = -2;

   while (x > 1)
   {
       x--;
       if (w > 0 && Lab[w - 1][k] == x)
           w--;
       else if (w < n - 1 && Lab[w + 1][k] == x)
           w++;
       else if (k > 0 && Lab[w][k - 1] == x)
           k--;
       else
           k++;

       Lab[w][k] = -2;
   }
}

int main()
{
   int lab[n][n];
   pole p1, p2;

   wczytajlab(lab);
   wypiszlab(lab);

   cout<<"WSPOLRZEDNE POLA STARTOWEGO: "<<endl;
   cout<<"w = "; cin>>p1.w;
   cout<<"k = "; cin>>p1.k;


   if(droga(lab,p1,p2))
   {
       oznaczdroge(lab,p2.w,p2.k);
       wypiszlab(lab);
   }
   else
   {
       cout<<"BRAK DROGI!!!";
   }
   return 0; 
}

zad 5

#include <iostream>
#include <fstream>
#include <queue>
#include <iomanip>

using namespace std;

const int n = 20;

struct pole
{
    int x;          // -1 ściana, 0 wolne, >0 BFS, -2 droga
    bool D, G, L, P;
};

void wczytajlab(pole lab[][n])
{
    ifstream we("labirynt-logiczny.txt");
    char c;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            we >> lab[i][j].G >> lab[i][j].D
               >> lab[i][j].L >> lab[i][j].P;

            lab[i][j].x = 0;
        }
    }
    we.close();
}

void wypiszlab(pole lab[][n])
{
    cout << "   ";
    for (int j = 0; j < n; j++)
        cout << setw(3) << j;
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        cout << setw(3) << i;
        for (int j = 0; j < n; j++)
        {
            if (lab[i][j].x == -1)
                cout << "  X";
            else if (lab[i][j].x == -2)
                cout << "  D";
            else
                cout << "   ";
        }
        cout << endl;
    }
}

bool droga(pole lab[][n], int ws, int ks, int &wk, int &kk)
{
    queue<pair<int,int>> q;
    q.push({ws, ks});
    lab[ws][ks].x = 1;

    while (!q.empty())
    {
        int w = q.front().first;
        int k = q.front().second;
        q.pop();

        if (w == 0 || w == n-1 || k == 0 || k == n-1)
        {
            wk = w;
            kk = k;
            return true;
        }

        if (lab[w][k].G && lab[w-1][k].x == 0)
        {
            lab[w-1][k].x = lab[w][k].x + 1;
            q.push({w-1, k});
        }

        if (lab[w][k].D && lab[w+1][k].x == 0)
        {
            lab[w+1][k].x = lab[w][k].x + 1;
            q.push({w+1, k});
        }

        if (lab[w][k].L && lab[w][k-1].x == 0)
        {
            lab[w][k-1].x = lab[w][k].x + 1;
            q.push({w, k-1});
        }

        if (lab[w][k].P && lab[w][k+1].x == 0)
        {
            lab[w][k+1].x = lab[w][k].x + 1;
            q.push({w, k+1});
        }
    }
    return false;
}

void oznaczdroge(pole lab[][n], int w, int k)
{
    int x = lab[w][k].x;
    lab[w][k].x = -2;

    while (x > 1)
    {
        x--;

        if (w > 0 && lab[w-1][k].x == x) w--;
        else if (w < n-1 && lab[w+1][k].x == x) w++;
        else if (k > 0 && lab[w][k-1].x == x) k--;
        else k++;

        lab[w][k].x = -2;
    }
}

int main()
{
    pole lab[n][n];
    int ws, ks, wk, kk;

    wczytajlab(lab);
    wypiszlab(lab);

    cout << "WSPOLRZEDNE POLA STARTOWEGO:\n";
    cout << "w = "; cin >> ws;
    cout << "k = "; cin >> ks;

    if (droga(lab, ws, ks, wk, kk))
    {
        oznaczdroge(lab, wk, kk);
        wypiszlab(lab);
    }
    else
    {
        cout << "BRAK DROGI!!!";
    }

    return 0;
}
cw 7
#include <iostream>
using namespace std;

const int N = 8;
bool tab[N][N];

bool szach(int w, int k){
    // kolejno kolumny, wiersze, skosy:
    // lewo gora, prawo gora, lewo dol, prawo dol

    for(int i = 0; i < N; i++)
        if(tab[i][k] && i != w)
            return true;

    for(int j = 0; j < N; j++)
        if(tab[w][j] && j != k)
            return true;

    for(int i = w-1, j = k-1; i >= 0 && j >= 0; i--, j--)
        if(tab[i][j]) return true;
    
    for(int i = w-1, j = k+1; i >= 0 && j < N; i--, j++)
        if(tab[i][j]) return true;

    for(int i = w+1, j = k-1; i < N && j >= 0; i++, j--)
        if(tab[i][j]) return true;

    for(int i = w+1, j = k+1; i < N && j < N; i++, j++)
        if(tab[i][j]) return true;

    return false;
}

void wypisz(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << tab[i][j] << " ";
        }
        cout << endl;
    }
    cout<<endl;
}

int counter = 0;

void hetman(int w) {
    if (w == N) {
        wypisz();
        counter++;
        return;
    }

    for (int k = 0; k < N; k++) {
        if (!szach(w, k)) {
            tab[w][k] = true;
            hetman(w + 1);
            // cofanie jezeli jest szach
            tab[w][k] = false;
        }
    }
}

int main(){

    if (N==2) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                tab[i][j] = true;
                wypisz();
                tab[i][j] = false;
                counter++;
            }
        }
    } else if(N==3) {
        for (int i1 = 0; i1 < N; i1++) {
            for (int j1 = 0; j1 < N; j1++) {
                tab[i1][j1] = true;
                for (int i2 = 0; i2 < N; i2++) {
                    for (int j2 = 0; j2 < N; j2++) {
                        if (!tab[i2][j2] && !szach(i2, j2)) {
                            tab[i2][j2] = true;
                            wypisz();
                            tab[i2][j2] = false;
                            counter++;
                        }
                    }
                    
                }
                tab[i1][j1] = false;
            }
        }
        
    } else {
        hetman(0);
    }
    cout << "Znaleziono " << counter << " rozwiazan";
}
