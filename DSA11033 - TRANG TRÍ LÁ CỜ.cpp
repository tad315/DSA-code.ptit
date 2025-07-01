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
    map<int, int> d;
    set<int> pos;
    while (n--)
    {
        int l, r;
        cin >> l >> r;
        d[l]++;
        d[r + 1]--;
        pos.insert(l);
        pos.insert(r + 1);
    }
    int q; 
    cin >> q;
    vector<int> c(q);
    for (int &x : c)
    {
        cin >> x;
        pos.insert(x);
    }
    map<int, int> cnt;
    int sum = 0;
    for (int x : pos)
    {
        sum += d[x];
        cnt[x] = sum;
    }
    for (int x : c)
    {
        auto it = cnt.upper_bound(x);
        if (it == cnt.begin()) cout << 0 << endl;
        else cout << (--it)->se << endl;
    }
    return 0;
}
