#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

bool b[1000001];
int n, p, s;
vector<int> a, cur;
vector<vector<int>> ans;
void snt()
{
    b[0] = b[1] = 1;
    for (int i = 2; i * i <= 1000000; i++)
        if (!b[i])
            for (int j = i * i; j <= 1000000; j += i)
                b[j] = 1;
}

void backTrack(int i, int sum)
{
    if (cur.size() > n || sum > s) return;
    if (cur.size() == n && sum == s)
    {
        ans.push_back(cur);
        return;
    }
    for (int j = i; j < a.size(); j++)
    {
        cur.push_back(a[j]);
        backTrack(j + 1, sum + a[j]);
        cur.pop_back();
    }

}

int main()
{
    fast;
    int t;
    cin >> t;
    snt();
    for (int i = 1; i <= t; i++)
    {
        cin >> n >> p >> s;
        ans.clear();
        a.clear();
        cur.clear();

        for (int j = p + 1; j <= s; j++)
            if (!b[j])
                a.push_back(j);
        backTrack(0, 0);
        cout << ans.size() << endl;
        for (auto x : ans)
        {
            for (int j : x) cout << j << " ";
            cout << endl;
        }
        
    }
    return 0;
}
