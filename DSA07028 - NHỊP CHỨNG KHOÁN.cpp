#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

void calc (vector<int> &a, int n)
{
    vector<int> res(n);
    stack<int> s;
    s.push(0);
    res[0] = 1;
    for (int i = 1; i < n; ++i)
    {
        while (!s.empty() && a[s.top()] <= a[i])
            s.pop();
        res[i] = (s.empty() ? i + 1 : i - s.top());
        s.push(i);
    }

    for (int i = 0; i < n; ++i)
        cout << res[i] << " ";
    cout << endl;
}

int main()
{
    boost;
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        calc(a, n);
    }
    return 0;
}
