class Solution {
public:
    bool isValid(string s) {

        unordered_map<char, int> mp = {
            {'{', -1},
            {'(', -2},
            {'[', -3},
            {'}', 1},
            {')', 2},
            {']', 3}
        };

        stack<char> st;

        for (char ch : s) {

            // Opening brackets are represented by negative values.
            // Push them onto the stack and wait for their matching
            // closing bracket to appear later.
            if (mp[ch] < 0) {
                st.push(ch);
            }
            else {

                // A closing bracket appeared, but there is no opening
                // bracket available to match it.
                //
                // Example:
                // s = ")"
                // s = "}"
                // s = "())"
                //
                // Calling st.top() on an empty stack would also cause
                // a runtime error, so we must check this first.
                if (st.empty())
                    return false;

                // Matching pairs have values that sum to 0:
                // '(' = -2, ')' = 2
                // '[' = -3, ']' = 3
                // '{' = -1, '}' = 1
                //
                // If the sum is not 0, the brackets do not match.
                if (mp[st.top()] + mp[ch] != 0)
                    return false;

                // Valid matching pair found, remove the opening bracket.
                st.pop();
            }
        }

        // If the stack is empty, every opening bracket found
        // its matching closing bracket.
        // Otherwise, some opening brackets were never closed.
        return st.empty();
    }
};