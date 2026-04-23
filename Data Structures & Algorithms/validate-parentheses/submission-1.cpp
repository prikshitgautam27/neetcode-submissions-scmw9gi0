class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto it : s) {
            // Push opening brackets onto the stack
            if(it == '(' || it == '{' || it == '[') {
                st.push(it);
            } 
            else {
                // If we see a closing bracket but stack is empty, it's invalid
                if(st.empty()) return false;
                
                char topChar = st.top();
                st.pop();
                
                // Check if current closing bracket matches the popped opening bracket
                if((it == ')' && topChar == '(') || 
                   (it == '}' && topChar == '{') || 
                   (it == ']' && topChar == '[')) {
                    continue;
                } else {
                    return false;
                }
            }
        }
        // Valid only if all opening brackets were matched and popped
        return st.empty();
    }
};
