#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

int main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;
        vector<vector<int>> a(m, vector<int>(n));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                cin >> a[i][j];

        vector<vector<bool>> v(m, vector<bool>(n, false));
        vector<vector<int>> dist(m, vector<int>(n, -1));
        queue<pair<int, int>> q;

        v[0][0] = true;
        dist[0][0] = 0;
        q.push({0, 0});

        int ans = -1;
        int dx[] = {0, 1};
        int dy[] = {1, 0};

        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if (x == m - 1 && y == n - 1)
            {
                ans = dist[x][y];
                break;
            }

            int step = a[x][y];

            for (int i = 0; i < 2; i++)
            {
                int newX = x + dx[i] * step;
                int newY = y + dy[i] * step;

                if (newX >= 0 && newX < m && newY >= 0 && newY < n && !v[newX][newY])
                {
                    v[newX][newY] = true;
                    dist[newX][newY] = dist[x][y] + 1;
                    q.push({newX, newY});
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
