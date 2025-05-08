#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

int minVal(string s, int k)
{
}

int main()
{
    boost;
    int t;
    cin >> t;

    while (t--)
    {
        int k;
        string s;
        cin >> k >> s;
        int fre[30] = {};
        for (char &c : s) ++fre[c - 'A'];
        priority_queue<int> pq;

        for (int i = 0; i < 26; ++i)
            if (fre[i] > 0) pq.push(fre[i]);

        while (k--)
        {
            int top = pq.top();
            pq.pop();
            --top;
            pq.push(top);
        }

        ll res = 0;
        while (!pq.empty())
        {
            int val = pq.top();
            pq.pop();
            res += 1LL * val * val;
        }
        cout << res << endl;
    }
    return 0;
}
