#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

int main()
{
    boost;
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n; 
        int A = -1, B = -1;
        for (int b = 0; b <= n / 7; ++b)
        {
            int tmp = n - 7 * b;
            if (tmp % 4 == 0)
            {
                int a = tmp / 4;
                if (A == -1 || a + b < A + B || (a + b == A + B && a > A))
                {
                    A = a;
                    B = b;
                }
            }
        }
        if (A == -1) cout << -1 << endl;
        else 
        {
            for (int i = 0; i < A; ++i) cout << 4;
            for (int i = 0; i < B; ++i) cout << 7;
            cout << endl;
        }
    }
    return 0;
}
