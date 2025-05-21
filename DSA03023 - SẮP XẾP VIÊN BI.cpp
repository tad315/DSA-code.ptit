#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

int main()
{
    boost;
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cntX = 0, cntT = 0, cntD = 0;
    for (char c : s)
    {
        if (c == 'X') ++cntX;
        else if (c == 'T') ++cntT;
        else if (c == 'D') ++cntD;
    }
    int xT = 0, xD = 0, tX = 0, tD = 0, dX = 0, dT = 0;
    for (int i = 0; i < n; ++i)
    {
        char c = s[i];
        if (i < cntX)
        {
            if (c == 'T') ++tX;
            else if (c == 'D') ++dX;
        }
        else if (i < cntX + cntT)
        {
            if (c == 'X') ++xT;
            else if (c == 'D') ++dT;
        }
        else 
        {
            if (c == 'X') ++xD;
            else if (c == 'T') ++tD;
        }
    }
    int ans = 0;
    int d1 = min(tX, xT);
    ans += d1;
    tX -= d1, xT -= d1;

    int d2 = min(dX, xD);
    ans += d2;
    dX -= d2, xD -= d2;

    int d3 = min(tD, dT);
    ans += d3;
    tD -= d3, dT -= d3;

    int r = tX + xT + dX + xD + tD + dT;
    ans += (2 * r) / 3;
    cout << ans;
    return 0;
}
