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

const int MAX = 1005;
int inOrder[MAX], preOrder[MAX];
unordered_map<int, int> inIndex;

struct Node
{
    int val;
    Node *left, *right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

Node *buildTree(int inL, int inR, int &pre, int n)
{
    if (inL > inR || pre >= n) return nullptr;
    int val = preOrder[pre++];
    Node *root = new Node(val);
    int mid = inIndex[val];
    root->left = buildTree(inL, mid - 1, pre, n);
    root->right = buildTree(mid + 1, inR, pre, n);
    return root;
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
        inIndex.clear();
        for (int i = 0; i < n; ++i)
        {
            cin >> inOrder[i];
            inIndex[inOrder[i]] = i;
        }
        for (int i = 0; i < n; ++i) cin >> preOrder[i];
        int pre = 0;
        Node *root = buildTree(0, n - 1, pre, n);
        postOrder(root);
        cout << endl;
    }
    return 0;
}
