zad 1

#include <iostream>
#include <string>

using namespace std;

int main (){
    string a; cin>>a;
    int p=0;
    for(int i=0; i<a.size(); i++){
        if(a[i]=='('){
            p++;
        }
        else if(p>0){
            p--;
        }
        else{
            cout<<"NIE";
            return 0;
        }
    }
    cout<<"TAK";
    return 0;
}

zad 2

#include <iostream>
#include <stack>

using namespace std;

string ONP(string w)
{

    stack<char> stos; 
    stos.push('#');
    string onp = "";

    for (int i = 0; i < w.size(); i++)
    {
        switch (w[i])
        {
            case '(':
                stos.push('('); break;
            case ')':
                while(stos.top() != '(')
                {
                    onp = onp + stos.top(); stos.pop();
                }
                stos.pop(); break;
            case '+':
                while(stos.top() != '#' && stos.top() != '(')
                {
                    onp = onp + stos.top(); stos.pop();
                }
                stos.push('+'); break;
            case '-':
                while(stos.top() != '#' && stos.top() != '(')
                {
                    onp = onp + stos.top(); stos.pop();
                }
                stos.push('-'); break;
            case '*':
                if(stos.top() == '*' || stos.top() == '/' || stos.top() == '%')
                {
                    onp = onp + stos.top(); stos.pop(); 
                }
                stos.push('*'); break;
            case '/':
                if(stos.top() == '*' || stos.top() == '/' || stos.top() == '%')
                {
                    onp = onp + stos.top(); stos.pop(); 
                }
                stos.push('/'); break;
            case '%':
                if(stos.top() == '*' || stos.top() == '/' || stos.top() == '%')
                {
                    onp = onp + stos.top(); stos.pop(); 
                }
                stos.push('%'); break;
            default: 
                onp = onp + w[i];
        }
    }
    while (stos.top() != '#')
    {
        onp = onp + stos.top(); 
        stos.pop();
    }

    stos.pop();
    return onp;
}


int main()
{

    string w; cin>>w;
    cout<<ONP(w);

    return 0;
}

zad 3

#include <iostream>
#include <stack>

using namespace std;

int oblicz(string &onp){
    char znak = onp[onp.size()-1];
    onp.erase(onp.size()-1,1);
    if(znak>='0' && znak<='9'){
        return znak-48;
    }
    else{
        int arg2 = oblicz(onp);
        int arg1 = oblicz(onp);
        switch (znak){
            case '+':
                return arg1+arg2;
            case '-':
                return arg1-arg2;
            case '*':
                return arg1*arg2;
            case '/':
                return arg1/arg2;
            case '%':
                return arg1%arg2;
        }
    }
}


int main(){

    string onp; cin>>onp;
    cout<<oblicz(onp);

    return 0;
}

zad 4
#include <iostream>
#include <string>

using namespace std;

int main (){
    string s;cin>>s;
    stack<int> stos;
    for(int i=s.size()-1;i>-1;i--){
        stos.push(s[i]);
    }

    for(int i=0;i<s.size();i++){
        cout<<char(stos.top())<<endl;
        stos.pop();
    }
}



zad 5
#include <iostream>
#include <string>




using namespace std;




int main (){
   string a; cin>>a;
   int zwykly=0, kwadratowy=0, klamra=0;
   for(int i=0; i<a.size(); i++){
       if(a[i]=='('){
           zwykly++;
       }
       else if(zwykly>0 && a[i]==')'){
           zwykly--;
       }
       else if(a[i]=='['){
           kwadratowy++;
       }
       else if(kwadratowy>0 && a[i]==']'){
           kwadratowy--;
       }
       else if(a[i]=='{'){
           klamra++;
       }
       else if(klamra>0 && a[i]=='}'){
           klamra--;
       }
       else{
           cout<<"NIE";
           return 0;
       }


   }
   if(zwykly==0 && kwadratowy==0 && klamra==0)
       cout<<"TAK";
   else
       cout<<"NIE";
   return 0;
}



zad 6

#include <iostream>
#include <stack>

using namespace std;

string ONP(string w)
{

    stack<char> stos; 
    stos.push('#');
    string onp = "";

    for (int i = 0; i < w.size(); i++)
    {
        switch (w[i])
        {
            case '(':
                stos.push('('); break;
            case ')':
                while(stos.top() != '(')
                {
                    onp = onp + stos.top(); stos.pop();
                }
                stos.pop(); break;
            case '+':
                while(stos.top() != '#' && stos.top() != '(')
                {
                    onp = onp + stos.top(); stos.pop();
                }
                stos.push('+'); break;
            case '-':
                while(stos.top() != '#' && stos.top() != '(')
                {
                    onp = onp + stos.top(); stos.pop();
                }
                stos.push('-'); break;
            case '*':
                if(stos.top() == '*' || stos.top() == '/' || stos.top() == '^')
                {
                    onp = onp + stos.top(); stos.pop(); 
                }
                stos.push('*'); break;
            case '/':
                if(stos.top() == '*' || stos.top() == '/' || stos.top() == '^')
                {
                    onp = onp + stos.top(); stos.pop(); 
                }
                stos.push('/'); break;
            case '^':
                if(stos.top() == '*' || stos.top() == '/' || stos.top() == '^')
                {
                    onp = onp + stos.top(); stos.pop(); 
                }
                stos.push('^'); break;
            default: 
                onp = onp + w[i];
        }
    }
    while (stos.top() != '#')
    {
        onp = onp + stos.top(); 
        stos.pop();
    }

    stos.pop();
    return onp;
}


int main()
{

    string w; cin>>w;
    cout<<ONP(w);

    return 0;
}

zad7
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
    string s; cin>>s;
    int licznik=0;

    for(int i=0;i<s.size();i++){
        if(s[i]>=48 && s[i]<=57){
            licznik++;
        }
        else if(s[i]==42 or s[i]==43 or s[i]==45 or s[i]==47){
            licznik--;
        }
    }
    if(licznik==1){
        cout<<"TAK";
    }
    else{
        cout<<"NIE";
    }
    return 0;
}
