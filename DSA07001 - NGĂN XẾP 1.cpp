#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

int main()
{
    fast;
    string s;
    vector<int> stack;
    while (getline(cin, s))
    {
        if (s.empty())
            continue;

        stringstream ss(s);
        string cmd;
        ss >> cmd;
        if (cmd == "push")
        {
            int x;
            ss >> x;
            stack.push_back(x);
        }
        else if (cmd == "pop")
        {
            if (!stack.empty())
                stack.pop_back();
        }
        else if ((cmd == "show"))
        {
            if (stack.empty())
                cout << "empty" << endl;
            else
            {
                for (int i = 0; i < stack.size(); i++)
                {
                    if (i != 0)
                        cout << " ";
                    cout << stack[i];
                }
                cout << endl;
            }
        }
    }
    return 0;
}
