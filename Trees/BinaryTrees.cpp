#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildTree(node *root)
{
    cout << "Enter the data: ";
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter the left child data of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter the right child data: " << data << endl;
    root->right = buildTree(root->right);
    return root;
}

void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            // purana level complete traverse ho chuka hai
            cout << endl;
            if (!q.empty())
            {
                // queue still has some child ndoes
                q.push(NULL);
            }
        }

        else
        {
            cout << temp->data << " ";

            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void inOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void preOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

void buildFromLevelOrder(node *&root)
{
    queue<node *> q;
    cout << "Enter data: ";
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        cout << "Enter left node for " << temp->data << " : " << endl;
        int leftData;
        cin >> leftData;

        if (leftData != -1)
        {
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        cout << "Enter right node for " << temp->data << " : " << endl;
        int rightData;
        cin >> rightData;

        if (rightData != -1)
        {
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}

int main()
{
    // Tree: 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    node *root = NULL;

    // creating tree
    // root = buildTree(root);

    // // level order
    // cout << "Printing the level order treversal output" << endl;
    // levelOrderTraversal(root);

    // cout << endl;

    // cout << "In Order traversal is: ";
    // inOrder(root);

    // cout << endl;

    // cout << "Pre Order traversal is: ";
    // preOrder(root);

    // cout << endl;

    // cout << "Post Order traversal is: ";
    // postOrder(root);

    buildFromLevelOrder(root);
    levelOrderTraversal(root);
    return 0;
}