#include <bits/stdc++.h>
using namespace std;

// Represents the single polynomial
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


// Simply Prints the List to the Screen
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


// Creates a new node and inserts it into the end
// of the head node
void insertNode(Node *head, int x, int pwr){
    Node *newNode = new Node(x, pwr, NULL);
    while(head->next != NULL){
        head = head->next;
    }
    head->next = newNode;
}


// Function to add both list.
void add(Node *first, Node *second){
    // Resultant list
    Node *result = NULL;

    // Loop to add both the list
    // until one of the list reaches to its end
    while (first && second) {
        // saves current result
        int x, pwr;

        // if power of both the polynomial is same
        // we simply add their coefficient and increment the
        // pointer to next node
        if(first->pwr == second->pwr) {
            x = first->x+second->x;
            pwr = first->pwr;
            first = first->next;
            second = second->next;
        }

        // if power of first polynomial is greater than
        // the second one then save its coefficient and power
        // into the result and increment its pointer
        else if (first->pwr > second->pwr) {
            x = first->x;
            pwr = first->pwr;
            first = first->next;
        }

        // if power of second polynomial is greater than
        // the first one. then save its coefficient and power
        // into the result and increment its pointer
        else {
            x = second->x;
            pwr = second->pwr;
            second = second->next;
        }

        // if resultant list is empty we create a new node
        // else we simply add the value at the end of our resultant list
        if(result == NULL) result = new Node(x, pwr, NULL);
        else insertNode(result, x, pwr);
   }

   // After completion of the above loop there might be a possibility
   // that one of the two polynomial lists have some unchecked data
   // below two loops are just adding the remaining data into our
   // resultant list
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


    // printing the resultant list
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