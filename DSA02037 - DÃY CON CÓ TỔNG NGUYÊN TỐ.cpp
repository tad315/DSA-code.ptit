#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

bool notPrime[1505];
int N = 1500, n, a[20];
vector<vector<int>> res;
vector<int> v;

inline void Try(int i, int sum = 0)
{
    if (!notPrime[sum])
        res.push_back(v);
    if (i > n)
        return;
    for (int j = i; j <= n; ++j)
    {
        v.push_back(a[j]);
        Try(j + 1, sum + a[j]);
        v.pop_back();
    }
}
int main()
{
    boost;
    notPrime[0] = notPrime[1] = 1;
    for (int i = 2; i * i <= N; ++i)
        if (!notPrime[i])
            for (int j = i * i; j <= N; j += i)
                notPrime[j] = 1;
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; ++i)
            cin >> a[i];
        sort(a + 1, a + n + 1, greater<int>());
        Try(1);
        vector<string> vs;
        sort(res.begin(), res.end());
        for (auto &x : res)
        {
            for (int &j : x)
                cout << j << " ";
            cout << endl;
        }
        v.clear();
        res.clear();
    }
    return 0;
}
