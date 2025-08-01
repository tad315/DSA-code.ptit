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
    int n, m;
    cin >> n >> m;
    vector<int> a;
    for (int i = 1; i <= n; ++i)
    {
        if (i != m) a.push_back(i);
    }
    sort(all(a));
    do
    {
        for (int x : a) cout << x << " ";
        cout << m << endl;
    } while (next_permutation(all(a)));
    
    return 0;
}
