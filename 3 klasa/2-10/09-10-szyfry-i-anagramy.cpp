Praca samodzielna / korzystałem z pomocy ……………………………..


Zad. 1
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void zlicz(string s, int ile[])
{
   for(int i=0;i<26;i++)
   {
       ile[i]=0;
   }
   for(int i=0;i<s.size();i++)
   {
       ile[toupper(s[i])-'A']++;
   }
}
bool anagramy(string s1, string s2, string s3)
{
   int ile1[26], ile2[26], ile3[26];
   if(s1.size()!=s2.size())
   {
       return false;
   }
   zlicz(s1,ile1);
   zlicz(s2,ile2);
   zlicz(s3,ile3);
   for(int i=0;i<26;i++)
   {
       if(ile1[i]!=ile2[i] && ile2[i]!=ile3[i])
       {
           return false;
       }
   }
   return true;
}
int main()
{
   string s1,s2,s3;
   getline(cin,s1);
   getline(cin,s2);
   getline(cin,s3);
   if(anagramy(s1,s2,s3))
   {
       cout<<"TAK"<<endl;
   } else cout<<"NIE"<<endl;
}

Zad. 2
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    getline(cin, s);

    for (int i = 0; i + 1 < s.size(); i += 2)
    {
        swap(s[i], s[i+1]);
    }

    cout << s << endl;
    return 0;
}

Zad. 3
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;


void zlicz(string s, int ile[])
{
   for(int i=0;i<26;i++)
   {
       ile[i]=0;
   }
   for(int i=0;i<s.size();i++)
   {
       ile[toupper(s[i])-'A']++;
   }
}
bool anagramy(string s1, string s2)
{
   int ile1[26], ile2[26];
   if(s1.size()!=s2.size())
   {
       return false;
   }
   zlicz(s1,ile1);
   zlicz(s2,ile2);
   for(int i=0;i<26;i++)
   {
       if(ile1[i]!=ile2[i])
       {
           return false;
       }
   }
   return true;
}
bool czyanagramy(fstream &wejscie)
{
    string pierwsze, slowo;
    if(!(wejscie>>pierwsze))
    {
        return false;
    }
    cout<<"wczytane pierwsze slowo: "<<pierwsze<<endl;  // wczytanie pierwszego slowa, aby porownac reszte
    while(wejscie>>slowo)
    {
        cout<<"wczytane slowo: "<<slowo<<endl; //sprawdzenie jakie slowa program porownuje z pierwszym slowem
        if(!anagramy(pierwsze,slowo))
        {
            return false;
        }
    }
    return true;
}
int main()
{
    fstream wejscie("dwaslowa.txt");
    if(czyanagramy(wejscie))
    {
        cout<<"TAK";
    } else cout<<"NIE";
}


Zad. 4

Zad. 5
#include <iostream>
#include <string>
#include <vector>

using namespace std;


string przestaw(string tj, vector<int> &klucz)
{
   string szyfrogram="";
   int i, j;
   while(tj.size()%klucz.size()!=0)
   {
       tj=tj+'X';
   }
   for(j=0;j<klucz.size();j++)
   {
       for(i=0;i<tj.size()/klucz.size();i++)
       {
           szyfrogram+=tj[i*klucz.size()+(klucz[j]-1)];
       }
   }
   return szyfrogram;
}



int main()
{
   

    string s;
   
    cout<<"PODAJ TEKST JAWNY: ";
    getline(cin,s);
    cout<<endl;
   
    int n;
    cout<<"PODAJ ILOSC KOLUMN: ";
    cin>>n;
    cout<<endl;

    cout<<"PODAJ KOLEJNOSC PRZEGLADANIA KOLUMN: "<<endl;
   
    vector<int> klucz(n);
    for(int i=0;i<n;i++)
    {
        cin>>klucz[i];
    }
    cout<<endl;
   
    cout<<"TEKST ZASZYFROWANY: "<<przestaw(s,klucz)<<endl;
}


Zad. 6

