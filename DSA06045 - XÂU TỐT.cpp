#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

int main()
{
    boost;
    int n;
    string s;
    cin >> n >> s;
    ll total = (1LL * n * (n - 1)) >> 1;
    int cnt = 1;
    vector<int> v;
    for (int i = 1; i < s.size(); ++i)
    {
        if (s[i] == s[i - 1])
            ++cnt;
        else
        {
            v.push_back(cnt);
            cnt = 1;
        }
    }
    v.push_back(cnt);
    for (int i = 1; i < v.size(); ++i)
        total -= (v[i] + v[i - 1] - 1);
    cout << total;
    return 0;
}
