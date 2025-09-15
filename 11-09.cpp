#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void allLetters () {
    string c; char h; int licz[26];
    for(int i=0; i<26; i++) licz[i] = 0;

    ifstream wejscie("dane_zliczanie.txt");

    while(!wejscie.eof()) {
        getline(wejscie, c);
        for(int i=0; i<c.size(); i++) {
            h = toupper(c[i]);
            if (h>='A' && h<='Z') licz[h-'A']++;
        }
    }

    wejscie.close();

    for(int i=0; i<26; i++) {
        if(licz[i]) {
                cout<<char(i+'A')<<" - ";
                cout<<licz[i]<<endl;
        }
    }
}

void najwiecejLiter (string s) {

    int licz[26], naj=0; char ch;
    for(int i=0; i<26; i++) licz[i] = 0;
    // zerowanie tablicy

    for(int i=0; i<s.size(); i++) {
            ch = toupper(s[i]);
            if (ch>='A' && ch<='Z') licz[ch-'A']++;
    }
    // liczenie

    for(int i=0; i<26; i++) {
            if(licz[i] > naj)
                naj = licz[i];
        }
    // szukanie naj liczby
    
    for(int i=0; i<26; i++) {
        if(licz[i] == naj){
            cout << char(i+'A')<<" - ";
            cout << licz[i]<<endl;
        }
    }
    //wypisanie najwiekszych
    return;
}

void lamanieSzyfru () {
    string c; char h; int licz[26], naj = 0, klucz = 1000000;
    for(int i=0; i<26; i++) licz[i] = 0;

    ifstream wejscie("dane_zliczanie.txt");

    while(!wejscie.eof()) {
        getline(wejscie, c);
        for(int i=0; i<c.size(); i++) {
            h = toupper(c[i]);
            if (h>='A' && h<='Z') licz[h-'A']++;
        }
    }
    // liczenie

    wejscie.close();

    for(int i=0; i<26; i++) {
            if(licz[i] > naj) {
                naj = licz[i];
                klucz = i;
            }
        }
    // szukanie naj liczby


    while(!wejscie.eof()) {
        getline(wejscie, c);
        for(int i=0; i<c.size(); i++) {
            cout << char(c[i]+klucz);
        }
    }
}

int main() {    
    
    // //cw 2 chb
    // allLetters();

    // // cw 3 chb
    // string s; 
    // getline(cin, s);
    // najwiecejLiter(s);
    
    lamanieSzyfru();

    return 0;
}
