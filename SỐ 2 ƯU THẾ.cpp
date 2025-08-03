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

vector<string> p;

bool check(string &s)
{
    int cnt = 0;
    for (char c : s)
    {
        if (c == '2') ++cnt;
    }
    return cnt * 2 > s.size();
}
void pre()
{
    queue<string> q;
    q.push("1");
    q.push("2");
    while (p.size() < 1000)
    {
        string cur = q.front();
        q.pop();
        if (check(cur)) p.push_back(cur);
        q.push(cur + '0');
        q.push(cur + '1');
        q.push(cur + '2');
    }
}
int main()
{
    boost;
    int t;
    cin >> t;
    pre();
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) cout << p[i] << " ";
        cout << endl;
    }
    return 0;
}
