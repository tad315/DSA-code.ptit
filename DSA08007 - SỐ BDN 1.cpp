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
        ll n;
        cin >> n;
        queue<ll> q;
        q.push(1);
        int cnt = 0;

        while (!q.empty())
        {
            ll top = q.front();
            q.pop();

            if (top > n) continue;
            cnt++;
            q.push(top * 10);
            q.push(top * 10 + 1);
        }
        cout << cnt << endl;
    }
    return 0;
}
