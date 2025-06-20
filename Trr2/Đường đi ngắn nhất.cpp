#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;
const int INF = 1e9;

int n, s, t;
int c[MAXN][MAXN]; 
int d[MAXN];       
bool visited[MAXN];
int trace[MAXN];   

void dijkstra(int s) {
    for (int i = 1; i <= n; i++) {
        d[i] = INF;
        visited[i] = false;
        trace[i] = -1;
    }

    d[s] = 0;

    for (int i = 1; i <= n; i++) {
        int u = -1;
        int min_d = INF;

        for (int j = 1; j <= n; j++) {
            if (!visited[j] && d[j] < min_d) {
                min_d = d[j];
                u = j;
            }
        }

        if (u == -1) break;
        visited[u] = true;

        for (int v = 1; v <= n; v++) {
            if (!visited[v] && c[u][v] < 10000 && d[v] > d[u] + c[u][v]) {
                d[v] = d[u] + c[u][v];
                trace[v] = u;
            }
        }
    }
}

vector<int> getPath(int t) {
    vector<int> path;
    while (t != -1) {
        path.push_back(t);
        t = trace[t];
    }
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    freopen("DN.INP", "r", stdin);
    freopen("DN.OUT", "w", stdout);

    cin >> n >> s >> t;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> c[i][j];

    dijkstra(s);

    if (d[t] == INF) {
        cout << 0 << endl;
    } else {
        cout << d[t] << endl;
        vector<int> path = getPath(t);
        for (int v : path) {
            cout << v << " ";
        }
        cout << endl;
    }

    return 0;
}
