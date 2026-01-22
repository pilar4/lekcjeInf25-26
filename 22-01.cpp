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
