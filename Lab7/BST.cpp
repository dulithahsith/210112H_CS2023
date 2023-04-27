#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
  if (root != NULL) {
    traverseInOrder(root->left);
    cout << root->key << " ";
    traverseInOrder(root->right);
  }
}

// Making a new node
struct node* newNode(int key) {
  struct node* Node = new node;
  Node->key = key;
  Node->left = Node->right = NULL;
  return Node;
}

// Insert a node
struct node* insertNode(struct node* node, int key) {
  if (node == NULL) {
    return newNode(key);}

  if (key < node->key) {
    node->left = insertNode(node->left, key);
  } else if (key > node->key) {
    node->right = insertNode(node->right, key);
  }
  return node;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  if (root == NULL) {
    return root;
  }
  if (key < root->key) {
    root->left = deleteNode(root->left, key);
  } else if (key > root->key) {
    root->right = deleteNode(root->right, key);
  } else {
    if (root->left == NULL) {
      struct node *Node = root->right;
      delete root;
      return Node;
    } else if (root->right == NULL) {
      struct node *Node = root->left;
      delete root;
      return Node;
    }
    struct node *Node = root->right;
    while (Node->left != NULL) {
      Node = Node->left;
    }
    root->key = Node->key;
    root->right = deleteNode(root->right, Node->key);
  }
  return root;
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
  return 0;
}
