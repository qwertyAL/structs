#include <bits/stdc++.h>

using namespace std;

namespace my_struct {

template <class T>
class stack {
private:

    struct Node {
        T val;
        Node *p;
    };
    Node *top = nullptr;

public:

    void push(T val) {
        Node *pv = new Node;
        pv->val = val;
        pv->p = top;
        top = pv;
    }

    bool isEmpty() {return !top;}

    T pop() {
        T temp;
        if(isEmpty()) {
            return NULL;
        }
        temp = top->val;
        Node *pv = top;
        top = top->p;
        delete pv;
        return temp;
    }

};

}

void solve() {
    my_struct::stack<int> new_stack;
    cout << "is null " << new_stack.isEmpty() << endl;
    new_stack.push(1);
    cout << "is null " << new_stack.isEmpty() << endl;
    new_stack.push(2);
    cout << "is null " << new_stack.isEmpty() << endl;
    cout << "last " << new_stack.pop() << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
