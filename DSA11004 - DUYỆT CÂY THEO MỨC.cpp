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

void levelOrder(Node *root)
{
    if (!root) return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *cur = q.front();
        q.pop();
        cout << cur->val << " ";
        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
    }
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
        unordered_map<int, Node *> nodes;
        Node *root = nullptr;
        while (n--)
        {
            int u, v;
            char c;
            cin >> u >> v >> c;
            if (!nodes[u])
            {
                nodes[u] = new Node(u);
                if (!root) root = nodes[u];
            }
            nodes[v] = new Node(v);
            if (c == 'L') nodes[u]->left = nodes[v];
            else nodes[u]->right = nodes[v];
        }
        levelOrder(root);
        cout << endl;
    }
    return 0;
}
