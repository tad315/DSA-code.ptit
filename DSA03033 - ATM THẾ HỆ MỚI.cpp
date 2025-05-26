#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

int main()
{
    boost;
    int t;
    cin >> t;
    ll w, c;
    while (t--)
    {
        cin >> w >> c;
        if (w % 1000) cout << 0 << endl;
        else 
        {
            w /= 1000;
            ll coin = 0, sum = 1, tmp;
            while (w && c--)
            {
                tmp = w % 10;
                if (tmp == 1 || tmp == 2 || tmp == 3 || tmp == 5) ++coin;
                else if (tmp == 4 || tmp == 6)
                {
                    coin += 2;
                    sum <<= 1;
                }
                else if (tmp == 7 || tmp == 8) coin += 2;
                else if (tmp == 9)
                {
                    coin += 3;
                    sum *= 3;
                }
                w/= 10;
            }
            if (w)
            {
                coin += w / 5;
                if (w % 5 == 4) coin += 2;
                else if (w % 5) ++coin;
                if (w % 5 == 1 && w > 1 || w == 4) sum <<= 1;
                else if (w % 5 == 4 && w > 4) sum *= 3;
            }
            cout << coin << " " << sum << endl;
        }
    }
    return 0;
}
