#include<iostream>
#include<vector>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = nullptr;
    }
};

void preorderHelper(Node* root, vector<int>& vec){
    if(root == nullptr) return ;
    vec.push_back(root->data);
    preorderHelper(root->left, vec);
    preorderHelper(root->right, vec);
}

vector<int> preOrder(Node* root){
    vector<int> vec;
    preorderHelper(root, vec);
    return vec;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(2);
    root->left->left = new Node(8);

    vector<int> result = preOrder(root);
    for(int val: result){
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
