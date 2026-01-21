cw.1
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

const int N=10;

void WczytajLabirynt(int Lab[][N]){
    string s;
    ifstream we("labirynt.txt");
    for(int i=0;i<N;i++){
        we>>s;
        for(int j=0;j<N;j++){
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

void WypiszLabirynt(int Lab[][N]){
    cout<<"    ";
    for(int j=0;j<N;j++){
        cout<<setw(3)<<j;
    }
    cout<<endl;
    for(int i=0;i<N;i++){
        cout<<setw(3)<<i;
        for(int j=0;j<N;j++){
            if(Lab[i][j]==-1){
                cout<<"  X";
            }
            else{
                cout<<"   ";
            }
        }
        cout<<endl;
    }
}

int main(){
    int Lab[N][N];

    WczytajLabirynt(Lab);
    WypiszLabirynt(Lab);

    return 0;
}
