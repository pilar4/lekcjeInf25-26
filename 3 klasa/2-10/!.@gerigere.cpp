int RSA(int podst, int wykl, int n)
{
    int w = 1;

    while (wykl > 0)
    {
        if (wykl % 2 == 1)
            w = (w * podst) % n;

        wykl = wykl / 2;

        if (wykl > 0)
            podst = (podst * podst) % n;
    }

    return w;
}

int main()
{
    ifstream we("t_jawny_RSA.txt");
    ofstream wy("szyfrogram_RSA.txt");

    unsigned char ch;
    int e, n;

    cout << "Podaj klucz publiczny:" << endl;
    cout << "e = ";
    cin >> e;
    cout << "n = ";
    cin >> n;

    we >> noskipws;

    while (we >> ch)
        wy << RSA(ch, e, n) << " ";

    we.close();
    wy.close();

    cout << "Tekst zostal zaszyfrowany";

    return 0;
}