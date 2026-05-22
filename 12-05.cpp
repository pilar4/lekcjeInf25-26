cw1

#include <iostream>
#include <string>

using namespace std;

int znajdz(string w, string t)
{
   int dw=w.size();
   int dt=t.size();

   int i, p=0;
  
   while(p<=dt-dw)
   {
       i=0;
       while(i<dw && w[i]==t[p+i])
       {
           i++;
       }
       if(i==dw) return p;
       else p++;
   }
   return -1;
}

int main()
{
   string w, t;
   cout<<"wzorzec: ";cin>>w;cout<<"tekst: ";cin>>t;

   cout<<"pozycja: "<<znajdz(w,t)<<endl;
}

cw2

MURMURHASH3

cw3

a)
(7+15)mod 5 = (22)mod 5 = 2 
(7-15)mod 5 = (-8)mod 5 = -3
(7*15)mod 5 = (105)mod 5 = 0
b) 
(5+11)mod 13 = (16)mod 13 = 3
(5-11)mod 13 = (-6)mod13 = 7
(5*11)mod 13 = (55)mod13 = 3

cw4

a)
n=11
hash(bcba) = (1*3^3 + 2*3^2 + 1*3^1 + 0*3^0) mod11 = (27+18+3)mod11 = (48)mod11 = 4
b)
n=29
hash(abccbb) = (0*3^5 + 1*3^4 + 2*3^3 + 2*3^2 + 1*3^1 + 1*3^0)mod29 = (81+54+18+3+1) = (157)mod29 = 12

cw5

#include <iostream>
#include <string>

using namespace std;

const int N=997;
const int M=26;

int potega(int podst, int wykl)
{
   int w=1;
   while(wykl>0)
   {
       if(wykl%2==1)
       {
           w=(w*podst)%N;
       }
       wykl=wykl/2;
       if(wykl>0)
       {
           podst=(podst*podst)%N;
       }
   }
   return w;
}

int hash0(string s)
{
   int w=0;
   for(int i=0;i<s.size();i++)
   {
       w=((w*M)%N+s[i]-'a')%N;
   }
   return w;
}

int hash1(int h0, int jd, char ch)
{
   int w=(h0-jd)%N;
   if(w<0)
   {
       w=w+N;
   }
   return((w*M)%N+ch-'a')%N;
}

int znajdz(string w, string t)
{
   int i, p=0, dw=w.size(), dt=t.size();
   int hw=hash0(w);
   int ht=hash0(t.substr(0,dw));
   int pot=potega(M,dw-1);
  
   while(p<=dt-dw)
   {
       if(hw==ht)
       {
           i=0;
           while(i<dw && w[i]==t[p+i])
           {
               i++;
           }
           if(i==dw)
           {
               return p;
           }
       }
       if(p<dt-dw)
       {
           ht=hash1(ht,(pot*(t[p]-'a'))%N,t[p+dw]);
       }
       p++;
   }
   return -1;
}

int main()
{
   string w,t;
   cout<<"wzorzec: ";cin>>w;
   cout<<"tekst: ";cin>>t;

   cout<<znajdz(w,t)<<endl;
}
