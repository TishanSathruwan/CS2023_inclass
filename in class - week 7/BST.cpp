#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// creating a new node

node* newNode(int value){
    node* node_1 = new node();
    node_1->key = value;
    node_1->left = nullptr;
    node_1->right = nullptr;
    return node_1; 
}


// Inorder traversal1
void traverseInOrder(struct node *root) {
  if ( root == NULL){
    return;
  }
  else {
    traverseInOrder(root->left);
    cout << root->key<<" ";
    traverseInOrder(root->right);
  }

}

// Postorder traversal

// Insert a node
struct node *insertNode(struct node *node, int key) {
  if (node == NULL){
    return newNode(key);
  }
  if ( key <= node->key){
    node->left = insertNode(node->left,key);
  }
  else {
    node->right = insertNode(node->right,key);
  }
  return node;
}

//find minimum value of the tree
struct node *Successor(struct node* root){
  struct node* current = root;
  while (current && current->left != NULL ){
    current = current->left;
  }
  return current;
}

 //Deleting a node
struct node *deleteNode(struct node *root, int key) {
  if (root == NULL) {
    return root;
  }
  else if ( key < root->key){
    root->left = deleteNode(root->left,key);
  }
  else if (key > root->key){
    root->right = deleteNode(root->right,key);
  }
  else{
    if (root->left == NULL && root->right == NULL){
      delete root;
      root = NULL;
    }
    else if (root->left == NULL){
      struct node *temp = root;
      root = root->right;
      delete temp;
    }
    else if (root->right == NULL){
      struct node *temp = root;
      root = root->left;
      delete temp;
    }
    else{
      struct node *temp = Successor (root->right);
      root->key = temp->key;
      root->right = deleteNode(root->right,temp->key);
    }
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
}
