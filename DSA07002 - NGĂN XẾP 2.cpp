#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

int main()
{
    fast;
    int q;
    cin >> q;
    cin.ignore();
    vector<int> stack;
    while (q--)
    {
        string s;
        getline(cin, s);
        
        if (s.substr(0, 4) == "PUSH")
        {
            int x = stoi(s.substr(5));
            stack.push_back(x);
        }
        else if (s == "POP")
        {
            if (!stack.empty())
                stack.pop_back();
        }
        else if (s == "PRINT")
        {
            if (stack.empty()) cout << "NONE" << endl;
            else cout << stack.back() << endl;
        }
    }
    return 0;
}
