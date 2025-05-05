#include <iostream>
using namespace std;
// Structure for a node in the threaded binary
tree struct Node {
int data;
Node* left;
Node*
right;
bool rightThread; // True if right pointer is a thread
// Constructor to initialize node
Node(int val) {
data = val;
left = right = nullptr;
rightThread = false;
}
};
// Function to insert a node into the threaded binary tree
Node* insert(Node* root, int key) {
if (!root) return new Node(key); // If tree is empty, create a new node as root
Node* parent =
nullptr;
Node* curr = root;
// Traverse the tree to find the correct position to insert
while (curr) {
parent = curr;
if (key < curr->data) {
if (!curr->left) {
curr->left = new Node(key); // Insert as left child
return root;
}
curr = curr->left;
} else {
if (curr->rightThread) { // If right pointer is a thread
Node* newNode = new Node(key);
newNode->right
=
curr->right;
newNode->rightThread
=
true; curr->right = newNode;
curr->rightThread
=
false; return root;
}
if (!curr->right) {curr->right = new Node(key); // Insert as right child
return root;
}
curr = curr->right;
}
}
return root;
}
// Function to find the leftmost node of a subtree
Node* leftmost(Node* node) {
while (node && node->left)
node = node->left;
return node;
}
// Function for in-order traversal using threading
void inorder(Node* root) {
Node* curr = leftmost(root);
while (curr) {
cout << curr->data << " "; // Print the node data
// If right pointer is a thread, follow it
if (curr->rightThread)
curr = curr->right;
else
curr = leftmost(curr->right); // Otherwise, move to leftmost of right subtree
}
cout << endl;
}
// Function to print tree structure with threading
void printTreeStructure(Node* root, string indent = "") {
if (!root) return;
// Print current node's data and whether the right pointer is a thread
cout << indent << root->data;
if (root->rightThread) {
cout << " (Thread to " << root->right->data << ")";
} else {
cout << " (Right child: " << (root->right ? to_string(root->right->data) : "NULL") << ")";
}
cout << endl;
// Recursively print left and right subtrees
if (root->left) {
cout << indent << " L-> ";
printTreeStructure(root->left, indent + " ");
}
if (root->right && !root->rightThread)
{ cout << indent << " R-> ";
printTreeStructure(root->right, indent + " ");}
}
// Main function to demonstrate the threaded binary tree
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
