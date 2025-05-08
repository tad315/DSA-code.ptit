#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

ll getMax(vector<ll> &h, int n)
{
    stack<int> s;
    ll ans = 0;
    int i = 0;
    while (i < n)
    {
        if (s.empty() || h[s.top()] <= h[i])
            s.push(i++);
        else
        {
            int tmp = s.top(); s.pop();
            ll area = h[tmp] * (s.empty() ? i : i - s.top() - 1);
            ans = max(ans, area);
        }
    }
    while (!s.empty())
    {
        int tmp = s.top(); s.pop();
        ll area = h[tmp] * (s.empty() ? i : i - s.top() - 1);
        ans = max(ans, area);
    }
    return ans;
}

int main()
{
    boost;
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<ll> h(n);
        for (int i = 0; i < n; ++i) cin >> h[i];
        cout << getMax(h, n) << endl;
    }
    return 0;
}
