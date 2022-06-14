#include <iostream>

using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;
    Node* InsertNode(Node* root, int data);
    void PreOrder(Node* root);
    void InOrder(Node* root);
    void PostOrder(Node* root);
	Node(int x) {
		data = x;
		left = nullptr;
		right = nullptr;
	}
};

Node* Node::InsertNode(Node* root, int data) {
    if (root == nullptr) {
        return new Node(data);
    }
    else {
        Node* cur;
        if (data <= root->data) {
            cur = InsertNode(root->left, data);
            root->left = cur;
        }
        else {
            cur = InsertNode(root->right, data);
            root->right = cur;
        }
        return root;
    }
}

void Node::InOrder(Node* root) {
    if (root == NULL) return;
    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}

void Node::PreOrder(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}

void Node::PostOrder(Node* root) {
    if (root == NULL) return;
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << " ";
}

int main() {
    Node Tree(0);
    Node* root = nullptr;

    root = Tree.InsertNode(root, 6);
    root = Tree.InsertNode(root, 2);
    root = Tree.InsertNode(root, 8);
    root = Tree.InsertNode(root, 1);
    root = Tree.InsertNode(root, 4);
    root = Tree.InsertNode(root, 7);
    root = Tree.InsertNode(root, 9);
    root = Tree.InsertNode(root, 3);
    root = Tree.InsertNode(root, 5);

    Tree.InOrder(root);
    cout << endl;
    Tree.PreOrder(root);
    cout << endl;
    Tree.PostOrder(root);
    cout << endl;
   

    return 0;
}