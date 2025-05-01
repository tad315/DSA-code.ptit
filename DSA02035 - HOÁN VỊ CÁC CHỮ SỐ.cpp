#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

int main()
{
    boost;
    int n, k;
    cin >> n >> k;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) cin >> s[i];

    vector<int> a(k);
    iota(a.begin(), a.end(), 0);

    int ans = 1e9;
    do
    {
        int m = INT_MAX, M = INT_MIN;
        for (int i = 0; i < n; ++i)
        {
            string t = "";
            for (int j = 0; j < k; ++j) t += s[i][a[j]];
            int num = stoi(t);
            m = min(m, num);
            M = max(M, num);
        }
        ans = min(ans, M - m);
    } while (next_permutation(a.begin(), a.end()));
    cout << ans << endl;
    return 0;
}
