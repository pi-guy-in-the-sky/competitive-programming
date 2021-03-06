// Problem ID: ccc20s2.cpp
// By

#include <iostream>
#include <cmath>
#define MAXN 1005
using namespace std;

int M, N, v;
int x[MAXN][MAXN], vis[MAXN][MAXN];

bool dfs(int r, int c)
{
    if (r == M && c == N)
        return true;
    vis[r][c] = true;
    for (int k = 1; k * k <= x[r][c]; k++)
    {
        if (x[r][c] % k != 0)
            continue;
        int l = x[r][c] / k;
        if (k >= 1 && k <= M && l >= 1 && l <= N && !vis[k][l] && dfs(k, l))
            return true;
        if (l >= 1 && l <= M && k >= 1 && k <= N && !vis[l][k] && dfs(l, k))
            return true;
    }
    return false;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> M >> N;
    v = min(M, N);

    for (int i = 1; i <= M; i++)
        for (int j = 1; j <= N; j++)
            cin >> x[i][j];

    if (dfs(1, 1))
        cout << "yes\n";
    else
        cout << "no\n";

    return 0;
}
