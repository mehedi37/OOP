// Binary Search Tree operations in C++

#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Create a node
struct node *newNode(int item) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}

// Inorder Traversal
void inorder(struct node *root) {
  if (root != NULL) {
    // Traverse left
    inorder(root->left);

    // Traverse root
    cout << root->key << " -> ";

    // Traverse right
    inorder(root->right);
  }
}

// Insert a node
struct node *insert(struct node *node, int key) {
  // Return a new node if the tree is empty
  if (node == NULL) return newNode(key);

  // Traverse to the right place and insert the node
  if (key < node->key)
    node->left = insert(node->left, key);
  else
    node->right = insert(node->right, key);

  return node;
}

// Find the inorder successor
struct node *minValueNode(struct node *node) {
  struct node *current = node;

  // Find the leftmost leaf
  while (current && current->left != NULL)
    current = current->left;

  return current;
}

// Search a node

bool found = 0;

void search(struct node *root, int key) {
    found = 0;
    if (root != NULL) {
    // Traverse left
    search(root->left, key);

    // Traverse root
    if (root->key == key) {
        cout << "Found\n";
        found = 1;
        return;
    }

    // Traverse right
    search(root->right, key);
  }
//   cout << "Not found\n";
}


// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  // Return if the tree is empty
  if (root == NULL) return root;

  // Find the node to be deleted
  if (key < root->key)
    root->left = deleteNode(root->left, key);
  else if (key > root->key)
    root->right = deleteNode(root->right, key);
  else {
    // If the node is with only one child or no child
    if (root->left == NULL) {
      struct node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      struct node *temp = root->left;
      free(root);
      return temp;
    }

    // If the node has two children
    struct node *temp = minValueNode(root->right);

    // Place the inorder successor in position of the node to be deleted
    root->key = temp->key;

    // Delete the inorder successor
    root->right = deleteNode(root->right, temp->key);
  }
  return root;
}

int main() {
    node *root = NULL;
    while (1) {
        int choose;
        cout << "\n1) Insert\n";
        cout << "2) Search\n";
        cout << "3) Delete\n";
        cout << "4) Display\n";
        cout << "5) Exit\n";
        cout << "Enter an option : \n";
        cin >> choose;

        int val;
        switch(choose) {
            case 1:
                cout << "Enter number to insert : ";
                val; cin >> val;
                root = insert(root, val);
                break;
            case 2:
                cout << "Search value : ";
                val; cin >> val;
                search(root, val);
                if (!found) cout << "Not Found\n";
                break;
            case 3:
                cout << "Delete value : ";
                val; cin >> val;
                root = deleteNode(root, val);
                break;
            case 4:
                inorder(root);
                break;
        }
        if (choose == 5) {
            cout << "Exiting Program\n";
            break;
        }
    }
    return 0;
}