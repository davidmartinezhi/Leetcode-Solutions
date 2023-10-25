#include <iostream>
#include <stack>

using namespace std;

class MinStack {
private:
    stack<int> mainStack;  // Main stack to hold all elements
    stack<int> minStack;   // Stack to keep track of minimum elements

public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    // Push element onto mainStack
    // Also update minStack if needed
    void push(int val) {
        mainStack.push(val);
        
        // If minStack is empty or the new element is <= current minimum,
        // push it onto minStack
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }
    
    // Pop element from mainStack
    // Also update minStack if needed
    void pop() {
        // If the element being popped is the current minimum,
        // pop it from minStack as well
        if (mainStack.top() == minStack.top()) {
            minStack.pop();
        }
        mainStack.pop();
    }
    
    // Get the top element from mainStack
    int top() {
        return mainStack.top();
    }
    
    // Get the current minimum element from minStack
    int getMin() {
        return minStack.top();
    }
};
