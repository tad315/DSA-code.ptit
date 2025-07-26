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

const int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
const int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

bool check(int x, int y)
{
    return (x >= 0 && x < 8 && y >= 0 && y < 8);
}

int steps (string s, string t)
{
    int sx = s[0] - 'a', sy = s[1] - '1';
    int tx = t[0] - 'a', ty = t[1] - '1';

    if (sx == tx && sy == ty) return 0;

    queue<pair<int, int>> q;
    int dist[8][8] = {};
    bool vis[8][8] = {};
    q.push({sx, sy});
    vis[sx][sy] = 1;

    while (!q.empty())
    {
        auto [x, y] = q.front(); 
        q.pop();
        for (int i = 0; i < 8; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (check(nx, ny) && !vis[nx][ny])
            {
                vis[nx][ny] = 1;
                dist[nx][ny] = dist[x][y] + 1;
                if (nx == tx && ny == ty) return dist[nx][ny];
                q.push({nx, ny});
            }
        }
    }
    return -1;
}

int main()
{
    boost;
    int t;
    cin >> t;
    while (t--)
    {
        string s, t;
        cin >> s >> t;
        cout << steps(s, t) << endl;
    }
    return 0;
}
