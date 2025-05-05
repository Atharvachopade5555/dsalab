#include <iostream>
using namespace std;

struct Node {
int data;
Node* left;
Node* right;
bool rightThread;
Node(int val) {
data = val;
left = right = nullptr;
rightThread = false;
}
};

Node* insert(Node* root, int key) {
if (!root) return new Node(key);
Node* parent = nullptr;
Node* curr = root;
while (curr) {
parent = curr;
if (key < curr->data) {
if (!curr->left) {
curr->left = new Node(key);
return root;
}
curr = curr->left;
} else {
if (curr->rightThread) {
Node* newNode = new Node(key);
newNode->right = curr->right;
newNode->rightThread = true;
curr->right = newNode;
curr->rightThread = false;
return root;
}
if (!curr->right) {
curr->right = new Node(key);
return root;
}
curr = curr->right;
}
}
return root;
}

Node* leftmost(Node* node) {
while (node && node->left)
node = node->left;
return node;
}

void inorder(Node* root) {
Node* curr = leftmost(root);
while (curr) {
cout << curr->data << " ";
if (curr->rightThread)
curr = curr->right;
else
curr = leftmost(curr->right);
}
cout << endl;
}

void printTreeStructure(Node* root, string indent = "") {
if (!root) return;
cout << indent << root->data;
if (root->rightThread) {
cout << " (Thread to " << root->right->data << ")";
} else {
cout << " (Right child: " << (root->right ? to_string(root->right->data) : "NULL") << ")";
}
cout << endl;
if (root->left) {
cout << indent << " L-> ";
printTreeStructure(root->left, indent + " ");
}
if (root->right && !root->rightThread) {
cout << indent << " R-> ";
printTreeStructure(root->right, indent + " ");
}
}

int main() {
Node* root = nullptr;
root = insert(root, 20);
root = insert(root, 10);
root = insert(root, 30);
root = insert(root, 5);
root = insert(root, 15);
root = insert(root, 25);
root = insert(root, 35);
cout << "Tree Structure: " << endl;
printTreeStructure(root);
cout << "\nInorder Traversal: ";
inorder(root);
return 0;
}
z
