#include <iostream>
#include <vector>
#include <stack>
#include <myutils.h>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> stk, minstk;

    MinStack() {
    }

    void push(int x) {
        stk.push(x);
        if (minstk.empty() or minstk.top() >= x)
            minstk.push(x);
    }

    void pop() {
        int top = stk.top();
        if (top == minstk.top())
            minstk.pop();
        stk.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return minstk.top();
    }
};

int main() {
//  Your MinStack object will be instantiated and called as such:
    MinStack *obj = new MinStack();
    obj->push(3);
    obj->pop();
    int param_3 = obj->top();
    int param_4 = obj->getMin();
    delete obj;
    return 0;
}
