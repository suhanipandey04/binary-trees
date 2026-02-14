#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
public:
    vector<int> rightView(Node *root) {
        vector<int> result;
        if(root == NULL) return result;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            for(int i = 0; i < n; i++) {
                Node* curr = q.front();
                q.pop();
                if(i == n - 1) {
                    result.push_back(curr->data);
                }
                if(curr->left != NULL) {
                    q.push(curr->left);
                }
                if(curr->right != NULL) {
                    q.push(curr->right);
                }
            }
        }
        return result;
    }

    vector<int> leftView(Node *root) {
        vector<int> result;
        if(root == NULL) return result;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            for(int i = 0; i < n; i++) {
                Node* curr = q.front();
                q.pop();
                if(i == 0) {
                    result.push_back(curr->data);
                }
                if(curr->left != NULL) {
                    q.push(curr->left);
                }
                if(curr->right != NULL) {
                    q.push(curr->right);
                }
            }
        }
        return result;
    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);
    root->right->right = new Node(4);

    Solution sol;
    vector<int> right = sol.rightView(root);
    vector<int> left = sol.leftView(root);

    cout << "Right View: ";
    for(int val : right) cout << val << " ";
    cout << endl;

    cout << "Left View: ";
    for(int val : left) cout << val << " ";
    cout << endl;

    return 0;
}