#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
#define ll long long


int n, m;
vector<pair<int, int>> edges;
vector<int> degrees;
vector<vector<int>> adjList;

void task1(ofstream& outFile) {
    degrees.assign(n + 1, 0);
    for (const auto& edge : edges) {
        degrees[edge.first]++;
        degrees[edge.second]++;
    }
    for (int i = 1; i <= n; i++) {
        outFile << degrees[i] << " ";
    }
}

void task2(ofstream& outFile) {
    adjList.assign(n + 1, vector<int>());
    for (const auto& edge : edges) {
        adjList[edge.first].push_back(edge.second);
        adjList[edge.second].push_back(edge.first);
    }
    for (int i = 1; i <= n; i++) {
        sort(adjList[i].begin(), adjList[i].end());
    }
    outFile << n << endl;
    for (int i = 1; i <= n; i++) {
        outFile << adjList[i].size();
        for (int neighbor : adjList[i]) {
            outFile << " " << neighbor;
        }
        outFile << endl;
    }
}

int main() {
    ifstream inFile("DT.INP");
    ofstream outFile("DT.OUT");
    
    int t;
    inFile >> t >> n >> m;
    
    edges.resize(m);
    for (int i = 0; i < m; i++) {
        inFile >> edges[i].first >> edges[i].second;
    }
    
    if (t == 1) {
        task1(outFile);
    } else if (t == 2) {
        task2(outFile);
    }
    
    inFile.close();
    outFile.close();
    return 0;
}
