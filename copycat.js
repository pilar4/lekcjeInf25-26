void Czytaj(tgraf &Graf)
{
    int n, m, w1, w2;
    ifstream we("graf.txt");
    we >> n >> m;
    Graf.resize(n);
    for (int i = 0; i < m; i++)
    {
        we >> w1 >> w2;
        Graf[w1].push_back(w2);
    }
    we.close();
}