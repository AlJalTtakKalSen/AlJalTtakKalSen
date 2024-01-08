#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to return precedence of operators
int precedence(char c) {
    if(c == '*' || c == '/') return 2;
    else if(c == '+' || c == '-') return 1;
    else return -1;
}

// Function to convert infix expression to postfix
string infixToPostfix(string s) {
    stack<char> st; 
    string result;

    for(int i = 0; i < s.length(); i++) {
        char c = s[i];

        // If the character is an operand, add it to the output
        if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
            result += c;

        // If the character is an '(', push it to the stack
        else if(c == '(')
            st.push('(');

        // If the character is an ')', pop and output from the stack 
        // until an '(' is encountered
        else if(c == ')') {
            while(st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop(); // Pop the '('
        }

        // If the character is an operator
        else {
            while(!st.empty() && precedence(s[i]) <= precedence(st.top())) {
                result += st.top();
                st.pop(); 
            }
            st.push(c);
        }
    }

    // Pop all the remaining elements from the stack
    while(!st.empty()) {
        result += st.top();
        st.pop();
    }

    return result;
}

int main() {
    string exp;
    cin >> exp;
    cout << infixToPostfix(exp) << endl;
    return 0;
}
