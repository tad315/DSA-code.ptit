#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'


void bfs (int n)
{
    queue <pair<string, int>> q;
    vector <bool> vis (n, 0);

    q.push({"9", 9 % n});
    vis[9 % n] = 1;
    while (!q.empty())
    {
        auto [tmp, mod] = q.front();
        q.pop();
        if (mod == 0)
        {
            cout << tmp << endl;
            return;
        }

        int mod0 = (mod * 10) % n;
        if (!vis[mod0])
        {
            vis[mod0] = 1;
            q.push({tmp + "0", mod0});
        }

        int mod9 = (mod * 10 + 9) % n;
        if (!vis[mod9])
        {
            vis[mod9] = 1;
            q.push({tmp + "9", mod9});
        }

    }
}

int main()
{
    boost;
    int t, n;
    cin >> t; 
    while (t--)
    {
        cin >> n;
        bfs(n);
    }
    return 0;
}
