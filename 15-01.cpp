#include 

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


zad 5
