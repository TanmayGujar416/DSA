#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start
class MinStack {
public:
    stack<long long> st;
    long long mini;
    MinStack() {
        mini = INT_MAX;
    }

    void push(int value) {
        if(st.empty()){
            st.push(value);
            mini = value;
        } else if(value >= mini){
            st.push(value);
        } else{
            long long newValue = 2LL*value - mini;
            st.push(newValue);
            mini = value;
        }
    }

    void pop() {
        if(st.top() >= mini) st.pop();
        else{
            mini = 2LL*mini - st.top();
            st.pop();
        }
        if (st.empty())
            mini = INT_MAX;
    }

    int top() {
        if(st.top() >= mini) return st.top();
        else return mini;
    }

    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

