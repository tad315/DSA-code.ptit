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

vector<string> a, cur;
vector<vector<string>> ans;
int n, k;

bool cmp (string &a, string &b)
{
    if (a.size() != b.size()) return a.size() < b.size();
    return a < b;
}

bool cmp2 (vector<string> &a, vector<string> &b)
{
    if (a.size() != b.size()) return a.size() < b.size();
    for (int i = 0; i < a.size(); ++i)
    {
        if (a[i] != b[i]) return a[i] < b[i];
    }
    return false;
}

void Try(int i)
{
    if (cur.size() == k)
    {
        ans.push_back(cur);
        return;
    } 
    for (int j = i; j < n; ++j)
    {
        cur.push_back(a[j]);
        Try(j + 1);
        cur.pop_back();
    }
}
int main()
{
    boost;
    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    sort(all(a), cmp);
    Try(0);
    sort(all(ans), cmp2);
    for (auto &x : ans)
    {
        for (string &y : x) cout << y << " ";
        cout << endl;
    }
    return 0;
}
