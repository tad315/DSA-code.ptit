#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define endl '\n'
const ll MOD = 1e9 + 7;

const int MAX = 100;
int n;
int adj[MAX][MAX];
bool visited[MAX];
int disc[MAX];      
int low[MAX];       
int parent[MAX];    
bool isArticulation[MAX]; 
int timeCount;       

void dfs(int u) {
    visited[u] = true;
    disc[u] = low[u] = ++timeCount;
    int children = 0; 

    for (int v = 0; v < n; ++v) {
        if (adj[u][v]) {
            if (!visited[v]) {
                children++;
                parent[v] = u;
                dfs(v);

                low[u] = min(low[u], low[v]);

                if (parent[u] == -1 && children > 1) {
                    isArticulation[u] = true;
                }
                if (parent[u] != -1 && low[v] >= disc[u]) {
                    isArticulation[u] = true;
                }
            } else if (v != parent[u]) {
                low[u] = min(low[u], disc[v]);
            }
        }
    }
}

void findArticulationPoints() {
    timeCount = 0;
    fill(visited, visited + n, false);
    fill(parent, parent + n, -1);
    fill(isArticulation, isArticulation + n, false);

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    int count = 0;
    vector<int> articulationPoints;
    for (int i = 0; i < n; ++i) {
        if (isArticulation[i]) {
            count++;
            articulationPoints.push_back(i + 1); 
        }
    }

    ofstream outFile("TK.OUT");
    outFile << count << endl;
    if (count > 0) {
        sort(articulationPoints.begin(), articulationPoints.end());
        for (int i = 0; i < articulationPoints.size(); ++i) {
            outFile << articulationPoints[i] << " ";
        }
    }
    outFile.close();
}

int main() {
    ifstream inFile("TK.INP");
    inFile >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            inFile >> adj[i][j];
        }
    }
    inFile.close();

    findArticulationPoints();

    return 0;
}
