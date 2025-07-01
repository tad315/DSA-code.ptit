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
    int val;
    Node *left, *right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

bool check(Node* root)
{
    if (!root) return 1;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    int leaf = -1;
    while (!q.empty())
    {
        auto [node, lv] = q.front();
        q.pop();
        if (!node->left && !node->right)
        {
            if (leaf == -1) leaf = lv;
            else if (leaf != lv) return 0;
        }
        if (node->left) q.push({node->left, lv + 1});
        if (node->right) q.push({node->right, lv + 1});
    }
    return 1;
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
        unordered_map<int, Node*> nodes;
        Node* root = nullptr;
        for (int i = 0; i < n; ++i)
        {
            int u, v;
            char c;
            cin >> u >> v >> c;
            if (!nodes[u]) nodes[u] = new Node(u);
            if (!nodes[v]) nodes[v] = new Node(v);
            if (c == 'L') nodes[u]->left = nodes[v];
            else nodes[u]->right = nodes[v];
            if (i == 0) root = nodes[u];
        }
        if (check(root)) cout << 1 << endl;
        else cout << 0 << endl;
    }
    return 0;
}
