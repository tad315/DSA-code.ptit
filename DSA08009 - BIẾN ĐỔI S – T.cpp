#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

bool visited[20000];
queue<pair<int, int>> q;

int bfs(int S, int T)
{
    memset(visited, 0, sizeof(visited));
    while (!q.empty()) q.pop();

    q.push({S, 0});
    visited[S] = 1;

    while (!q.empty())
    {
        auto [cur, steps] = q.front(); q.pop();
        if (cur == T) return steps;

        if (cur * 2 < 20000 && !visited[cur * 2])
        {
            visited[cur * 2] = 1;
            q.push({cur * 2, steps + 1});
        }

        if (cur - 1 > 0 && !visited[cur - 1])
        {
            visited[cur - 1] = 1;
            q.push({cur - 1, steps + 1});
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
        int S, T;
        cin >> S >> T;
        cout << bfs(S, T) << endl;
    }
    return 0;
}
