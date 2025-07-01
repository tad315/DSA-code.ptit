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

Node *buildTree(vector<int> &in, vector<int> &level, int l, int r, unordered_map<int, int> &idxMap)
{
    if (l > r) return NULL;
    for (int i = 0; i < level.size(); ++i)
    {
        int idx = idxMap[level[i]];
        if (idx >= l && idx <= r)
        {
            Node *root = new Node(level[i]);
            vector<int> leftLevel, rightLevel;
            for (int j = 0; j < level.size(); ++j)
            {
                int tmp = idxMap[level[j]];
                if (tmp < idx) leftLevel.pb(level[j]);
                else if (tmp > idx) rightLevel.pb(level[j]);
            }
            root->left = buildTree(in, leftLevel, l, idx - 1, idxMap);
            root->right = buildTree(in, rightLevel, idx + 1, r, idxMap);
            return root;
        }
    }
    return NULL;
}

void postOrder(Node *root)
{
    if (!root) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->val << " ";
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
        vector<int> in(n), level(n);
        unordered_map<int, int> idxMap;
        for (int i = 0; i < n; ++i)
        {
            cin >> in[i];
            idxMap[in[i]] = i;
        }
        for (int i = 0; i < n; ++i) cin >> level[i];
        Node *root = buildTree(in, level, 0, n - 1, idxMap);
        postOrder(root);
        cout << endl;
    }
    return 0;
}
