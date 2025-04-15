#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
#define ll long long

const int MAX_N = 105, MAX_M = 5000;
int main()
{
    ifstream inFile("DT.INP");
    ofstream outFile("DT.OUT");

    int t, n, m;
    inFile >> t >> n >> m;

    int u[MAX_M], v[MAX_M];
    int deg[MAX_N] = {0};
    int mt[MAX_N][MAX_M] = {0};

    for (int i = 0; i < m; i++)
    {
        inFile >> u[i] >> v[i];
        deg[u[i]]++;
        deg[v[i]]++;
        mt[u[i]][i] = 1;
        mt[v[i]][i] = 1;
    }

    if (t == 1)
    {
        for (int i = 1; i <= n; i++)
        {
            outFile << deg[i];
            if (i != n) outFile << " ";
        }
    }
    else if (t == 2)
    {
        outFile << n << " " << m << endl;
        for (int i = 1; i <= n; ++i) 
        {
            for (int j = 0; j < m; ++j)
            {
                outFile << mt[i][j];
                if (j != m - 1) outFile << " ";
            }
            outFile << endl;
        }
    }

    inFile.close();
    outFile.close();
    return 0;
}
