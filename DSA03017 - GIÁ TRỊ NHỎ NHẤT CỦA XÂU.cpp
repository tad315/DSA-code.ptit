#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

int main()
{
    boost;
    int t, k;
    cin >> t;
    string s;
    while (t--)
    {
        cin >> k >> s;
        unordered_map<char, int> freq; 
        for (char c : s) ++freq[c];

        priority_queue<int> pq;
        for (auto p : freq) pq.push(p.second);

        while(k-- && !pq.empty())
        {
            int top = pq.top(); pq.pop();
            if (top > 1) pq.push(top - 1);
        }
        ll ans = 0;
        while (!pq.empty())
        {
            ll x = pq.top(); pq.pop();
            ans += x * x;
        }
        cout << ans << endl;
    }
    return 0;
}
