int Znajdz(string w, string t)
{
    int dw = w.size();
    int dt = t.size();
    int i, p = 0;

    while (p <= dt - dw)
    {
        i = 0;
        while (i < dw && w[i] == t[p + i])
            i++;

        if (i == dw)
            return p;
        else
            p++;
    }

    return -1;
}