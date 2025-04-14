#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
#define ll long long

int n, m;
vector<pair<int, int>> edges;
vector<vector<int>> adjMatrix;
vector<int> degree;

void task1(ofstream &outFile)
{
    degree.assign(n + 1, 0);

    for (auto edge : edges)
    {
        int u = edge.first;
        int v = edge.second;
        degree[u]++;
        degree[v]++;
    }

    for (int i = 1; i <= n; ++i)
        outFile << degree[i] << " ";

}

void task2(ofstream &outFile)
{
    adjMatrix.assign(n + 1, vector<int>(n + 1, 0));

    for (auto edge : edges)
    {
        int u = edge.first;
        int v = edge.second;
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    outFile << n << endl;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            outFile << adjMatrix[i][j] << " ";
        outFile << endl;
    }
}

int main()
{
    ifstream inFile("DT.INP");
    ofstream outFile("DT.OUT");

    int t;
    inFile >> t >> n >> m;

    edges.resize(m);
    for (int i = 0; i < m; ++i)
        inFile >> edges[i].first >> edges[i].second;

    if (t == 1) task1(outFile);
    else if (t == 2) task2(outFile);

    inFile.close();
    outFile.close();
    return 0;
}
