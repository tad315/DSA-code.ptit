#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

const int MAXN = 1e4 + 5;
const int INF = 1e9;

int A[4][MAXN], dp[2][16];
vector<int> masks;

void sinhMasks() {
    masks.clear();
    for (int i = 0; i < (1 << 4); ++i)
        if ((i & (i >> 1)) == 0)
            masks.push_back(i);
}

int score(int mask, int col) {
    int sum = 0;
    for (int i = 0; i < 4; ++i)
        if (mask & (1 << i))
            sum += A[i][col];
    return sum;
}

int main() {
    fast;
    sinhMasks();

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < n; ++j)
                cin >> A[i][j];

        int cur = 0, nxt = 1;
        memset(dp, 0xcf, sizeof(dp)); 

        for (int i = 0; i < (int)masks.size(); ++i)
            dp[cur][i] = score(masks[i], 0);

        for (int col = 1; col < n; ++col) {
            swap(cur, nxt);
            for (int i = 0; i < (int)masks.size(); ++i) {
                dp[cur][i] = -INF;
                int m1 = masks[i];
                int s = score(m1, col);
                for (int j = 0; j < (int)masks.size(); ++j)
                    if ((m1 & masks[j]) == 0)
                        dp[cur][i] = max(dp[cur][i], dp[nxt][j] + s);
            }
        }

        int res = -INF;
        for (int i = 0; i < (int)masks.size(); ++i)
            res = max(res, dp[cur][i]);

        if (res == 0) {
            bool allNegative = true;
            for (int i = 0; i < 4 && allNegative; ++i)
                for (int j = 0; j < n && allNegative; ++j)
                    if (A[i][j] >= 0)
                        allNegative = false;
            cout << (allNegative ? -1 : 0) << endl;
        } else {
            cout << res << endl;
        }
    }

    return 0;
}
