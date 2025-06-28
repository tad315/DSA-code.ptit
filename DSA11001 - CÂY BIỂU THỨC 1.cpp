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

Node *buildTree(string &s)
{
    stack<Node *> st;
    for (char c : s)
    {
        if (isalnum(c))
            st.push(new Node(string(1, c)));
        else
        {
            Node* right = st.top(); st.pop();
            Node* left = st.top(); st.pop();
            Node *op = new Node(string(1, c));
            op->left = left;
            op->right = right;
            st.push(op);
        }
    }
    return st.top();
}

void inOrder(Node* root)
{
    if (!root) return;
    inOrder(root->left);
    cout << root->val;
    inOrder(root->right);
}

int main()
{
    boost;
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string s;
        getline(cin, s);
        Node *root = buildTree(s);
        inOrder(root);
        cout << endl;
    }
    return 0;
}
