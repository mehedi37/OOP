// Roll - 2003037
// Assignment 1201, topic 1, polynomial

#include <bits/stdc++.h>
using namespace std;

class Node {
 public:
    int x;
    int pwr;
    Node *next;

    Node(int x, int pwr, Node *next){
        this->x = x;
        this->pwr = pwr;
        this->next = next;
    }
};


void printList(Node *head){
    head =  head->next;
    Node * tmp = head;
    cout << "\n\nAnswer: ";
    while(head!=NULL){
    cout<< ((head->x > 0 && (tmp!= head))? "+ ": "") << head->x;
    if (head->pwr != 0) cout << "x" << "^" << head->pwr << " ";
    head = head->next;
  }
  cout << "\n\n";
}

void insertNode(Node *head, int x, int pwr){
    Node *newNode = new Node(x, pwr, NULL);
    while(head->next != NULL){
        head = head->next;
    }
    head->next = newNode;
}

void add(Node *first, Node *second){
    Node *result = NULL;
    while (first && second) {
        int x, pwr;
        if(first->pwr == second->pwr) {
            x = first->x+second->x;
            pwr = first->pwr;
            first = first->next;
            second = second->next;
        }
        else if (first->pwr > second->pwr) {
            x = first->x;
            pwr = first->pwr;
            first = first->next;
        }
        else {
            x = second->x;
            pwr = second->pwr;
            second = second->next;
        }
        if(result == NULL) result = new Node(x, pwr, NULL);
        else insertNode(result, x, pwr);
   }
   while(first){
        if(result == NULL) result = new Node(first->x, first->pwr, NULL);
        else insertNode(result, first->x, first->pwr);
        first = first->next;
   }

   while(second){
        if(result == NULL) result = new Node(second->x, second->pwr, NULL);
        else insertNode(result, second->x, second->pwr);
        second = second->next;
   }
   printList(result);
}

int main(){

    int part1{0}, part2{0};


    // First polynomial
    Node *polynomial1 = new Node(0, 0, NULL);       // Node(co-efficient, the power, next part location)   = 4x^2 ->(next location)
    cout << "\nHow many parts for poly 1 : ";
    cin >> part1;
    for (int i{0}; i < part1; i++) {
        cout << "Insert details of part " << i+1 << " as (x power) : ";
        int x, power;
        cin >> x >> power;
        insertNode(polynomial1, x, power);
    }


    // second polynomial
    Node *polynomial2 = new Node(0, 0, NULL);       // Node(co-efficient, the power, next part location)   = 4x^2 ->(next location)
    cout << "\nHow many parts for poly 2 : ";
    cin >> part2;

cout << "P1 : " << part1 << " part2 : " << part2 << endl;

    for (int i{0}; i < part2; i++) {
        cout << "Insert details of part " << i+1 << " as (x power) : ";
        int x, power;
        cin >> x >> power;
        insertNode(polynomial2, x, power);
    }



    // our algorithm
    add(polynomial1, polynomial2);

    return 0;
}

/*
4
13 8 7 5 32 2 54 0
4
3 12 17 5 3 3 98 0
*/