#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
const int MOD = 1e9 + 7;
const int MAX = 200;

int C[MAX + 1][MAX + 1];

void prepare() {
    for(int i = 0; i <= MAX; ++i) {
        C[i][0] = C[i][i] = 1;
        for(int j = 1; j < i; ++j)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
    }
}

int main() {
    boost;
    prepare();

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << C[n + 9][9] << '\n';
    }
    return 0;
}
