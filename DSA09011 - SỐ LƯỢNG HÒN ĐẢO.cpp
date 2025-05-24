#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};

int t, n, m;
int a[505][505];
bool visited[505][505];

bool isVal(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(int i, int j)
{
    stack<pair<int, int>> s;
    s.push({i, j});
    visited[i][j] = 1;
    while (!s.empty())
    {
        auto[x, y] = s.top(); s.pop();
        for (int k = 0; k < 8; ++k)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (isVal(nx, ny) && !visited[nx][ny] && a[nx][ny] == 1)
            {
                visited[nx][ny] = 1;
                s.push({nx, ny});
            }
        }
    }
}

int main()
{
    boost;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                cin >> a[i][j];
                visited[i][j] = 0;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (!visited[i][j] && a[i][j] == 1)
                {
                    dfs(i, j);
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
