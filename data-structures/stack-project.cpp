#include <iostream>
#include <string>
using namespace std;

class Stack {
    private:
        int top;
        int MAX_SIZE;
        string* infixArr;
        string* postfixArr;
        string* prefixArr;
    public:
        Stack(int size) : top(-1),MAX_SIZE(size) {
            infixArr = new string[MAX_SIZE];
            postfixArr = new string[MAX_SIZE];
            prefixArr = new string[MAX_SIZE];
        }
        ~Stack() {
            delete[] infixArr;
            delete[] postfixArr;
            delete[] prefixArr;
        }
        bool isEmpty() {
            return top == -1;
        }
        bool isFull() {
            return top == MAX_SIZE - 1;
        }
        void pop() {
            if (!isEmpty()) {
                top--;
            }
        }
        void push(string in, string post, string pre) {
            if (!isFull()) {
                infixArr[++top] = in;
                postfixArr[top] = post;
                prefixArr[top] = pre;
            }
        }
        int size() { return top + 1; }
        string peekInfix() { return infixArr[top]; }
        string peekPostfix() { return postfixArr[top]; }
        string peekPrefix() { return prefixArr[top]; }
};

bool Operator(Stack& st, char op) {
    if (st.size() < 2) return false;
    string yInfix = st.peekInfix(), yPostfix = st.peekPostfix(), yPrefix = st.peekPrefix();
    st.pop();
    string xInfix = st.peekInfix(), xPostfix = st.peekPostfix(), xPrefix = st.peekPrefix();
    st.pop();
    string newInfix = "(" + xInfix + op + yInfix + ")";
    string newPostfix = xPostfix + yPostfix + op;
    string newPrefix = op + xPrefix + yPrefix;
    st.push(newInfix, newPostfix, newPrefix);
    return true;
}

int main() {
    Stack st(100);
    string command;
    
    while (cin >> command) {
        if (command == "PUSH") {
            string a; cin >> a;
            st.push(a, a, a);
        }
        else if (command == "ADD") {
            if (!Operator(st, '+')) {
                cout << "STACK UNDERFLOW" << endl;
                return 0;
            }
        }
        else if (command == "SUB") {
            if (!Operator(st, '-')) {
                cout << "STACK UNDERFLOW" << endl;
                return 0;
            }
        }
        else if (command == "MUL") {
            if (!Operator(st, '*')) {
                cout << "STACK UNDERFLOW" << endl;
                return 0;
            }
        }
        else if (command == "DIV") {
            if (!Operator(st, '/')) {
                cout << "STACK UNDERFLOW" << endl;
                return 0;
            }
        }
        else if (command == "SWAP") {
            if (st.size() < 2) {
                cout << "STACK UNDERFLOW" << endl;
                return 0;
            }
            string aInfix = st.peekInfix(), aPostfix = st.peekPostfix(), aPrefix = st.peekPrefix();
            st.pop();
            string bInfix = st.peekInfix(), bPostfix = st.peekPostfix(), bPrefix = st.peekPrefix();
            st.pop();
            st.push(aInfix, aPostfix, aPrefix);
            st.push(bInfix, bPostfix, bPrefix);
        }
        else if (command == "DUP") {
            if (st.isEmpty()) {
                cout << "STACK UNDERFLOW" << endl;
                return 0;
            }
            string aInfix = st.peekInfix(), aPostfix = st.peekPostfix(), aPrefix = st.peekPrefix();
            st.push(aInfix, aPostfix, aPrefix);
        }
        else if (command == "END") {
            if (st.size() != 1) {
                cout << "INVALID EXPRESSION" << endl;
                return 0;
            }
            cout << "Infix: " << st.peekInfix() << endl;
            cout << "Postfix: " << st.peekPostfix() << endl;
            cout << "Prefix: " << st.peekPrefix() << endl;
            return 0;
        }
    }
    return 0;
}