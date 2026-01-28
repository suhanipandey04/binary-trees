#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

static int idx = -1;

// Build tree from preorder traversal with -1 as NULL marker
Node* buildTree(vector<int>& preorder) {
    idx++;
    if (idx >= preorder.size() || preorder[idx] == -1) {
        return NULL;
    }
    Node* root = new Node(preorder[idx]);
    root->left = buildTree(preorder);   // left subtree
    root->right = buildTree(preorder);  // right subtree
    return root;
}

// Transform tree into its mirror
Node* mirrorTree(Node* root) {
    if (root == NULL) return NULL;

    // Recursively mirror left and right subtrees
    Node* leftMirror = mirrorTree(root->left);
    Node* rightMirror = mirrorTree(root->right);

    // Swap children
    root->left = rightMirror;
    root->right = leftMirror;

    return root;
}

// Inorder traversal to check structure
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    // Example tree:
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5
    //
    // Preorder with -1 as NULL:
    // [1,2,4,-1,-1,5,-1,-1,3,-1,-1]

    vector<int> preorder = {1,2,4,-1,-1,5,-1,-1,3,-1,-1};
    idx = -1; // reset index before building
    Node* root = buildTree(preorder);

    cout << "Inorder before mirror: ";
    inorder(root);
    cout << endl;

    root = mirrorTree(root);

    cout << "Inorder after mirror: ";
    inorder(root);
    cout << endl;

    return 0;
}