/*
Implement the following operations of a stack using queues.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
empty() -- Return whether the stack is empty.
Notes:
You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).
 */

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        que.push(x);
        for (auto i = 0; i != que.size() - 1; ++i) {
            que.push(que.front());
            que.pop();
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int res = que.front();
        que.pop();
        return res;
    }

    /** Get the top element. */
    int top() {
        return que.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return que.empty();
    }

private:
    queue<int> que;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */