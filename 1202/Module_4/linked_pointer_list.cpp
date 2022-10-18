#include <iostream>
using namespace std;

class node {
public:
  int data;
  node *next;
  void show(node *tmp) {
    if (tmp == NULL) {
      cout << "List empty" << endl;
    }
    while (tmp != NULL) {
      cout << tmp->data << " ";
      tmp = tmp->next;
    }
  }
  void insert(node *tmp, int val, int pos_val) {
    while(tmp != NULL) {
      if (tmp->data == pos_val) {
        node *add = new node;
        add->data = val;
        add->next = tmp->next;
        tmp->next = add;
        cout << "Added\n";
        return;
      }
    }
    cout << "Not Found\n";
  }
  void del(node *tmp, int pos_val) {
    node *h = tmp;
    node *q = tmp;
    if (tmp->data == pos_val) {
      h = h->next;
    }
    while (h != NULL) {
      if (h->data == pos_val) {
        q->next = h->next;
        cout << "Deleted\n";
        return;
      }
      q = h;
      h = h->next;
    }
    cout << "Not Found\n";
  }
  void search(node *tmp, int pos_val) {
    node *h = tmp;
    // node *q = tmp;
    int cnt{1};
    while (h != NULL) {
      if (h->data == pos_val) {
        cout << "Found\nAt : " << cnt++ << " node\n";
        return;
      }
      h = h->next;
    }
    cout << "Not Found\n";
  }
};
int main() {
  node *head = NULL, *tail = NULL;
  int n, x;
  cout << "How many nodes you need?" << endl;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cout << "Enter your node " << i << " value" << endl;
    cin >> x;
    node *tmp = new node;
    tmp->data = x;
    tmp->next = NULL;
    if (head == NULL) {
      head = tmp;
    }
    if (tail == NULL) {
      tail = tmp;
    }
    else {
      tail->next = tmp;
      tail = tmp;
    }
  }
  node *temp = head;
  temp->show(temp);
  cout << "\nTest insert : ";
  int val, pos;
  cin >> val >> pos;
  temp->insert(temp, val, pos);
  temp->show(temp);
  cout << endl;
  cout << "\nDelete an element : ";
  int delt; cin >> delt;
  temp->del(temp, delt);
  temp->show(temp);
  cout << "\nSearch an element : ";
  int ss; cin >> ss;
  temp->search(temp, ss);
  temp->show(temp);
}
