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

int n, k;
int a[25];

void in() 
{
    for (int i = 0; i < k; ++i) cout << a[i] << " ";
    cout << endl;
}

void Try (int i, int j)
{
    if (i == k)
    {
        in();
        return;
    }
    for (int x = n - (k - i) + 1; x >= j + 1; --x)
    {
        a[i] = x;
        Try(i + 1, x);
    }
}

int main()
{
    boost;
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        Try(0, 0);
    }
    return 0;
}
