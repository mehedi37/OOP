#include<bits/stdc++.h>
using namespace std;


class stacked {
 private:
    int a[1000]{0};
    int top{0};

 public:
    void push(int at) {
        a[top++] = at;
    }
    int pop() {
        return a[--top];
    }
    int postfix_res(const string &s) {
        int n1, n2, n3, num, i{0};
        while (s[i] != '\0') {
            if (s[i] >= '0' && s[i] <= '9') {
                num = s[i]-'0';
                push(num);
            } else {
                n1 = pop();
                n2 = pop();
                if (s[i] == '+') n3 = n1+n2;
                else if (s[i] == '-') n3 = n1-n2;
                else if (s[i] == '/') n3 = n2/n1;
                else if (s[i] == '*') n3 = n1*n2;
                push(n3);       // NOLINT
            }
            i++;
        }
        return pop();
    }


    int prec(char c) {
        if (c == '^')
            return 3;
        else if (c == '/' || c == '*')
            return 2;
        else if (c == '+' || c == '-')
            return 1;
        else
            return -1;
    }
    string infixToPostfix(string s) {
    stack<char> st;
    string result;

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        if (c >= '0' && c <= '9')
            result += c;
        else if (c == '(')
            st.push('(');
        else if (c == ')') {
            while (st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop();
        }

        // If an operator is scanned
        else {
            while (!st.empty() && prec(s[i]) <= prec(st.top())) {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    // Pop all the remaining elements from the stack
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    return result;
}
};


int main() {
    string polish;
    cout << "Enter expression : ";
    cin >> polish;
    stacked p;
    string x = p.infixToPostfix(polish);
    cout << "From infix to postfix : " << x << endl;
    cout << "Result of the postfix\n" << polish << " = " << p.postfix_res(x) << endl;
}

// 12+31+*2/        = 6
// ((1+2)*(3+1))/2