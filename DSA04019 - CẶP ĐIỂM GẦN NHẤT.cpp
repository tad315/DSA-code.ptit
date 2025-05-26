#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

struct P
{
    ll x, y;
};

bool cmpX (P a, P b)
{
    return a.x < b .x;
}

bool cmpY (P a, P b)
{
    return a.y < b.y;
}

ld dist(P a, P b)
{
    ll dx = a.x - b.x, dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

ld solve (vector<P> &a, int l, int r)
{
    if (r - l <= 3)
    {
        ld d = 1e18;
        for (int i = l; i < r; ++i)
            for (int j = i + 1; j < r; ++j)
                d = min(d, dist(a[i], a[j]));
        sort(a.begin() + l, a.begin() + r, cmpY);
        return d;
    }
    int mid = (l + r) / 2;
    ll midX = a[mid].x;
    ld d = min(solve(a, l, mid), solve(a, mid, r));

    vector<P> b;
    merge(a.begin() + l, a.begin() + mid, a.begin() + mid, a.begin() + r, back_inserter(b), cmpY);
    copy(b.begin(), b.end(), a.begin() + l);

    vector<P> v;
    for (int i = l; i < r; ++i)
        if (abs(a[i].x - midX) < d)
            v.push_back(a[i]);
    
    for (int i = 0; i < (int)v.size(); ++i)
        for (int j = i + 1; j < (int)v.size() && (v[j].y - v[i].y) < d; ++j)
            d = min(d, dist(v[i], v[j]));   
    return d;
}

int main()
{
    boost;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<P> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i].x >> a[i].y;
        sort(a.begin(), a.end(), cmpX);
        cout << fixed << setprecision(6) << solve(a, 0, n) << endl;
    }
    return 0;
}
