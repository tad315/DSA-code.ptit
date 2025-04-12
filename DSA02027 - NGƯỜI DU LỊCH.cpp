#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

int n;
vector<vector<int>> c;
vector<bool> visited;
int ans = INT_MAX;

void backTrack(int pos, int cnt, int cost)
{
    if (cost >= ans) return;
    if (cnt == n)
    {
        ans = min(ans, cost + c[pos][0]);
        return;
    }

    for (int next = 0; next < n; next++)
    {
        if (!visited[next] && c[pos][next] > 0)
        {
            visited[next] = true;
            backTrack(next, cnt + 1, cost + c[pos][next]);
            visited[next] = false;
        }
    }
}

int main()
{
    fast;
    cin >> n;
    
    c.resize(n, vector<int>(n));
    visited.resize(n, false);
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> c[i][j];
    
    visited[0] = true;
    backTrack(0, 1, 0);
    
    cout << ans;
    return 0;
}
