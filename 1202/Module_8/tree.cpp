#include<bits/stdc++.h>
#include<fstream>
using namespace std;
struct Node {
    Node *leftNode;
    int data;
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
    while (file >> leftNode[i]) {
        file>>data[i];
        file>>rightNode[i];
        i++;
    }
    n=i-1;
    for(i=1;i<=n;i++)
        cout<<leftNode[i]<<" "<<char(data[i])<<" "<<rightNode[i]<<endl;

    for(i=1;i<=n;i++)
        LList[i]=new Node();

    for(i=1;i<=n;i++)
        cout<<"Node "<<char(i+64)<<" "<<LList[i]<<endl;

    LList[0]=0;
    h=LList[1];
    for(i=1;i<=n;i++){
        LList[i]->data=data[i];
        LList[i]->leftNode=LList[leftNode[i]];
        LList[i]->rightNode=LList[rightNode[i]];
    }
    cout<<endl<<"The Tree is"<<endl;
    for (i=1;i<=n;i++) {
        // cout<<LList[i] ->leftNode<<" "<<char(LList[i]->data)<<" "<<LList[i]->rightNode<<endl;
        cout<<(LList[i] ->leftNode == NULL ? 0 : LList[i] ->leftNode->data)<<"<-"<<LList[i]->data<<"->"<<(LList[i]->rightNode == NULL ? 0 : LList[i]->rightNode->data)<<endl;
    }

}