#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

bool match(string &p, int num)
{
    string s = to_string(num);
    for (int i = 0; i < 2; ++i)
        if (p[i] != '?' && p[i] != s[i])
            return 0;
    return 1;
}

char ops[] = {'+', '-', '*', '/'};

int main()
{
    boost;
    int t;
    cin >> t;
    while (t--)
    {
        string a, op, b, eq, c;
        cin >> a >> op >> b >> eq >> c;
        bool f = 0;
        for (int x = 10; x <= 99; x++)
            if (match(a, x))
                for (int y = 10; y <= 99; y++)
                    if (match(b, y))
                        for (char o : ops)
                            if (op[0] == '?' || op[0] == o)
                            {
                                int z = 0;
                                if (o == '+') z = x + y;
                                else if (o == '-') z = x - y;
                                else if (o == '*') z = x * y;
                                else if (o == '/')
                                {
                                    if (y == 0 || x % y != 0) continue;
                                    z = x / y;
                                }
                                if (z < 10 || z > 99) continue;
                                if (match(c, z))
                                {
                                    cout << x << " " << o << " " << y << " = " << z << endl;
                                    f = true;
                                    goto done;
                                }
                            }
    done:
        if (!f) cout << "WRONG PROBLEM!" << endl;
    }
    return 0;
}
