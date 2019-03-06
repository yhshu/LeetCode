class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int a, b;
        std::stack<int> stack;
        for(string &str : tokens) {
            if(str == "+") {
                topTwo(stack, a, b);
                stack.push(b + a);
            }
            else if (str == "/") {
                topTwo(stack, a, b);
                stack.push(b / a);    // it is not a / b
            }
            else if (str == "*") {
                topTwo(stack, a, b);
                stack.push(a * b);
            }
            else if (str == "-") {
                topTwo(stack, a, b);
                stack.push(b - a);    // it is not a - b
            }
            else
                stack.push(stoi(str));
        }
        return stack.top();
    }
    
    void topTwo(stack<int> &stack, int &a, int &b) {
        if(!stack.empty()) {
            a = stack.top();
            stack.pop();
            b = stack.top();
            stack.pop();
        }
    }
};
