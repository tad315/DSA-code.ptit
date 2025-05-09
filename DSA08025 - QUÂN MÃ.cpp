#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

bool visited[8][8];
queue<pair<pair<int, int>, int>> q;

int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

pair<int, int> convert(string s)
{
    return {s[0] - 'a', s[1] - '1'};
}

int bfs(pair<int, int> start, pair<int, int> end)
{
    memset(visited, 0, sizeof(visited));
    while (!q.empty()) q.pop();
    q.push({start, 0});
    visited[start.first][start.second] = 1;

    while (!q.empty())
    {
        auto [pos, steps] = q.front();
        q.pop();
        int x = pos.first, y = pos.second;

        if (x == end.first && y == end.second) return steps;

        for (int i = 0; i < 8; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && !visited[nx][ny])
            {
                visited[nx][ny] = 1;
                q.push({{nx, ny}, steps + 1});
            }
        }
    }
    return -1;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        auto start = convert(s1);
        auto end = convert(s2);
        cout << bfs(start, end) << endl;
    }
    return 0;
}
