#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e6+7;
class Node
{
public:
    int key;
    Node *left;
    Node *right;
    int height;
};
int height(Node *key)
{
    if (key == NULL)return 0;
    return key->height;
}
Node *newNode(int key)
{
    Node *node = new Node();
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return (node);
}

Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left),height(y->right)) +1;
    x->height = max(height(x->left),height(x->right)) +1;
    return x;
}
Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left),height(x->right)) +1;
    y->height = max(height(y->left),height(y->right)) +1;
    return y;
}

int getBalanceFactor(Node *key)
{
    if (key == NULL)return 0;
    return height(key->left) -height(key->right);
}

Node *insertNode(Node *node, int key)
{
    if (node == NULL)
        return (newNode(key));
    if (key < node->key)
        node->left = insertNode(node->left, key);
    else if (key > node->key)
        node->right = insertNode(node->right, key);
    else return node;

    node->height = 1 + max(height(node->left),height(node->right));
    int balanceFactor = getBalanceFactor(node);
    if (balanceFactor > 1)
    {
        if (key < node->left->key)
        {
            return rightRotate(node);
        }
        else if (key > node->left->key)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
    }
    if (balanceFactor < -1)
    {
        if (key > node->right->key)
        {
            return leftRotate(node);
        }
        else if (key < node->right->key)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
    }
    return node;
}
int main()
{
    freopen("test.inp","r",stdin);
    freopen("test.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for(int i=1;i<=10;i++)
    {
        Node *tree=NULL;
        for(int j=1;j<=M;j++)
        {
            int value;
            cin>>value;
            tree=insertNode(tree,value);
        }
        cout<<tree->height<<endl;
    }
}
