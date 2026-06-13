class MinStack {
public:
    stack<int> mainStack;  // Stores all elements
    stack<int> minStack;   // Stores current minimums

    MinStack() {
    }
    
    void push(int val) {

        // Always push into the main stack.
        mainStack.push(val);

        // Push into minStack if:
        // 1. minStack is empty (first element being inserted), OR
        // 2. val is smaller than or equal to the current minimum.
        //
        // We use <= instead of < to handle duplicate minimums.
        //
        // Example:
        // push(2), push(2)
        // minStack = [2, 2]
        //
        // After one pop(), there is still another 2 remaining
        // as the minimum.
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }
    
    void pop() {

        // If the element being removed from mainStack
        // is also the current minimum, remove it from
        // minStack as well.
        //
        // Example:
        // mainStack = [5, 3]
        // minStack  = [5, 3]
        //
        // Popping 3 should remove it from both stacks.
        if (mainStack.top() == minStack.top()) {
            minStack.pop();
        }

        // Remove the top element from the main stack.
        mainStack.pop();
    }
    
    int top() {

        // Return the most recently added element.
        return mainStack.top();
    }
    
    int getMin() {

        // The top of minStack always stores
        // the current minimum element.
        return minStack.top();
    }
};