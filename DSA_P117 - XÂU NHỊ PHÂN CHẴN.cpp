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
int a[16];

void Try(int i)
{
    for (int j = 0; j <= 1; ++j)
    {
        a[i] = j;
        if (i == n - 1)
        {
            int cnt = 0;
            for (int k = 0; k < n; ++k) cnt += a[k];
            if (cnt % 2 == 0)
            {
                for (int k = 0; k < n; ++k)
                {
                    cout << a[k];
                    if (k < n - 1) cout << " ";
                    else cout << endl;
                }
            }
        }
        else Try(i + 1);
    }
}

int main()
{
    boost;
    cin >> n;
    Try(0);
    return 0;
}
