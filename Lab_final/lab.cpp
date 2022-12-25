// Roll - 2003037
// Lab Final on DSA

#include<bits/stdc++.h>
using namespace std;

// Set the size of the array
// For understanding BST it kept low
#define SIZE 5

class Queue {
 private:
  int items[SIZE]{0}, front, rear;

 public:
  Queue() {
    front = -1;
    rear = -1;
  }
  bool isFull() {
    if (front == 0 && rear == SIZE - 1) {
      return true;
    }
    if (front == rear + 1) {
      return true;
    }
    return false;
  }
  bool isEmpty() {
    if (front == -1)
      return true;
    else
      return false;
  }
  void enQueue(int element) {
    if (isFull()) {
      cout << "Queue is full";
    } else {
      if (front == -1) front = 0;
      rear = (rear + 1) % SIZE;
      items[rear] = element;
    }
  }

int deQueue() {
    int element;
    if (isEmpty()) {
    //   cout << "Queue is empty" << endl;
      return (0);
    } else {
      element = items[front];
      if (front == rear) {
        front = -1;
        rear = -1;
      } else {
        front = (front + 1) % SIZE;
      }
      return (element);
    }
}
  void display() {
    int i;
    if (isEmpty()) {
      cout << endl << "Empty Queue" << endl;
      return;
    } else {
    //   cout << "Front -> " << front;
      cout << endl << "Items -> ";
      for (i = front; i != rear; i = (i + 1) % SIZE)
        cout << items[i] << " ";
      cout << items[i];
    //   cout << endl << "Rear -> " << rear;
    }
  }
};


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
    cout << root->left << "<- " << root->key << " ->" << root->right << endl;

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


class arrayClass {
 private:
    int ax_mehedi[SIZE];
    stack<int> s_mehedi;
    Queue q_mehedi;
    // bst root
    node *root = NULL;
    int queueSize{1};

 public:
    void create() {
        for (int i_mehedi{0}; i_mehedi < SIZE; i_mehedi++) {
            // cin >> ax_mehedi[i_mehedi];
            ax_mehedi[i_mehedi] = i_mehedi+1;
        }
    }
    void transfer() {
        for (auto v_mehedi : ax_mehedi) {
            s_mehedi.push(v_mehedi);
        }
    }

    void transferOdd() {
        int x_mehedi{SIZE};
        while (x_mehedi--) {
            if (s_mehedi.top() & 1) {
                q_mehedi.enQueue(s_mehedi.top());
                queueSize++;
            }
            s_mehedi.pop();
        }
    }
    void bstCreate() {
        for (int i_mehedi{0}; i_mehedi < queueSize; i_mehedi++)
            root = insert(root, q_mehedi.deQueue());
    }

    void DisplayArr() {
        cout << "\nArray Display\n";
        for (auto v_mehedi : ax_mehedi) {
            cout << v_mehedi << " ";
        }
        cout << endl;
    }
    void DisplayStack() {
        cout << "\nStack Display\n";
        for (int i_mehedi{SIZE-1}; i_mehedi >= 0; i_mehedi--) {
            cout << ax_mehedi[i_mehedi] << " ";
        }
        cout << endl;
    }
    void DisplayQueue() {
        cout << "\nQueue Display\n";
        q_mehedi.display();
    }
    void DisplayBst() {
        cout << "\n\nBst Display\n";
        inorder(root);
    }

};

int main() {
    arrayClass arr;
    arr.create();
    arr.DisplayArr();
    arr.transfer();
    arr.DisplayStack();
    arr.transferOdd();
    arr.DisplayQueue();
    arr.bstCreate();
    arr.DisplayBst();
}