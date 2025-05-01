#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

int cm(string &a, string &b)
{
    int c = 0, i = 0, j = 0;
    while (i < a.size() && j < b.size())
    {
        if (a[i] == b[j]) ++c, ++i, ++j;
        else if (a[i] < b[j]) ++i;
        else ++j;
    }
    return c;
}

int main()
{
    boost;
    int n;
    cin >> n;
    vector<string> s(n);
    for (auto &x : s) cin >> x;

    vector<int> p(n);
    for (int i = 0; i < n; ++i) p[i] = i;

    int ans = 1e9;
    do
    {
        int c = 0;
        for (int i = 0; i < n - 1; ++i)
            c += cm(s[p[i]], s[p[i + 1]]);
        ans = min(ans, c);
        
    } 
    while (next_permutation(p.begin(), p.end()));
    cout << ans << endl;   
    return 0;
}
