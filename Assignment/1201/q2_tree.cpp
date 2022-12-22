#include<bits/stdc++.h>
#include<fstream>
using namespace std;
struct Node {
    Node *leftNode;
    int data{0};
    Node *rightNode;
};

Node *LList[50];
Node *h, *p;

int main() {
    ifstream file;
    int leftNode[50];
    int data[50];
    int rightNode[50];
    file.open("array.txt");
    int i=1, n;

    // Getting input from "text" file
    while (file >> leftNode[i]) {
        file>>data[i];
        file>>rightNode[i];
        i++;
    }
    n=i-1;
// Tree node create kora holo
    for(i=1;i<=n;i++)
        LList[i]=new Node();

//  Head er parent null করে নিলাম
    LList[0]=0;
    h=LList[1];
    for(i=1;i<=n;i++){
        LList[i]->data=data[i];
        LList[i]->leftNode=LList[leftNode[i]];
        LList[i]->rightNode=LList[rightNode[i]];
    }

    // বামে আর ডানে কোনো নোড এড্ড্রেস না থাকলে ওটাই লিফ নোড, এই নোড এর value গুলোরই sum বের করতে হবে
    int sum{0};
    for (i=1; i <= n; i++) {
        if (LList[i]->leftNode == NULL && LList[i]->rightNode == NULL) {
            sum += LList[i]->data;
        }
    }
    cout<<endl<<"The Tree is"<<endl;
    for (i=1;i<=n;i++) {
        cout<<(LList[i] ->leftNode == NULL ? 0 : LList[i] ->leftNode->data)<<"<-"<<LList[i]->data<<"->"<<(LList[i]->rightNode == NULL ? 0 : LList[i]->rightNode->data)<<endl;
    }
    cout << "\n\nLeaf Node sum is : " << sum << endl;
}