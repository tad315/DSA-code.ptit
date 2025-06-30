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

struct Node
{
    string val;
    Node *left, *right;
    Node(string v) : val(v), left(nullptr), right(nullptr) {}
};

Node* buildTree(vector<string> &s, int i)
{
    if (i >= s.size()) return nullptr;
    Node* root = new Node(s[i]);
    root->left = buildTree(s, 2 * i + 1);
    root->right = buildTree(s, 2 * i + 2);
    return root;
}

int calc(Node* root)
{
    if (!root->left && !root->right) return stoi(root->val);
    int l = calc(root->left);
    int r = calc(root->right);
    if (root->val == "+") return l + r;
    if (root->val == "-") return l - r;
    if (root->val == "*") return l * r;
    if (root->val == "/") return l / r;
    return 0;
}

int main()
{
    boost;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> s(n);
        for (int i = 0; i < n; ++i) cin >> s[i];
        Node* root = buildTree(s, 0);
        cout << calc(root) << endl;
    }
    return 0;
}
