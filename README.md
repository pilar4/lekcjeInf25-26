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







int Oblicz(string onp)
{
    stack<int> stos;
    for(int i=0; i < onp.size(); i++)
        if (onp[i] >= '0' && onp[i] <= '9')
            stos.push(onp[i] - 48);
        else
        {
            int arg2 = stos.top(); stos.pop();
            int arg1 = stos.top(); stos.pop();
            switch (onp[i])
            {
                case '+':
                    stos.push(arg1 + arg2);
                    break;
                case '-':
                    stos.push(arg1 - arg2);
                    break;
                case '*':
                    stos.push(arg1 * arg2);
                    break;
                case '/':
                    stos.push(arg1 / arg2);
                    // Uwaga: w oryginale brakuje break, ale logicznie 
                    // jest to ostatni element instrukcji switch.
            }
        }
    int wart = stos.top();
    stos.pop();
    return wart;
}
