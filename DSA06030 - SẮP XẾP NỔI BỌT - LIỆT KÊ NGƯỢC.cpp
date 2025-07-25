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
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        vector<vector<int>> steps;
        for (int i = 0; i < n - 1; ++i)
        {
            int check = 0;
            for (int j = 0; j < n - 1; ++j)
            {
                if (a[j + 1] < a[j])
                {
                    swap(a[j], a[j + 1]);
                    check = 1;
                }
            }
            if (check) steps.pb(a);
            
        }
        for (int i = steps.size() - 1; i >= 0; --i)
        {
            cout << "Buoc " << i + 1 << ": ";
            for (int x : steps[i]) cout << x << " ";
            cout << endl;
        }
    }
    return 0;
}
