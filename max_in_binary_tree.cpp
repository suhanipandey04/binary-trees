#include<iostream>
#include<vector>
#include<queue>
#include<climits> // for INT_MIN
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
Node* buildTree(vector<int>& preorder) {
    idx++;
    if(preorder[idx] == -1) {
        return NULL;
    }
    Node* root = new Node(preorder[idx]);
    root->left = buildTree(preorder);   // left
    root->right = buildTree(preorder);  // right
    return root;
}

void levelorder(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* curr = q.front();
        q.pop();
        if(curr == NULL) {
            if(!q.empty()) {
                cout << endl;
                q.push(NULL);
                continue;
            } else break;
        }
        cout << curr->data << " ";

        if(curr->left != NULL) q.push(curr->left);
        if(curr->right != NULL) q.push(curr->right);
    }
    cout << endl;
}

int maxtree(Node* root) {
    if(root == NULL) return INT_MIN;
    int leftMax = maxtree(root->left);
    int rightMax = maxtree(root->right);
    return max(root->data, max(leftMax, rightMax));
}

int main() {
    vector<int> tree = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = buildTree(tree);
    levelorder(root);

    cout << "Maximum value in tree: " << maxtree(root) << endl;
    return 0;
}