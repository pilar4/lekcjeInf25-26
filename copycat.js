void BFS(int w1, tgraf Graf)
{
    int w2;
    vector<bool> Odwiedzone;
    Odwiedzone.resize(Graf.size(), false);
    queue<int> wierzch;

    wierzch.push(w1);
    Odwiedzone[w1] = true;

    while (!wierzch.empty())
    {
        w1 = wierzch.front();
        wierzch.pop();

        cout << "Odwiedzony wierzcholek: " << w1 << endl;

        for (int i = 0; i < Graf[w1].size(); i++)
        {
            w2 = Graf[w1][i];
            if (!Odwiedzone[w2])
            {
                wierzch.push(w2);
                Odwiedzone[w2] = true;
            }
        }
    }
}