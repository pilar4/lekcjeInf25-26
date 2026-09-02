#include <iostream>
#include <fstream>
using namespace std;
int arr[26];
int arrDictionary[26];
string z = "zliczanie.txt";
string dic = "src.txt";

void zliczLitery(int array[], string file){
    ifstream input(file);
    string napis;
    char ch;
    while(!input.eof()){
        getline(input,napis);
        for(int i=0;i<napis.size();i++){
            ch=toupper(napis[i]);
            if(ch>='A' &&ch<='Z'){
                array[ch-'A']++;
            }
        }
    }
    for(int i=0;i<26;i++){
        char c='A' + i;
        // cout<<"DDDD";
        if(array[i]>1) cout<<array[i]<<" -"<<c<<"\n";
    }
    input.close();
    return;
}

void deszyfr(void){
    zliczLitery(arr, z);
    cout<<endl;
    zliczLitery(arrDictionary, dic);

    int maxA=0, chA;
    int maxD=0, chD;
    // for(auto& obj : arr){
    //     if(maxA<obj) maxA=obj;
    // }
    // for(auto& obj : arrDictionary){
    //     if(maxD<obj) maxD=obj;
    // }

    for(int i=0;i<26;i++){
        if(arr[i]>maxA){
            maxA = arr[i];
            chA = i-1;
        }
        if(arrDictionary[i]>maxD){
            maxD = arrDictionary[i];
            chD = i-1;
        }
    }
    
    int obroc = chD-chA;

    ifstream input("zliczanie.txt");
    char ch;
    string napis;

    while(!input.eof()){
        getline(input,napis);
        for(int i=0;i<napis.size();i++){
           ch=toupper(napis[i]);
        }
        for(size_t i=0;i<napis.size();i++){
            napis[i] = toupper(napis[i]);
            if(napis[i]<65 || napis[i]>90){
                cout<<char(napis[i]);
            } else {
                cout<<char(napis[i]-obroc);
            }
        }
    
    

    

    }
    cout<<endl<<endl<<maxA<<" "<<maxD<<endl;
    cout<<chA<<" "<<chD<<endl;
    
}

int main(){
    deszyfr();
    
}
