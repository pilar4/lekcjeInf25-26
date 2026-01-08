Archiwizacja
wszystkich
kodow
z
informatyki 
2
0
2
5
/
2
0
2
6


disclaimer: I, nor any contributor take responsibility for abominations you can find here 


brakuje nam 1, 3, 5, 10, 12, 13, 14, 15, 16, 17, 19, 22, 24, 26, 29, 31


string ONP(string w)
{
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
