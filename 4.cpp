#include <iostream>
#include <queue>
using namespace std;

struct Node {
int data;
Node* left;
Node* right;
Node(int value) {
data = value;
left = right = nullptr;
}
};

Node* insert(Node* root, int data) {
if (root == nullptr)
return new Node(data);
if (data < root->data)
root->left = insert(root->left, data);
else
root->right = insert(root->right, data);
return root;
}

int height(Node* root) {
if (root == nullptr)
return 0;
int leftHeight = height(root->left);
int rightHeight = height(root->right);
return max(leftHeight, rightHeight) + 1;
}

int findMin(Node* root) {
if (root == nullptr) {
cout << "Tree is empty\n";
return -1;
}
while (root->left != nullptr)
root = root->left;
return root->data;
}

void mirror(Node* root) {
if (root == nullptr)
return;
swap(root->left, root->right);
mirror(root->left);
mirror(root->right);
}

bool search(Node* root, int key) {
if (root == nullptr)
return false;
if (root->data == key)
return true;
else if (key < root->data)
return search(root->left, key);
else
return search(root->right, key);
}

void inorder(Node* root) {
if (root == nullptr)
return;
inorder(root->left);
cout << root->data << " ";
inorder(root->right);
}

void deleteTree(Node* root) {
if (root == nullptr)
return;
deleteTree(root->left);
deleteTree(root->right);
delete root;
}

void printLevelOrder(Node* root) {
if (root == nullptr) {
cout << "Tree is empty\n";
return;
}
queue<Node*> q;
q.push(root);
while (!q.empty()) {
int levelSize = q.size();
while (levelSize--) {
Node* current = q.front();
q.pop();
cout << current->data << " ";
if (current->left != nullptr)
q.push(current->left);
if (current->right != nullptr)
q.push(current->right);
}
cout << endl;
}
}

int main() {
Node* root = nullptr;
int values[] = {50, 30, 70, 20, 40, 60, 80};
for (int val : values)
root = insert(root, val);
cout << "Inorder Traversal of Original BST:\n";
inorder(root);
cout << "\n\n";
cout << "Level Order Traversal:\n";
printLevelOrder(root);
cout << endl;
root = insert(root, 25);
cout << "After inserting 25 (Inorder):\n";
inorder(root);
cout << "\n\n";
int longestPath = height(root);
cout << "Number of nodes in longest path from root: " << longestPath << "\n";
int minValue = findMin(root);
cout << "Minimum value in the tree: " << minValue << "\n";
mirror(root);
cout << "Inorder Traversal of Mirrored Tree:\n";
inorder(root);
cout << "\n\n";
cout << "Level Order Traversal of Mirrored Tree:\n";
printLevelOrder(root);
cout << endl;
int searchValue = 60;
cout << "Searching for " << searchValue << ": ";
if (search(root, searchValue))
cout << "Found\n";
else
cout << "Not Found\n";
deleteTree(root);
return 0;
}

