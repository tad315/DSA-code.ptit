#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
#define endl '\n'
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second

const int MAX = 505;
int n, m;
char grid[MAX][MAX];
bool vis[MAX][MAX][4][3];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

struct State
{
    int x, y, dir, turns;
};

bool bfs(int sx, int sy, int tx, int ty)
{
    queue<State> q;
    for (int d = 0; d < 4; ++d)
    {
        int nx = sx + dx[d];
        int ny = sy + dy[d];
        if (nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] != '*')
        {
            q.push({nx, ny, d, 0});
            vis[nx][ny][d][0] = true;
        }
    }
    while (!q.empty())
    {
        auto [x, y, dir, turns] = q.front();
        q.pop();

        if (grid[x][y] == 'T') return true;
        for (int ndir = 0; ndir < 4; ++ndir)
        {
            int nx = x + dx[ndir];
            int ny = y + dy[ndir];
            int nturns = turns + (ndir != dir);

            if (nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] != '*' && nturns <= 2 && !vis[nx][ny][ndir][nturns])
            {
                vis[nx][ny][ndir][nturns] = true;
                q.push({nx, ny, ndir, nturns});
            }
        }
    }
    return false;
}

int main()
{
    boost;
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;

        int sx, sy, tx, ty;
        for (int i = 0; i < n; ++i)
        {
            cin >> grid[i];
            for (int j = 0; j < m; ++j)
            {
                if (grid[i][j] == 'S')
                {
                    sx = i;
                    sy = j;
                }
                else if (grid[i][j] == 'T')
                {
                    tx = i;
                    ty = j;
                }
            }
        }
        memset(vis, 0, sizeof(vis));
        if (bfs(sx, sy, tx, ty)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
