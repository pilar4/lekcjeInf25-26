cw 1

ab+cd+*

cw 2
  
  a. 
    ab*c+
  b. 
    bc+a*
  c.
    ab+cd+*
  d.
    abc*+d-

cw 3

  a. 
    ab+c*d-e*fg*+
  b.
    abc+*def+*-gh+/

cw 4

#include <iostream>
#include <stack>

using namespace std;

string ONP(string w) {

    stack<char> stos; 
    stos.push('#');
    string onp = "";

    for (int i = 0; i < w.size(); i++)
    {
        if (w[i] == '(')
        {
            stos.push('(');
            continue;
        }
        
        if (w[i] == ')')
        {
            while (stos.top() != '(')
            {
                onp = onp + stos.top();
                stos.pop();
            }
            stos.pop();
            continue;
        }
        
        if (w[i] == '+' || w[i] == '-')
        {
            while (stos.top() != '#' && stos.top() != '(')
            {
                onp = onp + stos.top();
                stos.pop();
            }
            stos.push(w[i]);
            continue;
        }
        
        if (w[i] == '*' || w[i] == '/')
        {
            if (stos.top() == '*' || stos.top() == '/')
            {
                onp = onp + stos.top();
                stos.pop();
            }
            stos.push(w[i]);
        }
        else 
        {
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


int main(){

    string w; cin>>w;
    cout<<ONP(w);

    return 0;
}

cw 5

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
                if(stos.top() == '*' || stos.top() == '/')
                {
                    onp = onp + stos.top(); stos.pop(); 
                }
                stos.push('*'); break;
            case '/':
                if(stos.top() == '*' || stos.top() == '/')
                {
                    onp = onp + stos.top(); stos.pop(); 
                }
                stos.push('/'); break;
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

cw 6

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
        }
    }
}


int main(){

    string onp; cin>>onp;
    cout<<oblicz(onp);

    return 0;
}
