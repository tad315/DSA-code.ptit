#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int bfs(pair<int, int> start, pair<int, int> end, set<pair<int, int>> &val)
{
    queue<pair<int, int>> q;
    map<pair<int, int>, int> dist;

    q.push(start);
    dist[start] = 0;

    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        if (cur == end)
            return dist[cur];

        for (int i = 0; i < 8; ++i)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            pair<int, int> next = {nx, ny};
            if (val.count(next) && !dist.count(next))
            {
                dist[next] = dist[cur] + 1;
                q.push(next);
            }
        }
    }
    return -1;
}

int main()
{
    boost;
    int T;
    cin >> T;
    while (T--)
    {
        int xA, yA, xB, yB;
        cin >> xA >> yA >> xB >> yB;
        int N;
        cin >> N;
        set<pair<int, int>> val;

        for (int i = 0; i < N; ++i)
        {
            int x, y1, y2;
            cin >> x >> y1 >> y2;
            for (int y = y1; y <= y2; ++y)
            {
                val.insert({x, y});
            }
        }

        int res = bfs({xA, yA}, {xB, yB}, val);
        cout << res << endl;
    }
    return 0;
}
