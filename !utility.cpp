const int N = 5

void Losuj (int A[] [N + 1] rangle

{

for (int i = 0; i < N ;i++)

for (int j = 0; j < N ;j++) A[i][j]=1+rand()%9;

for (int i = 0 i<N;i++)

{

A[N][i] = 0 A[i][N] = emptyset

}

}

void Wypisz(int A[] [N + 1] )

{

for (int i = 0 i<N;i++)

{

for (int j = 0; j < N ;j++) cout<<A[i][j]<<" ";

cout<<endl;

}

}

int MaksSuma(int A[] [N + 1] )

{

int suma=A[0][0], w = 0 k = 0

for (int i = 1; i < 2N - 1 ;i++)

if (A[w + 1][k] > A[w][k + 1])

{

suma+=A[w+1] [k]; w++;

}

else

{

suma+=A[w] [k+1]; k++;

}

return suma;

228
