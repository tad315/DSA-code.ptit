#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

int board[8][8];
int ans;
int colUsed[8], diag1Used[15], diag2Used[15];

void backTrack(int row, int cur)
{
    if (row == 8)
    {
        ans = max(ans, cur);
        return;
    }

    for (int col = 0; col < 8; col++)
    {
        if (!colUsed[col] && !diag1Used[row - col + 7] && !diag2Used[row + col])
        {
            colUsed[col] = diag1Used[row - col + 7] = diag2Used[row + col] = 1;
            backTrack(row + 1, cur + board[row][col]);
            colUsed[col] = diag1Used[row - col + 7] = diag2Used[row + col] = 0;
        }
    }
}

int main()
{
    fast;
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        for (int j = 0; j < 8; j++)
            for (int k = 0; k < 8; k++)
                cin >> board[j][k];
        memset(colUsed, 0, sizeof(colUsed));
        memset(diag1Used, 0, sizeof(diag1Used));
        memset(diag2Used, 0, sizeof(diag2Used));

        ans = 0;
        backTrack(0, 0);
        cout << ans << endl;
    }
}
