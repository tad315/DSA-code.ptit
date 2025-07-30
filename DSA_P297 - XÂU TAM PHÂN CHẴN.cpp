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

int n;
int a[15];
int cnt = 1;

void in()
{
    if (cnt % 2 == 0)
    {
        cout << cnt << ": ";
        for (int i = 1; i <= n; ++i) cout << a[i];
        cout << endl;
    }
    ++cnt;
}

void Try(int i)
{
    for (int j = 0; j <= 2; ++j)
    {
        a[i] = j;
        if (i == n) in();
        else Try(i + 1);
    }
}
int main()
{
    boost;
    cin >> n;
    Try(1);
    return 0;
}
