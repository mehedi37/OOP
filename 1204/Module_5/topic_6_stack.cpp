#include<bits/stdc++.h>
using namespace std;

int main() {
    stack<int> st;
    st.push(5);
    st.push(6);
    cout << st.top() << endl;
    st.pop();
    cout << st.empty() << endl;
    cout << st.top() << endl;
    st.pop();
    cout << st.empty() << endl;
}