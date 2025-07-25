#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
#define endl '\n'
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second

int main()
{
    boost;
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<vector<int>> steps;

    for (int i = 0; i < n; ++i)
    {
        int tmp = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > tmp)
        {
            a[j + 1] = a[j];
            --j;
        }
        a[j + 1] = tmp;
        vector<int> cur;
        for (int k = 0; k <= i; ++k) cur.pb(a[k]);
        steps.pb(cur);
    }
    for (int i = n - 1; i >= 0; --i)
    {
        cout << "Buoc " << i << ":";
        for (int x : steps[i]) cout << " " << x;
        cout << endl;
    }
    return 0;
}
